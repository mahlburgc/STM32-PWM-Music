/********************************************************************************
 * @file           : music.h
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


#ifndef MUSIC_H_
#define MUSIC_H_

void MUSIC_Play_ACDC(void);

void MUSIC_Play_SuperMario(void);

void MUSIC_Play_Tetris_RightHand(void);
void MUSIC_Play_Tetris_LeftHand(void);

void MUSIC_Play_TetrisRagtime_RightHand(void);
void MUSIC_Play_TetrisRagtime_LeftHand(void);


#endif /* MUSIC_H_ */
