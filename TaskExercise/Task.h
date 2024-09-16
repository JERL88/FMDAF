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
    
    static void taskEntryPoint(void* taskInstance) {
        static_cast<Task*>(taskInstance)->taskFunction();
    }
    
    void start()
    { 
        xTaskCreate()
    }
    void stop()
    {
    }

};
