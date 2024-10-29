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
#pragma once 

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <string>
#include "Task.h"
#include "esp_mac.h"

using namespace std;

//Created delay task with inheritance of Task
class DelayTask : public Task
{
    private:
    int delay_ms; //Time to delay the task by in ms
    string task_msg; //mesage to print when the task is delay by

    public:
    DelayTask(int time, string msg) // task cosntructor
    : Task("DelayTask",4096,4), delay_ms(time), task_msg(msg)
    {

    }

    void taskFunction() override // overrides taskFunction to be a delay
    {
        for(;;)
        {
            vTaskDelay(delay_ms/portTICK_PERIOD_MS); // creates a delay in ms
            printf("%s \n", task_msg.c_str());
        }
    }
    
};
