#include <esp_system.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include <driver/gpio.h>
class LedTask : public Task {
    private:
    int ledPin;
    TickType_t delayMs;

    public:
    LedTask(const char* name, uint32_t stack, UBaseType_ prio, int pin,TickType_t delay)
    void taskFunction() override 

    void toggleLed(int pin)
    {
        
        gpio_pad_select_gpio(pin); // Configura o pino como IO
        gpio_set_direction(pin,GPIO_MODE_OUTPUT); // Configura o IO como saida
        while 1
        {
            gpio_set_state(gpio_get_state(pin)^);
            vTaskDelay(500 / portTICK_PERIOD_MS);
        }

    }

    
};