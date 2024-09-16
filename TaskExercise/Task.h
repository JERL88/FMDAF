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

    }
    
    ~Task() //task destructor 
    { 
        stop();
    }
    
    virtual void taskFunction()=0

    static void taskFunctionWrapper(void* pvParameters)
    {
        // Convert the pointer back to the object
        Task* task = static_cast<Task*>(pvParameters);
        // Call the task 
        task->taskFunction();
        // Delete the task
        vTaskDelete(nullptr);
    }

    void start()
    { 
        xTaskCreate()
    }
    void stop()
    {
    }

};
