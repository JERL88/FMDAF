#include <esp_system.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include <TaskLed.h>

    LedTask::LedTask(const char* name, uint32_t stack, UBaseType_ prio, int ledpin,TickType_t delay)
    
    void LedTask::taskFunction()
    {
        vTaskSuspend(NULL);//Suspending the ctive task
        vTaskDelet(NULL);//Deleting the active task
    } 

    void LedTask::toggleLed(int ledPin)
    {
        
        gpio_pad_select_gpio(ledPin); // Configuring the IO pin
        gpio_set_direction(ledPin,GPIO_MODE_OUTPUT); // Configuring the IO pin as output
        for(;;)
        {
            gpio_set_state(gpio_get_state(ledPin)^1); // toggles the GPIO
            vTaskDelay(delayMs); // Delay between each toggle
        }

    }
    

    
