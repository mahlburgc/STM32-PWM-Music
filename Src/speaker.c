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
#include "stm32f0xx_ll_tim.h"

typedef struct
{
    TIM_TypeDef* timer;
    uint32_t channel;
} Speaker_t;

Speaker_t speaker[3] =
{
    { TIM14, LL_TIM_CHANNEL_CH1 }, /* PA4 */
    { TIM2, LL_TIM_CHANNEL_CH2 }, /* PB3 */
    { TIM3, LL_TIM_CHANNEL_CH1 }, /* PB4 */
};

/* tone length */
uint16_t quarter = 480; /* ms */
uint16_t full = quarter * 4;
uint16_t half = quarter * 2;
uint16_t eighth = quarter / 2;
uint16_t sixteenth = quarter / 4;
uint16_t thirtysecond = quarter / 8;

static uint16_t staccatoLength = 0;

static void SPEAKER_SetFrequency(SpeakerNr_t nr, uint32_t frequency);

/**
 * @brief Configure PWM output to given frequency by setting ARR Register.
 *        f_pwm = (f_sys)/((arr + 1) * (psc + 1)
 */
static void SPEAKER_SetFrequency(SpeakerNr_t nr, uint32_t frequency)
{
    uint64_t f_sys = (uint64_t)SystemCoreClock * 100; /* in dHz */
    uint32_t f_pwm = frequency;
    uint32_t psc = LL_TIM_GetPrescaler(speaker[nr].timer); /* prescaler */

#ifdef DEBUG /* to avoid "unused warning" in release build */
    uint32_t arr_max = 0xFFFF; /* only 16bit values are allowed */
    uint32_t arr_min = 0x0000; /* only 16bit values are allowed */
    uint32_t f_pwm_max = (f_sys / ((arr_min + 1) * (psc + 1)));
    uint32_t f_pwm_min = (f_sys / ((arr_max + 1) * (psc + 1)));

    assert_param((frequency >= f_pwm_min) && (frequency <= f_pwm_max));
#endif

    uint32_t autoReload = (f_sys / (f_pwm * (psc + 1))) - 1;
    uint32_t pulseWidth = ((autoReload + 1) / 2) - 1;

    LL_TIM_SetAutoReload(speaker[nr].timer, autoReload);

    if (speaker[nr].channel == LL_TIM_CHANNEL_CH1)
    {
      LL_TIM_OC_SetCompareCH1(speaker[nr].timer, pulseWidth);
    }
    else if (speaker[nr].channel == LL_TIM_CHANNEL_CH2)
    {
      LL_TIM_OC_SetCompareCH2(speaker[nr].timer, pulseWidth);
    }
    else if (speaker[nr].channel == LL_TIM_CHANNEL_CH3)
    {
      LL_TIM_OC_SetCompareCH3(speaker[nr].timer, pulseWidth);
    }
    else if (speaker[nr].channel == LL_TIM_CHANNEL_CH4)
    {
      LL_TIM_OC_SetCompareCH4(speaker[nr].timer, pulseWidth);
    }
}

/**
 * @brief TODO
 */
void SPEAKER_SetToneLength(uint16_t quarterLengthMs)
{
    assert_param(quarterLengthMs % 8 == 0);

    full = quarterLengthMs * 4;
    half = quarterLengthMs * 2;
    quarter = quarterLengthMs;
    eighth = quarterLengthMs / 2;
    sixteenth = quarterLengthMs / 4;
    thirtysecond = quarterLengthMs / 8;
}

/**
 * @brief TODO
 */
void SPEAKER_SetStaccato(uint16_t newStaccatoLength)
{
    staccatoLength = newStaccatoLength;
}

/**
 * @brief Plays a note with a given frequency and duration.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_Play(SpeakerNr_t nr, uint32_t frequency, uint32_t duration)
{
    LL_TIM_CC_DisableChannel(speaker[nr].timer, speaker[nr].channel);
    LL_TIM_DisableCounter(speaker[nr].timer);

    if (frequency > 0)
    {
        LL_TIM_SetCounter(speaker[nr].timer, 0);
        SPEAKER_SetFrequency(nr, frequency);
        LL_TIM_EnableCounter(speaker[nr].timer);
        LL_TIM_CC_EnableChannel(speaker[nr].timer, speaker[nr].channel);

        osDelay(duration);

        LL_TIM_CC_DisableChannel(speaker[nr].timer, speaker[nr].channel);
        LL_TIM_DisableCounter(speaker[nr].timer);
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
void SPEAKER_PlayStaccato(SpeakerNr_t nr, uint32_t frequency, uint32_t duration)
{
    assert_param(duration >= staccatoLength);

    SPEAKER_Play(nr, frequency, duration - staccatoLength);
    SPEAKER_Pause(nr, staccatoLength);
}

/**
 * @brief Stops audio output of given speaker nr.
 */
void SPEAKER_Stop(SpeakerNr_t nr)
{
    LL_TIM_CC_DisableChannel(speaker[nr].timer, speaker[nr].channel);
    LL_TIM_DisableCounter(speaker[nr].timer);
}


/**
 * @brief Pause for given duration.
 */
void SPEAKER_Pause(SpeakerNr_t nr, uint32_t duration)
{
    LL_TIM_CC_DisableChannel(speaker[nr].timer, speaker[nr].channel);
    LL_TIM_DisableCounter(speaker[nr].timer);
    osDelay(duration);
}


/**
 * @brief Plays a note with a given frequency and duration.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_PlayCont(SpeakerNr_t nr, uint32_t frequency, uint32_t duration)
{
    LL_TIM_CC_DisableChannel(speaker[nr].timer, speaker[nr].channel);
    LL_TIM_DisableCounter(speaker[nr].timer);

    if (frequency > 0)
    {
        LL_TIM_SetCounter(speaker[nr].timer, 0);
        SPEAKER_SetFrequency(nr, frequency);
        LL_TIM_EnableCounter(speaker[nr].timer);
        LL_TIM_CC_EnableChannel(speaker[nr].timer, speaker[nr].channel);
    }
}

/**
 * @brief Plays two notes with a given frequency and duration.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_PlayTwo(SpeakerNr_t sp1, uint32_t freq1, SpeakerNr_t sp2, uint32_t freq2, uint32_t duration)
{
    assert_param(duration >= staccatoLength);

    LL_TIM_CC_DisableChannel(speaker[sp1].timer, speaker[sp1].channel);
    LL_TIM_DisableCounter(speaker[sp1].timer);

    LL_TIM_CC_DisableChannel(speaker[sp2].timer, speaker[sp2].channel);
    LL_TIM_DisableCounter(speaker[sp2].timer);

    if ((freq1 > 0) && (freq2 > 0))
    {
        LL_TIM_SetCounter(speaker[sp1].timer, 0);
        SPEAKER_SetFrequency(sp1, freq1);

        LL_TIM_SetCounter(speaker[sp2].timer, 0);
        SPEAKER_SetFrequency(sp2, freq2);

        LL_TIM_EnableCounter(speaker[sp1].timer);
        LL_TIM_CC_EnableChannel(speaker[sp1].timer, speaker[sp1].channel);

        LL_TIM_EnableCounter(speaker[sp2].timer);
        LL_TIM_CC_EnableChannel(speaker[sp2].timer, speaker[sp2].channel);

        osDelay(duration - staccatoLength);

        LL_TIM_CC_DisableChannel(speaker[sp1].timer, speaker[sp1].channel);
        LL_TIM_DisableCounter(speaker[sp1].timer);

        LL_TIM_CC_DisableChannel(speaker[sp2].timer, speaker[sp2].channel);
        LL_TIM_DisableCounter(speaker[sp2].timer);

        osDelay(staccatoLength);
    }
    else /* pause */
    {
        osDelay(duration);
    }
}
