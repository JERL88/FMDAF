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

#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include <stdio.h>


//Creation of main class Task
class Task
{
    protected: 
    const char* taskName;       //name of task
    uint32_t stackSize;         //stack size of task
    UBaseType_t priority;       //priority of task
    TaskHandle_t taskHandle;    //task identifier
    
    public:
    
    Task(const char* name, uint32_t stack, UBaseType_t Prio); //task constructor
    
    virtual ~Task()// task destructor 
    {
        
    } 
    
    virtual void taskFunction()=0; //creates the task to be overriden 

    void start() //Starts a task
    {
        printf("before start\n");
        //Creation of a task by using a pointer
        xTaskCreate([](void* obj) {static_cast<Task*>(obj)->taskFunction();}, taskName,stackSize,this,priority,&taskHandle);
        printf("After start\n");
    }
    
    void stop()//Stops and deletes a task
    {
        if (taskHandle != nullptr) //Checking if the task exists
        {
            vTaskDelete(taskHandle); //Destroying the task
            taskHandle=nullptr; //Changeing the task handle to NULL
        }
    }
};

