/********************************************************************************
 * @file           : speaker.c
 * @author         : Christian Mahlburg
 * @date           : 16.11.2022
 * @brief          : Module to control up to 3 speaker with pwm.
 *
 ********************************************************************************
 * MIT License
 *
 * Copyright (c) 2022 CMA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ********************************************************************************/

#include "speaker.h"
#include "main.h"
#include "cmsis_os.h"

#define staccatoLenPercent 10 /* staccato note duration reduced by x percent */

static void SPEAKER_SetFrequency(Speaker_t speaker, uint32_t frequency);

/**
 * @brief Configure PWM output to given frequency by setting ARR Register.
 *        f_pwm = (f_sys)/((arr + 1) * (psc + 1)
 */
static void SPEAKER_SetFrequency(Speaker_t speaker, uint32_t frequency)
{
    uint64_t f_sys = (uint64_t)SystemCoreClock * 100; /* in dHz */
    uint32_t f_pwm = frequency;
    uint32_t psc = LL_TIM_GetPrescaler(speaker.timer); /* prescaler */

#ifdef DEBUG /* to avoid "unused warning" in release build */
    uint32_t arr_max = 0xFFFF; /* only 16bit values are allowed */
    uint32_t arr_min = 0x0000; /* only 16bit values are allowed */
    uint32_t f_pwm_max = (f_sys / ((arr_min + 1) * (psc + 1)));
    uint32_t f_pwm_min = (f_sys / ((arr_max + 1) * (psc + 1)));

    assert_param((frequency >= f_pwm_min) && (frequency <= f_pwm_max));
#endif

    uint32_t autoReload = (f_sys / (f_pwm * (psc + 1))) - 1;
    uint32_t pulseWidth = ((autoReload + 1) / 2) - 1;

    LL_TIM_SetAutoReload(speaker.timer, autoReload);

    if (speaker.channel == LL_TIM_CHANNEL_CH1)
    {
      LL_TIM_OC_SetCompareCH1(speaker.timer, pulseWidth);
    }
    else if (speaker.channel == LL_TIM_CHANNEL_CH2)
    {
      LL_TIM_OC_SetCompareCH2(speaker.timer, pulseWidth);
    }
    else if (speaker.channel == LL_TIM_CHANNEL_CH3)
    {
      LL_TIM_OC_SetCompareCH3(speaker.timer, pulseWidth);
    }
    else if (speaker.channel == LL_TIM_CHANNEL_CH4)
    {
      LL_TIM_OC_SetCompareCH4(speaker.timer, pulseWidth);
    }
}

/**
 * @brief Plays a note with a given frequency and duration.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_Play(Speaker_t speaker, uint32_t frequency, uint32_t duration)
{
    LL_TIM_CC_DisableChannel(speaker.timer, speaker.channel);
    LL_TIM_DisableCounter(speaker.timer);

    if (frequency > 0)
    {
        LL_TIM_SetCounter(speaker.timer, 0);
        SPEAKER_SetFrequency(speaker, frequency);
        LL_TIM_EnableCounter(speaker.timer);
        LL_TIM_CC_EnableChannel(speaker.timer, speaker.channel);

        osDelay(duration);

        LL_TIM_CC_DisableChannel(speaker.timer, speaker.channel);
        LL_TIM_DisableCounter(speaker.timer);
    }
    else /* pause */
    {
        osDelay(duration);
    }
}

/**
 * @brief Plays a note with a given frequency and duration.
 *        A staccato is added here.
 */
void SPEAKER_PlayStac(Speaker_t speaker, uint32_t frequency, uint32_t duration)
{
    uint32_t staccatoLength = (duration * staccatoLenPercent) / 100;

    SPEAKER_Play(speaker, frequency, duration - staccatoLength);
    SPEAKER_Pause(speaker, staccatoLength);
}

/**
 * @brief Stops audio output of given speaker.
 */
void SPEAKER_Stop(Speaker_t speaker)
{
    LL_TIM_CC_DisableChannel(speaker.timer, speaker.channel);
    LL_TIM_DisableCounter(speaker.timer);
}


/**
 * @brief Pause for given duration.
 */
void SPEAKER_Pause(Speaker_t speaker, uint32_t duration)
{
    LL_TIM_CC_DisableChannel(speaker.timer, speaker.channel);
    LL_TIM_DisableCounter(speaker.timer);
    osDelay(duration);
}

/**
 * @brief Plays a note with a given frequency and duration.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_PlayCont(Speaker_t speaker, uint32_t frequency)
{
    LL_TIM_CC_DisableChannel(speaker.timer, speaker.channel);
    LL_TIM_DisableCounter(speaker.timer);

    if (frequency > 0)
    {
        LL_TIM_SetCounter(speaker.timer, 0);
        SPEAKER_SetFrequency(speaker, frequency);
        LL_TIM_EnableCounter(speaker.timer);
        LL_TIM_CC_EnableChannel(speaker.timer, speaker.channel);
    }
}

/**
 * @brief Plays two notes with a given frequency and duration with staccato.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_PlayTwoStac(Speaker_t speaker1, uint32_t freq1, Speaker_t speaker2, uint32_t freq2, uint32_t duration)
{
    uint32_t staccatoLength = (duration * staccatoLenPercent) / 100;

    SPEAKER_PlayCont(speaker1, freq1);
    SPEAKER_PlayCont(speaker2, freq2);

    osDelay(duration - staccatoLength);

    SPEAKER_Stop(speaker1);
    SPEAKER_Stop(speaker2);

    osDelay(staccatoLength);
}

/**
 * @brief Plays two notes with a given frequency and duration with staccato.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_PlayTwo(Speaker_t speaker1, uint32_t freq1, Speaker_t speaker2, uint32_t freq2, uint32_t duration)
{
    SPEAKER_PlayCont(speaker1, freq1);
    SPEAKER_PlayCont(speaker2, freq2);

    osDelay(duration);

    SPEAKER_Stop(speaker1);
    SPEAKER_Stop(speaker2);
}
