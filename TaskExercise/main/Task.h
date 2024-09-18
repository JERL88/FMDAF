#ifndef Task_h
#define Task_h
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"


//Creation of main class Task
class Task
{
    protected: 
    const char* taskName;   //name of task
    uint32_t stackSize;    //stack size of task
    UBaseType_t priority;  //priority of task
    TaskHandle_t taskHandle; //task identifier
    
    public:
    
    Task(const char* name, uint32_t stack, UBaseType_t Prio); //task constructor
    ~Task(); //task destructor 
    virtual void taskFunction()=0;
    void start();
    void stop();
};
#endif
