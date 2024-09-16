#include <esp_system.h>
#include <DelayTask.h>
#include <TaskLed.h>


// Main function
extern "C" void app_main()
{
    // Create LED task
    LedTask ledTask1("LED Task 1", 1024, 1, 2, pdMS_TO_TICKS(500)); // Blinks LED on pin 2 every 500ms
    ledTask1.start();

    LedTask ledTask2("LED Task 2", 1024, 1, 3, pdMS_TO_TICKS(1000)); // Blinks LED on pin 3 every 1000ms
    ledTask2.start();

    // Create delay task
    DelayTask delayTask("Delay Task", 1024, 1, pdMS_TO_TICKS(1500));
    delayTask.start();
}