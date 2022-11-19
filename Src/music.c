/********************************************************************************
 * @file           : music.c
 * @author         : Christian Mahlburg
 * @date           : 16.11.2022
 * @brief          : Module with different songs to play with pwm sound.
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

#include "music.h"
#include "speaker.h"

#define defaultBPM 120 /* initial beats per minute */
#define defaultQuarter ((60 * 1000) / defaultBPM)

/* pwm speaker */
static Speaker_t left = { TIM14, LL_TIM_CHANNEL_CH1 }; /* PA4 */
static Speaker_t middle = { TIM2, LL_TIM_CHANNEL_CH2 }; /* PB3 */
static Speaker_t right = { TIM3, LL_TIM_CHANNEL_CH1 }; /* PB4 */

/* tone length in ms*/
static uint32_t quarter = defaultQuarter;
static uint32_t full = defaultQuarter * 4;
static uint32_t half = defaultQuarter * 2;
static uint32_t eighth = defaultQuarter / 2;
static uint32_t sixteenth = defaultQuarter / 4;
static uint32_t thirtysecond = defaultQuarter / 8;

static void MUSIC_SetBPM(uint32_t quarterLengthMs);

/**
 * @brief Calculate new tone length in ms for given bpm.
 */
static void MUSIC_SetBPM(uint32_t bpm)
{
    quarter = (60 * 1000) / bpm;
    full = quarter * 4;
    half = quarter * 2;
    eighth = quarter / 2;
    sixteenth = quarter / 4;
    thirtysecond = quarter / 8;
}

/**
 * @brief Play ACDC - Thunderstruck
 */
void MUSIC_Play_ACDC(void)
{
  MUSIC_SetBPM(134);

    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(left, e4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, g4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(left, f4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, gis4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(left, e4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, g4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(left, f4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, gis4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 2; i++)
    {
       SPEAKER_Play(left, c5, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, ais4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, a4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, ais4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, a4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, g4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, a4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       SPEAKER_Play(left, f4, sixteenth);
       SPEAKER_Play(left, c4, sixteenth);
       for (uint8_t i = 0; i < 4; i++)
       {
           SPEAKER_Play(left, g4, sixteenth);
           SPEAKER_Play(left, c4, sixteenth);
           SPEAKER_Play(left, e4, sixteenth);
           SPEAKER_Play(left, c4, sixteenth);
       }
    }
}

/**
 * @brief Play Super Mario Bros. Theme Song
 */
void MUSIC_Play_SuperMario(void)
{
    MUSIC_SetBPM(180);

    SPEAKER_PlayStac(left, fret_E12, eighth);
    SPEAKER_PlayStac(left, fret_E12, eighth);
    SPEAKER_Pause(left, eighth);
    SPEAKER_PlayStac(left, fret_E12, eighth);
    SPEAKER_Pause(left, eighth);
    SPEAKER_PlayStac(left, fret_E8, eighth);
    SPEAKER_PlayStac(left, fret_E12, quarter);
    SPEAKER_Play(left, fret_E15, quarter);
    SPEAKER_Pause(left, quarter);
    SPEAKER_Play(left, fret_H8, quarter);
    SPEAKER_Pause(left, quarter);
}

/**
 * @brief Play Tetris Right Piano Hand
 */
void MUSIC_Play_Tetris_RightHand(void)
{
    MUSIC_SetBPM(150);

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 1 */
        SPEAKER_Play(right, e5, quarter);
        SPEAKER_Play(right, h4, eighth);
        SPEAKER_Play(right, c5, eighth);
        SPEAKER_Play(right, d5, eighth);
        SPEAKER_Play(right, e5, sixteenth);
        SPEAKER_Play(right, d5, sixteenth);
        SPEAKER_Play(right, c5, eighth);
        SPEAKER_Play(right, h4, eighth);

        /* 2 */
        SPEAKER_Play(right, a4, quarter);
        SPEAKER_Play(right, a4, eighth);
        SPEAKER_Play(right, c5, eighth);
        SPEAKER_Play(right, e5, quarter);
        SPEAKER_Play(right, d5, eighth);
        SPEAKER_Play(right, c5, eighth);

        /* 3 */
        SPEAKER_Play(right, h4, quarter);
        SPEAKER_Play(right, h4, eighth);
        SPEAKER_Play(right, c5, eighth);
        SPEAKER_Play(right, d5, quarter);
        SPEAKER_Play(right, e5, quarter);

        /* 4 */
        SPEAKER_Play(right, c5, quarter);
        SPEAKER_Play(right, a4, quarter);
        SPEAKER_Play(right, a4, half);

        /* 5 */
        SPEAKER_Play(right, 0, eighth);
        SPEAKER_Play(right, d5, quarter);
        SPEAKER_Play(right, f5, eighth);
        SPEAKER_Play(right, a5, quarter);
        SPEAKER_Play(right, g5, eighth);
        SPEAKER_Play(right, f5, eighth);

        /* 6 */
        SPEAKER_Play(right, 0, eighth);
        SPEAKER_Play(right, e5, quarter);
        SPEAKER_Play(right, c5, eighth);
        SPEAKER_Play(right, e5, quarter);
        SPEAKER_Play(right, d5, eighth);
        SPEAKER_Play(right, c5, eighth);

        /* 7 */
        SPEAKER_Play(right, h4, quarter);
        SPEAKER_Play(right, h4, eighth);
        SPEAKER_Play(right, c5, eighth);
        SPEAKER_Play(right, d5, quarter);
        SPEAKER_Play(right, e5, quarter);

        /* 8 */
        SPEAKER_Play(right, c5, quarter);
        SPEAKER_Play(right, a4, quarter);
        SPEAKER_Play(right, a4, half);
    }

    /* 17 */
    SPEAKER_PlayTwo(right, e5, middle, c5, half);
    SPEAKER_PlayTwo(right, c5, middle, a4, half);

    /* 18 */
    SPEAKER_PlayTwo(right, d5, middle, h4, half);
    SPEAKER_PlayTwo(right, h4, middle, gis4, half);

    /* 19 */
    SPEAKER_PlayTwo(right, c5, middle, a4, half);
    SPEAKER_PlayTwo(right, a4, middle, e4, half);

    /* 20 */
    SPEAKER_PlayTwo(right, gis4, middle, e4, half);
    SPEAKER_PlayTwo(right, h4, middle, gis4, half);

    /* 21 */
    SPEAKER_PlayTwo(right, e5, middle, c5, half);
    SPEAKER_PlayTwo(right, c5, middle, a4, half);

    /* 22 */
    SPEAKER_PlayTwo(right, d5, middle, h4, half);
    SPEAKER_PlayTwo(right, h4, middle, gis4, half);

    /* 23 */
    SPEAKER_PlayTwo(right, c5, middle, a4, quarter);
    SPEAKER_PlayTwo(right, e5, middle, c5, quarter);
    SPEAKER_PlayTwo(right, a5, middle, e5, quarter);
    SPEAKER_PlayTwo(right, a5, middle, e5, quarter);

    /* 24*/
    SPEAKER_PlayTwo(right, gis5, middle, e5, full);

    /*********** third part ********/

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 25 */
        SPEAKER_PlayTwo(right, e5, middle, h4, quarter);

        SPEAKER_PlayTwo(right, h4, middle, gis4, eighth);
        SPEAKER_PlayTwo(right, c5, middle, a4, eighth);

        SPEAKER_PlayTwo(right, d5, middle, h4, eighth);
        SPEAKER_Play(right, e5, sixteenth);
        SPEAKER_Play(right, d5, sixteenth);

        SPEAKER_PlayTwo(right, c5, middle, a4, eighth);
        SPEAKER_PlayTwo(right, h4, middle, gis4, eighth);

        /* 26 */
        SPEAKER_PlayTwo(right, a4, middle, e4, quarter);

        SPEAKER_PlayTwo(right, a4, middle, e4, eighth);
        SPEAKER_PlayTwo(right, c5, middle, a5, eighth);

        SPEAKER_PlayTwo(right, e5, middle, c5, quarter);

        SPEAKER_PlayTwo(right, d5, middle, h4, eighth);
        SPEAKER_PlayTwo(right, c5, middle, a4, eighth);

        /* 27 */
        SPEAKER_PlayTwo(right, h4, middle, gis4, eighth);
        SPEAKER_PlayTwo(right, e4, middle, 0, eighth);

        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, c5, eighth);

        SPEAKER_PlayTwo(right, d5, middle, h4, quarter);

        SPEAKER_PlayTwo(right, e5, middle, c4, quarter);

        /* 28 */
        SPEAKER_PlayTwo(right, c5, middle, a4, quarter);
        SPEAKER_PlayTwo(right, a4, middle, e4, quarter);

        SPEAKER_PlayTwo(right, a4, middle, e4, half);

        /* 29 */
        SPEAKER_Pause(right, eighth);
        SPEAKER_PlayTwo(right, d5, middle, f4, quarter);
        SPEAKER_PlayTwo(right, f5, middle, a4, eighth);

        SPEAKER_PlayTwo(right, a5, middle, c5, quarter);
        SPEAKER_PlayTwo(right, g5, middle, h4, eighth);
        SPEAKER_PlayTwo(right, f5, middle, a4, eighth);

        /* 30 */
        SPEAKER_Pause(right, eighth);
        SPEAKER_PlayTwo(right, e5, middle, g4, quarter);
        SPEAKER_PlayTwo(right, c5, middle, e5, eighth); /* e4 */

        SPEAKER_PlayTwo(right, e5, middle, g4, quarter);
        SPEAKER_PlayTwo(right, d5, middle, f4, eighth);
        SPEAKER_PlayTwo(right, c5, middle, e4, eighth);

        /* 31 */
        SPEAKER_PlayTwo(right, h4, middle, gis4, eighth);
        SPEAKER_PlayTwo(right, e4, middle, 0, eighth);

        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, c5, eighth);

        SPEAKER_PlayTwo(right, d5, middle, h4, quarter);

        SPEAKER_PlayTwo(right, e5, middle, c4, quarter);

        /* 32 */
        SPEAKER_PlayTwo(right, c5, middle, a4, quarter);
        SPEAKER_PlayTwo(right, a4, middle, e4, quarter);

        SPEAKER_PlayTwo(right, a4, middle, e4, half);
    }

    /* end */
}


/**
 * @brief Play Tetris Left Piano Hand
 */
void MUSIC_Play_Tetris_LeftHand(void)
{
    MUSIC_SetBPM(150);

    /*********** first part ********/
    /* 1 */
    SPEAKER_Pause(left, full);

    /* 2 */
    SPEAKER_Pause(left, full);

    /* 3 */
    SPEAKER_Pause(left, full);

    /* 4 */
    SPEAKER_Pause(left, full);

    /* 5 */
    SPEAKER_Pause(left, full);

    /* 6 */
    SPEAKER_Pause(left, full);

    /* 7 */
    SPEAKER_Pause(left, full);

    /* 8 */
    SPEAKER_Pause(left, full);

    /* 9 */
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 10 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);

    /* 11 */
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, gis3, eighth);
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, gis3, eighth);
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 12 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, c2, eighth);
    SPEAKER_Play(left, d3, eighth);

    /* 13 */
    SPEAKER_Play(left, d2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, d2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, d2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, d2, eighth);
    SPEAKER_Play(left, d3, eighth);

    /* 14 */
    SPEAKER_Play(left, c2, eighth);
    SPEAKER_Play(left, c3, eighth);
    SPEAKER_Play(left, c2, eighth);
    SPEAKER_Play(left, c3, eighth);
    SPEAKER_Play(left, c2, eighth);
    SPEAKER_Play(left, c3, eighth);
    SPEAKER_Play(left, c2, eighth);
    SPEAKER_Play(left, c3, eighth);

    /* 15 */
    SPEAKER_Play(left, g2, eighth);
    SPEAKER_Play(left, g3, eighth);
    SPEAKER_Play(left, g2, eighth);
    SPEAKER_Play(left, g3, eighth);
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 16 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, a3, eighth);
    SPEAKER_Play(left, a2, quarter);

    /*********** second part ********/

    /* 17 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 18 */
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);

    /* 19 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 20 */
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 21 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 22 */
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);
    SPEAKER_Play(left, h2, eighth);
    SPEAKER_Play(left, d3, eighth);

    /* 23 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Play(left, e3, eighth);

    /* 24 */
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_Play(left, e3, eighth);
    SPEAKER_Play(left, gis2, quarter - 10);
    SPEAKER_Pause(left, 10);
    SPEAKER_Play(left, gis2, quarter - 10);
    SPEAKER_Pause(left, 10);

    /*********** third part ********/

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 25 */
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);

        /* 26 */
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);

        /* 27 */
        SPEAKER_Play(left, gis2, eighth);
        SPEAKER_Play(left, gis3, eighth);
        SPEAKER_Play(left, gis2, eighth);
        SPEAKER_Play(left, gis3, eighth);
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);

        /* 28 */
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, h2, eighth);
        SPEAKER_Play(left, c2, eighth);
        SPEAKER_Play(left, d3, eighth);

        /* 29 */
        SPEAKER_Play(left, d2, eighth);
        SPEAKER_Play(left, d3, eighth);
        SPEAKER_Play(left, d2, eighth);
        SPEAKER_Play(left, d3, eighth);
        SPEAKER_Play(left, d2, eighth);
        SPEAKER_Play(left, d3, eighth);
        SPEAKER_Play(left, d2, eighth);
        SPEAKER_Play(left, d3, eighth);

        /* 30 */
        SPEAKER_Play(left, c2, eighth);
        SPEAKER_Play(left, c3, eighth);
        SPEAKER_Play(left, c2, eighth);
        SPEAKER_Play(left, c3, eighth);
        SPEAKER_Play(left, c2, eighth);
        SPEAKER_Play(left, c3, eighth);
        SPEAKER_Play(left, c2, eighth);
        SPEAKER_Play(left, c3, eighth);

        /* 31 */
        SPEAKER_Play(left, gis2, eighth);
        SPEAKER_Play(left, gis3, eighth);
        SPEAKER_Play(left, gis2, eighth);
        SPEAKER_Play(left, gis3, eighth);
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);
        SPEAKER_Play(left, e2, eighth);
        SPEAKER_Play(left, e3, eighth);

        /* 32 */
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, eighth);
        SPEAKER_Play(left, a3, eighth);
        SPEAKER_Play(left, a2, quarter);
    }
    /* end */
}

/**
 * @brief Play Tetris Ragtime Right Piano Hand
 */
void MUSIC_Play_TetrisRagtime_RightHand(void)
{
    MUSIC_SetBPM(125);

#if 1
    /* 1 */
    SPEAKER_Pause(right, full);

    /* 2 */
    SPEAKER_Pause(right, quarter);
    SPEAKER_PlayStac(right, h4, eighth);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, h4, eighth);

    /* 3 */
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_PlayStac(right, a4, eighth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStac(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStac(right, d5, eighth);
    SPEAKER_PlayStac(right, c5, eighth);

    /* 4 */
    SPEAKER_PlayStac(right, h4, quarter + eighth);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_PlayStac(right, e5, quarter);

    /* 5 */
    SPEAKER_PlayStac(right, c5, quarter);
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_PlayStac(right, a4, half);

    /* 6 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_PlayStac(right, f5, eighth);
    SPEAKER_PlayStac(right, a5, quarter);
    SPEAKER_PlayStac(right, g5, eighth);
    SPEAKER_PlayStac(right, f5, eighth);

    /* 7 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStac(right, e5, quarter);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, e5, quarter);
    SPEAKER_PlayStac(right, d5, eighth);
    SPEAKER_PlayStac(right, c5, eighth);

    /* 8 */
    SPEAKER_PlayStac(right, h4, quarter + eighth);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_Play(right, e5, quarter - thirtysecond);
    SPEAKER_Play(right, d5, thirtysecond);

    /* 9 */
    SPEAKER_PlayStac(right, c5, quarter);
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_Pause(right, quarter);

    /*****************************************/


    /* 10 */
    SPEAKER_Play(right, dis5, thirtysecond);
    SPEAKER_Play(right, e5, quarter - thirtysecond);
    SPEAKER_PlayStac(right, h4, eighth);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, h4, eighth);

    /* 11 */
    SPEAKER_PlayStac(right, a4, quarter - sixteenth);
    SPEAKER_Play(right, e4, sixteenth);
    SPEAKER_Play(right, a4, sixteenth);
    SPEAKER_Play(right, e4, sixteenth);
    SPEAKER_Play(right, c5, sixteenth);
    SPEAKER_Play(right, e4, sixteenth);
    SPEAKER_PlayStac(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStac(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStac(right, d5, eighth);
    SPEAKER_PlayStac(right, c5, eighth);

    /* 12 */
    SPEAKER_PlayStac(right, h4, quarter + eighth);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_PlayStac(right, e5, quarter);

    /* 13 */
    SPEAKER_PlayStac(right, c5, quarter);
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_PlayStac(right, a4, half);

    /* 14 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_PlayStac(right, f5, eighth);
    SPEAKER_PlayStac(right, a5, quarter);
    SPEAKER_PlayStac(right, g5, eighth);
    SPEAKER_PlayStac(right, f5, eighth);

    /* 15 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStac(right, e5, quarter);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, e5, quarter);
    SPEAKER_PlayStac(right, d5, eighth);
    SPEAKER_PlayStac(right, c5, eighth);

    /* 16 */
    SPEAKER_PlayStac(right, h4, quarter + eighth);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, d5, quarter);
    SPEAKER_Play(right, e5, quarter - thirtysecond);
    SPEAKER_Play(right, d5, thirtysecond);

#endif
    /* 17 */
    SPEAKER_PlayStac(right, c5, quarter);
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_PlayStac(right, a4, quarter);

    SPEAKER_Play(right, e5, sixteenth);
    SPEAKER_Pause(right, sixteenth);
    SPEAKER_Play(right, c5, sixteenth);
    SPEAKER_Play(right, d5, eighth);

    /************ Solo part *************/
    /* 17 */
    /* eighth for above*/
    SPEAKER_Pause(right, sixteenth);
    SPEAKER_Pause(right, eighth);
    SPEAKER_Pause(right, quarter);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, d5, sixteenth);
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, d5, eighth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_Play(right, dis5, thirtysecond);
    SPEAKER_Play(right, e5, thirtysecond + eighth);

    /* 18 */
    /* eighth for above*/
    SPEAKER_PlayStac(right, c5, eighth);
    SPEAKER_PlayStac(right, a4, sixteenth);
    SPEAKER_PlayStac(right, g4, eighth);
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_Play(right, e5, sixteenth);
    SPEAKER_Play(right, g5, sixteenth);
    SPEAKER_Play(right, a5, eighth);

    /* 19 */
    SPEAKER_Play(right, c6, eighth);
    SPEAKER_Pause(right, sixteenth);

    SPEAKER_Play(right, dis5, sixteenth);
    SPEAKER_Play(right, e5, sixteenth);
    SPEAKER_Play(right, g5, sixteenth);
    SPEAKER_Play(right, a5, sixteenth);
    SPEAKER_PlayStac(right, c6, eighth + sixteenth);
    SPEAKER_Pause(right, sixteenth);

    SPEAKER_Play(right, dis5, sixteenth);
    SPEAKER_Play(right, e5, sixteenth);
    SPEAKER_Play(right, g5, sixteenth);
    SPEAKER_Play(right, a5, sixteenth);
    SPEAKER_Play(right, g5, sixteenth);

    /* 20 */
    SPEAKER_PlayStac(right, c6, eighth);
    SPEAKER_PlayStac(right, a5, sixteenth);
    SPEAKER_PlayStac(right, g5, sixteenth);
    SPEAKER_PlayStac(right, a5, sixteenth);
    SPEAKER_PlayStac(right, g5, sixteenth);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, d5, sixteenth);
    SPEAKER_PlayStac(right, a5, sixteenth);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, d5, sixteenth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, a4, sixteenth);
    SPEAKER_PlayStac(right, e4, sixteenth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, a4, sixteenth);

    /* 21 */
    SPEAKER_PlayStac(right, g5, sixteenth);
    SPEAKER_PlayStac(right, f5, sixteenth);
    SPEAKER_PlayStac(right, d5, sixteenth);
    SPEAKER_PlayStac(right, a4, sixteenth);
    SPEAKER_PlayStac(right, f4, sixteenth);
    SPEAKER_PlayStac(right, cis5, sixteenth);
    SPEAKER_PlayStac(right, d5, sixteenth);
    SPEAKER_PlayStac(right, f5, sixteenth);
    SPEAKER_PlayStac(right, a5, sixteenth);
    SPEAKER_PlayStac(right, gis5, sixteenth);
    SPEAKER_PlayStac(right, g5, sixteenth);
    SPEAKER_PlayStac(right, fis5, sixteenth);
    SPEAKER_PlayStac(right, f5, sixteenth);
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_PlayStac(right, cis5, sixteenth);
    SPEAKER_PlayStac(right, d5, sixteenth);

    /* 22 */
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_Pause(right, sixteenth);
    SPEAKER_PlayStac(right, dis4, sixteenth);
    SPEAKER_PlayStac(right, e4, sixteenth);
    SPEAKER_PlayStac(right, f4, sixteenth);
    SPEAKER_PlayStac(right, e4, sixteenth);
    SPEAKER_PlayStac(right, f4, sixteenth);
    SPEAKER_PlayStac(right, a4, sixteenth);
    SPEAKER_PlayStac(right, e5, quarter);
    SPEAKER_Play(right, c5, eighth);
    SPEAKER_Play(right, h4, sixteenth);
    SPEAKER_Play(right, a4, sixteenth);

    /* 22 */
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, a4, sixteenth);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, a4, sixteenth);
    SPEAKER_PlayStac(right, dis5, sixteenth);
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, gis4, sixteenth);

    /* 23 */
    SPEAKER_PlayStac(right, a4, sixteenth);
    SPEAKER_PlayStac(right, c5, sixteenth);
    SPEAKER_PlayStac(right, e5, sixteenth);
    SPEAKER_PlayStac(right, a5, sixteenth);
    SPEAKER_PlayStac(right, f5, sixteenth);
    SPEAKER_PlayStac(right, d5, sixteenth);
    SPEAKER_PlayStac(right, h4, sixteenth);
    SPEAKER_PlayStac(right, gis4, sixteenth);
    SPEAKER_PlayStac(right, a4, quarter);
    SPEAKER_PlayStac(right, a5, eighth);
    SPEAKER_Pause(right, eighth);
}

/**
 * @brief Play Tetris Ragtime Left Piano Hand
 */
void MUSIC_Play_TetrisRagtime_LeftHand(void)
{
    MUSIC_SetBPM(125);

#if 1
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 2 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Pause(left, eighth + quarter + half);

    /* 3 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 4 */
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 5 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 6 */
    SPEAKER_Play(left, d2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, d2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, g2, eighth);
    SPEAKER_Play(left, gis2, eighth);

    /* 7 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, d2, eighth);
    SPEAKER_Play(left, dis2, eighth);

    /* 8 */
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 9 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4,sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);


    /***************************************************/

    /* 10 */
    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 11 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 12 */
    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e2, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 13 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 14 */
    SPEAKER_PlayTwoStac(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, g1, middle, g2, eighth);
    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);

    /* 15 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwoStac(left, dis1, middle, dis2, eighth);

    /* 16 */
    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);
#endif

#if 1
    /* 17 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4,sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_Pause(left, eighth);

    SPEAKER_Pause(left, quarter);
    /************ Solo part *************/

    /* 18 */
    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 19 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 20 */
    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e2, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 21 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 22 */
    SPEAKER_PlayTwoStac(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwoStac(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, g1, middle, g2, eighth);
    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);

    /* 23 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwoStac(left, dis1, middle, dis2, eighth);

    /* 24 */
    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 25 */
    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4,sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwoStac(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwoStac(left, a1, middle, a2, eighth);
    SPEAKER_Pause(left, eighth);

    SPEAKER_PlayTwoStac(left, a2, middle, c5, eighth);
    SPEAKER_Pause(left, eighth);
#endif
}
