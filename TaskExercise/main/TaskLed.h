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

#include <esp_system.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "Task.h"
#include "esp_mac.h"
#include "driver/gpio.h"


class LedTask : public Task 
{
    private:
    gpio_num_t ledPin;  // pin to toggle
    TickType_t delayMs; // delay in ms
    uint32_t current_level; // current state of gpio

    public:
    LedTask(const char* name, uint32_t stack, UBaseType_t prio, gpio_num_t pin,TickType_t delay)
    :Task(name,stack,prio),ledPin(pin),delayMs(delay){
        printf("Led task created %s \n",name);
        current_level=0; 
    }
    
    void taskFunction() override // overrides the taskfunction from Task
    {
        gpio_reset_pin(ledPin);  // resets pin to default state
        gpio_set_direction(ledPin,GPIO_MODE_OUTPUT); // sets selected pin to output
        printf("GPIO has been set %d \n",(int)ledPin);
        for(;;) //toggles the selected led
        {
            toggleLed(ledPin);
        }
    }

    void toggleLed(gpio_num_t pin) //function to toggle led
    {
        current_level ^=1; //XOR functionality 
        printf("GPIO: %d , current_level %ld \n",(int)ledPin,current_level);
        gpio_set_level(pin,current_level); //sets the state for the led
        vTaskDelay(delayMs/portTICK_PERIOD_MS);//delays the toggle
    }

};
