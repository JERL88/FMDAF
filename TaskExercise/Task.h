#include <esp_system.h>

class Task
{
    protected: 
    const char taskName;
    uint32_t stackSize;
    UBaseType_t priority;
    TaskHandle_t taskHandle;
    
    public:
    Task(const char* name, uint32_t stack, UBaseType_t Prio)
    {
    }
    ~Task()
    virtual void taskFunction()=0
    void start()
    { 
    }
    void stop()
    {
    }

};