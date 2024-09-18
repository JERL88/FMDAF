#include <esp_system.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "Task.h"

//Creation of main class Task

    
    Task::Task(const char* name, uint32_t stack, UBaseType_t Prio) //task constructor
    : taskName(name), stackSize(stack), priority(Prio), taskHandle(nullptr) 
    {
        xTaskCreate(this->taskFunction,taskName,stackSize,NULL,priority,&taskHandle);
    }
    
    Task::~Task() //task destructor 
    { 
        xTaskSuspend();
        vTaskDestroy();
    }

    virtual void Task::taskFunction()=0;
    
    void Task::start()
    { 
        xTaskResume();
    }
    void Task::stop()
    {
        xTaskSuspend();
    }


