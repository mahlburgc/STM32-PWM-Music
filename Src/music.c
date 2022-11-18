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

enum
{
    left = 0,
    right = 1,
    middle = 2,
};

/**
 * @brief Play ACDC - Thunderstruck
 */
void MUSIC_Play_ACDC(void)
{
    SPEAKER_SetToneLength(96);

    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(1, e4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, g4, quarter);
       SPEAKER_Play(1, c4, quarter);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(1, f4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, gis4, quarter);
       SPEAKER_Play(1, c4, quarter);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(1, e4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, g4, quarter);
       SPEAKER_Play(1, c4, quarter);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       SPEAKER_Play(1, f4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, gis4, quarter);
       SPEAKER_Play(1, c4, quarter);
    }
    for (uint8_t i = 0; i < 2; i++)
    {
       SPEAKER_Play(1, c5, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, ais4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, a4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, ais4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, a4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, g4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, a4, quarter);
       SPEAKER_Play(1, c4, quarter);
       SPEAKER_Play(1, f4, quarter);
       SPEAKER_Play(1, c4, quarter);
       for (uint8_t i = 0; i < 4; i++)
       {
           SPEAKER_Play(1, g4, quarter);
           SPEAKER_Play(1, c4, quarter);
           SPEAKER_Play(1, e4, quarter);
           SPEAKER_Play(1, c4, quarter);
       }
    }
}

/**
 * @brief Play Super Mario Bros. Theme Song
 */
void MUSIC_Play_SuperMario(void)
{
    SPEAKER_SetToneLength(352);

    SPEAKER_Play(1, fret_E12, quarter - 10);
    SPEAKER_Pause(1, 10);
    SPEAKER_Play(1, fret_E12, quarter);
    SPEAKER_Pause(1, quarter);
    SPEAKER_Play(1, fret_E12, quarter);
    SPEAKER_Pause(1, quarter);
    SPEAKER_Play(1, fret_E8, quarter - 10);
    SPEAKER_Pause(1, 10);
    SPEAKER_Play(1, fret_E12, quarter * 2 - 10);
    SPEAKER_Pause(1, 10);
    SPEAKER_Play(1, fret_E15, quarter * 2);
    SPEAKER_Pause(1, quarter * 2);
    SPEAKER_Play(1, fret_H8, quarter * 2);
}

/**
 * @brief Play Tetris Right Piano Hand
 */
void MUSIC_Play_Tetris_RightHand(void)
{
    SPEAKER_SetToneLength(400);

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
    SPEAKER_PlayCont(right, e5, half);
    SPEAKER_Play(middle, c5, half);
    SPEAKER_PlayCont(right, c5, half);
    SPEAKER_Play(middle, a4, half);

    /* 18 */
    SPEAKER_PlayCont(right, d5, half);
    SPEAKER_Play(middle, h4, half);
    SPEAKER_PlayCont(right, h4, half);
    SPEAKER_Play(middle, gis4, half);

    /* 19 */
    SPEAKER_PlayCont(right, c5, half);
    SPEAKER_Play(middle, a4, half);
    SPEAKER_PlayCont(right, a4, half);
    SPEAKER_Play(middle, e4, half);

    /* 20 */
    SPEAKER_PlayCont(right, gis4, half);
    SPEAKER_Play(middle, e4, half);
    SPEAKER_PlayCont(right, h4, half);
    SPEAKER_Play(middle, gis4, half);

    /* 21 */
    SPEAKER_PlayCont(right, e5, half);
    SPEAKER_Play(middle, c5, half);
    SPEAKER_PlayCont(right, c5, half);
    SPEAKER_Play(middle, a4, half);

    /* 22 */
    SPEAKER_PlayCont(right, d5, half);
    SPEAKER_Play(middle, h4, half);
    SPEAKER_PlayCont(right, h4, half);
    SPEAKER_Play(middle, gis4, half);

    /* 23 */
    SPEAKER_PlayCont(right, c5, quarter);
    SPEAKER_Play(middle, a4, quarter);
    SPEAKER_PlayCont(right, e5, quarter);
    SPEAKER_Play(middle, c5, quarter);
    SPEAKER_PlayCont(right, a5, quarter);
    SPEAKER_Play(middle, e5, quarter);
    SPEAKER_PlayCont(right, a5, quarter);
    SPEAKER_Play(middle, e5, quarter);

    /* 24*/
    SPEAKER_PlayCont(right, gis5, full);
    SPEAKER_Play(middle, e5, full);

    /*********** third part ********/

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 25 */
        SPEAKER_PlayCont(right, e5, quarter);
        SPEAKER_Play(middle, h4, quarter);

        SPEAKER_PlayCont(right, h4, eighth);
        SPEAKER_Play(middle, gis4, eighth);
        SPEAKER_PlayCont(right, c5, eighth);
        SPEAKER_Play(middle, a4, eighth);

        SPEAKER_PlayCont(right, d5, eighth);
        SPEAKER_Play(middle, h4, eighth);
        SPEAKER_Play(right, e5, sixteenth);
        SPEAKER_Play(right, d5, sixteenth);

        SPEAKER_PlayCont(right, c5, eighth);
        SPEAKER_Play(middle, a4, eighth);
        SPEAKER_PlayCont(right, h4, eighth);
        SPEAKER_Play(middle, gis4, eighth);

        /* 26 */
        SPEAKER_PlayCont(right, a4, quarter);
        SPEAKER_Play(middle, e4, quarter);

        SPEAKER_PlayCont(right, a4, eighth);
        SPEAKER_Play(middle, e4, eighth);
        SPEAKER_PlayCont(right, c5, eighth);
        SPEAKER_Play(middle, a5, eighth);

        SPEAKER_PlayCont(right, e5, quarter);
        SPEAKER_Play(middle, c5, quarter);

        SPEAKER_PlayCont(right, d5, eighth);
        SPEAKER_Play(middle, h4, eighth);
        SPEAKER_PlayCont(right, c5, eighth);
        SPEAKER_Play(middle, a4, eighth);

        /* 27 */
        SPEAKER_PlayCont(right, h4, eighth);
        SPEAKER_Play(middle, gis4, eighth);
        SPEAKER_PlayCont(right, e4, eighth);
        SPEAKER_Play(middle, 0, eighth);

        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, c5, eighth);

        SPEAKER_PlayCont(right, d5, quarter);
        SPEAKER_Play(middle, h4, quarter);

        SPEAKER_PlayCont(right, e5, quarter);
        SPEAKER_Play(middle, c4, quarter);

        /* 28 */
        SPEAKER_PlayCont(right, c5, quarter);
        SPEAKER_Play(middle, a4, quarter);
        SPEAKER_PlayCont(right, a4, quarter);
        SPEAKER_Play(middle, e4, quarter);

        SPEAKER_PlayCont(right, a4, half);
        SPEAKER_Play(middle, e4, half);

        /* 29 */
        SPEAKER_Pause(right, eighth);
        SPEAKER_PlayCont(right, d5, quarter);
        SPEAKER_Play(middle, f4, quarter);
        SPEAKER_PlayCont(right, f5, eighth);
        SPEAKER_Play(middle, a4, eighth);

        SPEAKER_PlayCont(right, a5, quarter);
        SPEAKER_Play(middle, c5, quarter);
        SPEAKER_PlayCont(right, g5, eighth);
        SPEAKER_Play(middle, h4, eighth);
        SPEAKER_PlayCont(right, f5, eighth);
        SPEAKER_Play(middle, a4, eighth);

        /* 30 */
        SPEAKER_Pause(right, eighth);
        SPEAKER_PlayCont(right, e5, quarter);
        SPEAKER_Play(middle, g4, quarter);
        SPEAKER_PlayCont(right, c5, eighth);
        SPEAKER_Play(middle, e5, eighth); /* e4 */

        SPEAKER_PlayCont(right, e5, quarter);
        SPEAKER_Play(middle, g4, quarter);
        SPEAKER_PlayCont(right, d5, eighth);
        SPEAKER_Play(middle, f4, eighth);
        SPEAKER_PlayCont(right, c5, eighth);
        SPEAKER_Play(middle, e4, eighth);

        /* 31 */
        SPEAKER_PlayCont(right, h4, eighth);
        SPEAKER_Play(middle, gis4, eighth);
        SPEAKER_PlayCont(right, e4, eighth);
        SPEAKER_Play(middle, 0, eighth);

        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, gis4, sixteenth);
        SPEAKER_Play(right, c5, eighth);

        SPEAKER_PlayCont(right, d5, quarter);
        SPEAKER_Play(middle, h4, quarter);

        SPEAKER_PlayCont(right, e5, quarter);
        SPEAKER_Play(middle, c4, quarter);

        /* 32 */
        SPEAKER_PlayCont(right, c5, quarter);
        SPEAKER_Play(middle, a4, quarter);
        SPEAKER_PlayCont(right, a4, quarter);
        SPEAKER_Play(middle, e4, quarter);

        SPEAKER_PlayCont(right, a4, half);
        SPEAKER_Play(middle, e4, half);
    }

    /* end */
    SPEAKER_PlayCont(right, 0, 0);
    SPEAKER_PlayCont(left, 0, 0);
    SPEAKER_PlayCont(middle, 0, 0);
}


/**
 * @brief Play Tetris Left Piano Hand
 */
void MUSIC_Play_Tetris_LeftHand(void)
{
    SPEAKER_SetToneLength(400);

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
    SPEAKER_PlayCont(right, 0, 0);
    SPEAKER_PlayCont(left, 0, 0);
    SPEAKER_PlayCont(middle, 0, 0);
}

/**
 * @brief Play Tetris Ragtime Right Piano Hand
 */
void MUSIC_Play_TetrisRagtime_RightHand(void)
{
    SPEAKER_SetToneLength(480);
    SPEAKER_SetStaccato(25);

#if 1
    /* 1 */
    SPEAKER_Pause(right, full);

    /* 2 */
    SPEAKER_Pause(right, quarter);
    SPEAKER_PlayStaccato(right, h4, eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, h4, eighth);

    /* 3 */
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_PlayStaccato(right, a4, eighth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStaccato(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStaccato(right, d5, eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);

    /* 4 */
    SPEAKER_PlayStaccato(right, h4, quarter + eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_PlayStaccato(right, e5, quarter);

    /* 5 */
    SPEAKER_PlayStaccato(right, c5, quarter);
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_PlayStaccato(right, a4, half);

    /* 6 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_PlayStaccato(right, f5, eighth);
    SPEAKER_PlayStaccato(right, a5, quarter);
    SPEAKER_PlayStaccato(right, g5, eighth);
    SPEAKER_PlayStaccato(right, f5, eighth);

    /* 7 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStaccato(right, e5, quarter);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, e5, quarter);
    SPEAKER_PlayStaccato(right, d5, eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);

    /* 8 */
    SPEAKER_PlayStaccato(right, h4, quarter + eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_Play(right, e5, quarter - thirtysecond);
    SPEAKER_Play(right, d5, thirtysecond);

    /* 9 */
    SPEAKER_PlayStaccato(right, c5, quarter);
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_Pause(right, quarter);

    /*****************************************/


    /* 10 */
    SPEAKER_Play(right, dis5, thirtysecond);
    SPEAKER_Play(right, e5, quarter - thirtysecond);
    SPEAKER_PlayStaccato(right, h4, eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, h4, eighth);

    /* 11 */
    SPEAKER_PlayStaccato(right, a4, quarter - sixteenth);
    SPEAKER_Play(right, e4, sixteenth);
    SPEAKER_Play(right, a4, sixteenth);
    SPEAKER_Play(right, e4, sixteenth);
    SPEAKER_Play(right, c5, sixteenth);
    SPEAKER_Play(right, e4, sixteenth);
    SPEAKER_PlayStaccato(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStaccato(right, e5, eighth - 25);
    SPEAKER_Pause(right, 25);
    SPEAKER_PlayStaccato(right, d5, eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);

    /* 12 */
    SPEAKER_PlayStaccato(right, h4, quarter + eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_PlayStaccato(right, e5, quarter);

    /* 13 */
    SPEAKER_PlayStaccato(right, c5, quarter);
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_PlayStaccato(right, a4, half);

    /* 14 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_PlayStaccato(right, f5, eighth);
    SPEAKER_PlayStaccato(right, a5, quarter);
    SPEAKER_PlayStaccato(right, g5, eighth);
    SPEAKER_PlayStaccato(right, f5, eighth);

    /* 15 */
    SPEAKER_Pause(right, eighth);
    SPEAKER_PlayStaccato(right, e5, quarter);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, e5, quarter);
    SPEAKER_PlayStaccato(right, d5, eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);

    /* 16 */
    SPEAKER_PlayStaccato(right, h4, quarter + eighth);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, d5, quarter);
    SPEAKER_Play(right, e5, quarter - thirtysecond);
    SPEAKER_Play(right, d5, thirtysecond);

#endif
    /* 17 */
    SPEAKER_PlayStaccato(right, c5, quarter);
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_PlayStaccato(right, a4, quarter);

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
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, d5, sixteenth);
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, d5, eighth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_Play(right, dis5, thirtysecond);
    SPEAKER_Play(right, e5, thirtysecond + eighth);

    /* 18 */
    /* eighth for above*/
    SPEAKER_PlayStaccato(right, c5, eighth);
    SPEAKER_PlayStaccato(right, a4, sixteenth);
    SPEAKER_PlayStaccato(right, g4, eighth);
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
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
    SPEAKER_PlayStaccato(right, c6, eighth + sixteenth);
    SPEAKER_Pause(right, sixteenth);

    SPEAKER_Play(right, dis5, sixteenth);
    SPEAKER_Play(right, e5, sixteenth);
    SPEAKER_Play(right, g5, sixteenth);
    SPEAKER_Play(right, a5, sixteenth);
    SPEAKER_Play(right, g5, sixteenth);

    /* 20 */
    SPEAKER_PlayStaccato(right, c6, eighth);
    SPEAKER_PlayStaccato(right, a5, sixteenth);
    SPEAKER_PlayStaccato(right, g5, sixteenth);
    SPEAKER_PlayStaccato(right, a5, sixteenth);
    SPEAKER_PlayStaccato(right, g5, sixteenth);
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, d5, sixteenth);
    SPEAKER_PlayStaccato(right, a5, sixteenth);
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, d5, sixteenth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, a4, sixteenth);
    SPEAKER_PlayStaccato(right, e4, sixteenth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, a4, sixteenth);

    /* 21 */
    SPEAKER_PlayStaccato(right, g5, sixteenth);
    SPEAKER_PlayStaccato(right, f5, sixteenth);
    SPEAKER_PlayStaccato(right, d5, sixteenth);
    SPEAKER_PlayStaccato(right, a4, sixteenth);
    SPEAKER_PlayStaccato(right, f4, sixteenth);
    SPEAKER_PlayStaccato(right, cis5, sixteenth);
    SPEAKER_PlayStaccato(right, d5, sixteenth);
    SPEAKER_PlayStaccato(right, f5, sixteenth);
    SPEAKER_PlayStaccato(right, a5, sixteenth);
    SPEAKER_PlayStaccato(right, gis5, sixteenth);
    SPEAKER_PlayStaccato(right, g5, sixteenth);
    SPEAKER_PlayStaccato(right, fis5, sixteenth);
    SPEAKER_PlayStaccato(right, f5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_PlayStaccato(right, cis5, sixteenth);
    SPEAKER_PlayStaccato(right, d5, sixteenth);

    /* 22 */
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_Pause(right, sixteenth);
    SPEAKER_PlayStaccato(right, dis4, sixteenth);
    SPEAKER_PlayStaccato(right, e4, sixteenth);
    SPEAKER_PlayStaccato(right, f4, sixteenth);
    SPEAKER_PlayStaccato(right, e4, sixteenth);
    SPEAKER_PlayStaccato(right, f4, sixteenth);
    SPEAKER_PlayStaccato(right, a4, sixteenth);
    SPEAKER_PlayStaccato(right, e5, quarter);
    SPEAKER_Play(right, c5, eighth);
    SPEAKER_Play(right, h4, sixteenth);
    SPEAKER_Play(right, a4, sixteenth);

    /* 22 */
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, a4, sixteenth);
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, a4, sixteenth);
    SPEAKER_PlayStaccato(right, dis5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, gis4, sixteenth);

    /* 23 */
    SPEAKER_PlayStaccato(right, a4, sixteenth);
    SPEAKER_PlayStaccato(right, c5, sixteenth);
    SPEAKER_PlayStaccato(right, e5, sixteenth);
    SPEAKER_PlayStaccato(right, a5, sixteenth);
    SPEAKER_PlayStaccato(right, f5, sixteenth);
    SPEAKER_PlayStaccato(right, d5, sixteenth);
    SPEAKER_PlayStaccato(right, h4, sixteenth);
    SPEAKER_PlayStaccato(right, gis4, sixteenth);
    SPEAKER_PlayStaccato(right, a4, quarter);
    SPEAKER_PlayStaccato(right, a5, eighth);
    SPEAKER_Pause(right, eighth);
}

/**
 * @brief Play Tetris Ragtime Left Piano Hand
 */
void MUSIC_Play_TetrisRagtime_LeftHand(void)
{
    SPEAKER_SetToneLength(480);
    SPEAKER_SetStaccato(25);

#if 1
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 2 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_Pause(left, eighth + quarter + half);

    /* 3 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 4 */
    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 5 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 6 */
    SPEAKER_Play(left, d2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, d2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, g2, eighth);
    SPEAKER_Play(left, gis2, eighth);

    /* 7 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, d2, eighth);
    SPEAKER_Play(left, dis2, eighth);

    /* 8 */
    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 9 */
    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4,sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_Play(left, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);


    /***************************************************/

    /* 10 */
    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 11 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 12 */
    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e2, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 13 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 14 */
    SPEAKER_PlayTwo(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, g1, middle, g2, eighth);
    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);

    /* 15 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwo(left, dis1, middle, dis2, eighth);

    /* 16 */
    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);
#endif

#if 1
    /* 17 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4,sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_Pause(left, eighth);

    SPEAKER_Pause(left, quarter);
    /************ Solo part *************/

    /* 18 */
    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 19 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 20 */
    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e2, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 21 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 22 */
    SPEAKER_PlayTwo(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwo(left, f3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, g1, middle, g2, eighth);
    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);

    /* 23 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, e3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, d1, middle, d2, eighth);
    SPEAKER_PlayTwo(left, dis1, middle, dis2, eighth);

    /* 24 */
    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, h1, middle, h2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, e4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, gis1, middle, gis2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, d4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, gis3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    /* 25 */
    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4,sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, e1, middle, e2, eighth);
    SPEAKER_PlayTwo(left, a3, middle, c4, sixteenth);
    SPEAKER_Pause(left, sixteenth);

    SPEAKER_PlayTwo(left, a1, middle, a2, eighth);
    SPEAKER_Pause(left, eighth);

    SPEAKER_PlayTwo(left, a2, middle, c5, eighth);
    SPEAKER_Pause(left, eighth);
#endif
}

///**
// * @brief Play Tetris
// */
//void SPEAKER_Play_Tetris(void)
//{
//    const uint16_t duration = 400; /* for quarter note */
//
//    const uint16_t full = duration * 4;
//    const uint16_t half = duration * 2;
//    const uint16_t quarter = duration;
//    const uint16_t eighth = duration / 2;
//    const uint16_t sixteenth = duration / 4;
//
//    enum
//    {
//        left = 0,
//        right = 1,
//        middle = 2,
//    };
//
//    /* 1 */
//    SPEAKER_Play(right, e5, quarter);
//    SPEAKER_Play(right, h4, eighth);
//    SPEAKER_Play(right, c5, eighth);
//    SPEAKER_Play(right, d5, eighth);
//    SPEAKER_Play(right, e5, sixteenth);
//    SPEAKER_Play(right, d5, sixteenth);
//    SPEAKER_Play(right, c5, eighth);
//    SPEAKER_Play(right, h4, eighth);
//
//    /* 2 */
//    SPEAKER_Play(right, a4, quarter);
//    SPEAKER_Play(right, a4, eighth);
//    SPEAKER_Play(right, c5, eighth);
//    SPEAKER_Play(right, e5, quarter);
//    SPEAKER_Play(right, d5, eighth);
//    SPEAKER_Play(right, c5, eighth);
//
//    /* 3 */
//    SPEAKER_Play(right, h4, quarter);
//    SPEAKER_Play(right, h4, eighth);
//    SPEAKER_Play(right, c5, eighth);
//    SPEAKER_Play(right, d5, quarter);
//    SPEAKER_Play(right, e5, quarter);
//
//    /* 4 */
//    SPEAKER_Play(right, c5, quarter);
//    SPEAKER_Play(right, a4, quarter);
//    SPEAKER_Play(right, a4, half);
//
//    /* 5 */
//    SPEAKER_Play(right, 0, eighth);
//    SPEAKER_Play(right, d5, quarter);
//    SPEAKER_Play(right, f5, eighth);
//    SPEAKER_Play(right, a5, quarter);
//    SPEAKER_Play(right, g5, eighth);
//    SPEAKER_Play(right, f5, eighth);
//
//    /* 6 */
//    SPEAKER_Play(right, 0, eighth);
//    SPEAKER_Play(right, e5, quarter);
//    SPEAKER_Play(right, c5, eighth);
//    SPEAKER_Play(right, e5, quarter);
//    SPEAKER_Play(right, d5, eighth);
//    SPEAKER_Play(right, c5, eighth);
//
//    /* 7 */
//    SPEAKER_Play(right, h4, quarter);
//    SPEAKER_Play(right, h4, eighth);
//    SPEAKER_Play(right, c5, eighth);
//    SPEAKER_Play(right, d5, quarter);
//    SPEAKER_Play(right, e5, quarter);
//
//    /* 8 */
//    SPEAKER_Play(right, c5, quarter);
//    SPEAKER_Play(right, a4, quarter);
//    SPEAKER_Play(right, a4, half);
//
//    for (uint8_t i = 0; i < 1; i++)
//    {
//        /* 1 */
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_PlayCont(left, e3);
//        SPEAKER_Play(right, e5, sixteenth);
//        SPEAKER_Play(right, d5, sixteenth);
//
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_Play(left, e3, eighth);
//
//        /* 2 */
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, a3, eighth);
//
//        /* 3 */
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_Play(left, gis2, eighth);
//        SPEAKER_Play(left, gis3, eighth);
//
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_Play(left, gis2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, gis3, eighth);
//
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        /* 4 */
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, h2, eighth);
//        SPEAKER_Play(left, c2, eighth);
//        SPEAKER_Play(left, d3, eighth);
//
//        /* 5 */
//        SPEAKER_PlayCont(right, 0);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_Play(left, d3, eighth);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_PlayCont(right, f5);
//        SPEAKER_Play(left, d3, eighth);
//
//        SPEAKER_PlayCont(right, a5);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_Play(left, d3, eighth);
//
//        SPEAKER_PlayCont(right, g5);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_PlayCont(right, f5);
//        SPEAKER_Play(left, d3, eighth);
//
//        /* 6 */
//        SPEAKER_PlayCont(right, 0);
//        SPEAKER_Play(left, c2, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_Play(left, c3, eighth);
//        SPEAKER_Play(left, c2, eighth);
//
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, c3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_Play(left, c2, eighth);
//        SPEAKER_Play(left, c3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_Play(left, c2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, c3, eighth);
//
//        /* 7 */
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_Play(left, g2, eighth);
//        SPEAKER_Play(left, g3, eighth);
//
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_Play(left, g2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, g3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        /* 8 */
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//        SPEAKER_Play(left, a2, quarter);
//    }
//
//    /* 1 */
//    SPEAKER_PlayCont(right, e5);
//    SPEAKER_PlayCont(middle, c5);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 2 */
//    SPEAKER_PlayCont(right, c5);
//    SPEAKER_PlayCont(middle, a4);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 3 */
//    SPEAKER_PlayCont(right, d5);
//    SPEAKER_PlayCont(middle, h4);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//
//    /* 4 */
//    SPEAKER_PlayCont(right, h4);
//    SPEAKER_PlayCont(middle, gis4);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//
//    /* 5 */
//    SPEAKER_PlayCont(right, c5);
//    SPEAKER_PlayCont(middle, a4);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 6 */
//    SPEAKER_PlayCont(right, a4);
//    SPEAKER_PlayCont(middle, e4);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 7 */
//    SPEAKER_PlayCont(right, gis4);
//    SPEAKER_PlayCont(middle, e4);
//    SPEAKER_Play(left, gis2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, gis2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 8 */
//    SPEAKER_PlayCont(right, h4);
//    SPEAKER_PlayCont(middle, gis4);
//    SPEAKER_Play(left, gis2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, gis2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 9 */
//    SPEAKER_PlayCont(right, e5);
//    SPEAKER_PlayCont(middle, c5);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 10 */
//    SPEAKER_PlayCont(right, c5);
//    SPEAKER_PlayCont(middle, a4);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 11 */
//    SPEAKER_PlayCont(right, d5);
//    SPEAKER_PlayCont(middle, h4);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//
//    /* 12 */
//    SPEAKER_PlayCont(right, h4);
//    SPEAKER_PlayCont(middle, gis4);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//    SPEAKER_Play(left, h2, eighth);
//    SPEAKER_Play(left, d3, eighth);
//
//    /* 13 */
//    SPEAKER_PlayCont(right, c5);
//    SPEAKER_PlayCont(middle, a4);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_PlayCont(right, e5);
//    SPEAKER_PlayCont(middle, c5);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 14 */
//    SPEAKER_PlayCont(right, a5);
//    SPEAKER_PlayCont(middle, e5);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_PlayCont(right, a5);
//    SPEAKER_PlayCont(middle, e5);
//    SPEAKER_Play(left, a2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 15 */
//    SPEAKER_PlayCont(right, gis5);
//    SPEAKER_PlayCont(middle, e5);
//    SPEAKER_Play(left, gis2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//    SPEAKER_Play(left, gis2, eighth);
//    SPEAKER_Play(left, e3, eighth);
//
//    /* 16 */
//    SPEAKER_Play(left, gis2, quarter - 10);
//    SPEAKER_Pause(left, 10);
//    SPEAKER_Play(left, gis2, quarter - 10);
//    SPEAKER_Pause(left, 10);
//
//    for (uint8_t i = 0; i < 2; i++)
//    {
//        /* 1 */
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_PlayCont(middle, h4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_PlayCont(middle, gis4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, a4);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_PlayCont(middle, h4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_PlayCont(left, e3);
//        SPEAKER_Play(right, e5, sixteenth);
//        SPEAKER_PlayCont(middle, 0);
//        SPEAKER_Play(right, d5, sixteenth);
//        SPEAKER_PlayCont(middle, 0);
//
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, a4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_PlayCont(middle, gis4);
//        SPEAKER_Play(left, e3, eighth);
//
//        /* 2 */
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_PlayCont(middle, e4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_PlayCont(middle, e4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, a5);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_PlayCont(middle, c5);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_PlayCont(middle, h4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, a4);
//        SPEAKER_Play(left, a3, eighth);
//
//        /* 3 */
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_PlayCont(middle, gis4);
//        SPEAKER_Play(left, gis2, eighth);
//        SPEAKER_PlayCont(right, e4);
//        SPEAKER_PlayCont(middle, 0);
//        SPEAKER_Play(left, gis3, eighth);
//
//        SPEAKER_PlayCont(left, gis2);
//        SPEAKER_Play(right, gis4, sixteenth);
//        SPEAKER_Play(right, gis4, sixteenth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, gis3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_PlayCont(middle, h4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_PlayCont(middle, c4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        /* 4 */
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_PlayCont(middle, e4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_PlayCont(middle, e4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, h2, eighth);
//        SPEAKER_Play(left, c2, eighth);
//        SPEAKER_Play(left, d3, eighth);
//
//        /* 5 */
//        SPEAKER_PlayCont(right, 0);
//        SPEAKER_PlayCont(middle, 0);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_PlayCont(middle, f4);
//        SPEAKER_Play(left, d3, eighth);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_PlayCont(right, f5);
//        SPEAKER_PlayCont(middle, a4);
//        SPEAKER_Play(left, d3, eighth);
//
//        SPEAKER_PlayCont(right, a5);
//        SPEAKER_PlayCont(middle, c5);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_Play(left, d3, eighth);
//
//        SPEAKER_PlayCont(right, g5);
//        SPEAKER_PlayCont(middle, h4);
//        SPEAKER_Play(left, d2, eighth);
//        SPEAKER_PlayCont(right, f5);
//        SPEAKER_PlayCont(middle, a4);
//        SPEAKER_Play(left, d3, eighth);
//
//        /* end */
//        SPEAKER_PlayCont(right, 0);
//        SPEAKER_PlayCont(left, 0);
//        SPEAKER_PlayCont(middle, 0);
//
//        /* 6 */
//        SPEAKER_PlayCont(right, 0);
//        SPEAKER_PlayCont(middle, 0);
//        SPEAKER_Play(left, c2, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_PlayCont(middle, g4);
//        SPEAKER_Play(left, c3, eighth);
//        SPEAKER_Play(left, c2, eighth);
//
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, e5); /* e4 */
//        SPEAKER_Play(left, c3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_PlayCont(middle, g4);
//        SPEAKER_Play(left, c2, eighth);
//        SPEAKER_Play(left, c3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_PlayCont(middle, f4);
//        SPEAKER_Play(left, c2, eighth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, e4);
//        SPEAKER_Play(left, c3, eighth);
//
//        /* 7 */
//        SPEAKER_PlayCont(right, h4);
//        SPEAKER_PlayCont(middle, gis4);
//        SPEAKER_Play(left, gis2, eighth);
//        SPEAKER_PlayCont(right, e4);
//        SPEAKER_PlayCont(middle, 0);
//        SPEAKER_Play(left, gis3, eighth);
//
//        SPEAKER_PlayCont(left, gis2);
//        SPEAKER_Play(right, gis4, sixteenth);
//        SPEAKER_Play(right, gis4, sixteenth);
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_Play(left, gis3, eighth);
//
//        SPEAKER_PlayCont(right, d5);
//        SPEAKER_PlayCont(middle, h4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        SPEAKER_PlayCont(right, e5);
//        SPEAKER_PlayCont(middle, c4);
//        SPEAKER_Play(left, e2, eighth);
//        SPEAKER_Play(left, e3, eighth);
//
//        /* 8 */
//        SPEAKER_PlayCont(right, c5);
//        SPEAKER_PlayCont(middle, a4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_PlayCont(middle, e4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//
//        SPEAKER_PlayCont(right, a4);
//        SPEAKER_PlayCont(middle, e4);
//        SPEAKER_Play(left, a2, eighth);
//        SPEAKER_Play(left, a3, eighth);
//        SPEAKER_Play(left, a2, quarter);
//    }
//
//    /* end */
//    SPEAKER_PlayCont(right, 0);
//    SPEAKER_PlayCont(left, 0);
//    SPEAKER_PlayCont(middle, 0);
//
//}
