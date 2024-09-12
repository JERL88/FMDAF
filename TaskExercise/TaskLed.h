#include <esp_system.h>
#include <Task.h>
class LedTask : public Task {
    private:
    int ledPin;
    TickType_t delayMs;

    public:
    LedTask(const char* name, uint32_t stack, UBaseType_ prio, int pin,TickType_t delay)
    void taskFunction() override 
    void toggleLed(int pin)

    
};