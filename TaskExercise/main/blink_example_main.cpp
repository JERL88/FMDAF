/*
 * Copyright (c) 2024 FMDAD
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

#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "Task.h"
#include "TaskLed.h"
#include "DelayTask.h"
#include "esp_mac.h"
#include "driver/gpio.h"


using namespace std;

// Main function
extern "C" void app_main()
{
    // Create LED task
    LedTask ledTask1("task1", 1024, 1, GPIO_NUM_12, pdMS_TO_TICKS(500)); // Blinks LED on pin 12 every 500ms
    ledTask1.start();

    LedTask ledTask2("task2", 1024, 1, GPIO_NUM_14, pdMS_TO_TICKS(1000)); // Blinks LED on pin 14 every 1000ms
    ledTask2.start();

    LedTask ledTask3("task3", 1024, 1, GPIO_NUM_27, pdMS_TO_TICKS(1500)); // Blinks LED on pin 27 every 1500ms
    ledTask3.start();

   
}
