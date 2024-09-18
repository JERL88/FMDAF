#ifndef TaskLed_h
#define TaskLed_h
#include <esp_system.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "Task.h"


class LedTask : public Task {
    private:
    int ledPin;
    TickType_t delayMs;

    public:
    LedTask(const char* name, uint32_t stack, UBaseType_ prio, int ledpin,TickType_t delay);
    
    void taskFunction();

    void toggleLed(int ledPin);

};
#endif