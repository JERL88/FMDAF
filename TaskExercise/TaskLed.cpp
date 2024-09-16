#include <esp_system.h>

class LedTask : public Task {
    private:
    
    int ledPin;

    TickType_t delayMs;
    
};