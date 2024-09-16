#include <esp_system.h>
#include <freertos>
//Creation of main class Task
class Task
{
    protected: 
    const char taskName;   //name of task
    uint32_t stackSize;    //stack size of task
    UBaseType_t priority;  //priority of task
    TaskHandle_t taskHandle; //task identifier
    
    public:
    
    Task(const char* name, uint32_t stack, UBaseType_t Prio) //task constructor
    : taskName(name), stackSize(stack), priority(prio), taskHandle(nullptr) 
    {
        xTaskCreate(this->taskFunction,taskName,stackSize,NULL,priority,&taskHandle)
    }
    
    ~Task() //task destructor 
    { 
        xTaskSuspend()
        vTaskDestroy()
    }

    virtual void taskFunction()=0
    
    void start()
    { 
        xTaskResume()
    }
    void stop()
    {
        xTaskSuspend()
    }

};
