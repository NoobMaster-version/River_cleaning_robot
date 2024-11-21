/*
 * MIT License
 *
 * Copyright (c)  2021 Society of Robotics and Automation
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
 */

#ifndef PIN_DEFS_H
#define PIN_DEFS_H

#define CHECK(x)                \
    do                          \
    {                           \
        esp_err_t __;           \
        if ((__ = x) != ESP_OK) \
            return __;          \
    } while (0)
#define CHECK_LOGE(err, x, tag, msg, ...)      \
    do                                         \
    {                                          \
        if ((err = x) != ESP_OK)               \
        {                                      \
            ESP_LOGE(tag, msg, ##__VA_ARGS__); \
            return err;                        \
        }                                      \
    } while (0)

//////// mpu //////


/////////////////////////////



//////// bar graph //////////

/////////////////////////////

////////// switches //////////

/////////////////////////////

/////////// lsa /////////////

//******* battery ********//
/////////////////////////////

/////// motor driver ////////
//****** normal mode ******//
#define MDA_NORMAL_IN_1 12 //MCPWM_UNIT_1 MCPWM0A
#define MDA_NORMAL_IN_2 13 //MCPWM_UNIT_1 MCPWM0B
#define MDA_NORMAL_IN_3 25 //MCPWM_UNIT_1 MCPWM1A
#define MDA_NORMAL_IN_4 26 //MCPWM_UNIT_1 MCPWM1B

//***** parallel mode *****//
#define MDA_PARALLEL_IN_1_2 25 //MCPWM_UNIT_1 MCPWM0A
#define MDA_PARALLEL_IN_3_4 26 //MCPWM_UNIT_1 MCPWM0B
/////////////////////////////

/////////// servos //////////
/////////////////////////////

#endif
