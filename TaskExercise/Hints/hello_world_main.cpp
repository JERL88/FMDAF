/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include <iostream>

using std::cout;
using std::endl;
using std::runtime_error;
void Task1( void * pvParameters )
{
    for( ;; )
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        cout<<"task 1000ms"<<endl;
    }
}

void Task2( void * pvParameters )
{
    for( ;; )
    {
        vTaskDelay(500 / portTICK_PERIOD_MS);
        cout<<"task 500ms"<<endl;
    }
}

extern "C" void app_main(void)
{
    cout << "Hello world!"<< endl;
    BaseType_t xReturned;
    TaskHandle_t xHandle = NULL;

    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
                    Task1,       /* Function that implements the task. */
                    "NAME1",          /* Text name for the task. */
                    4096,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    tskIDLE_PRIORITY,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */

    xReturned = xTaskCreate(
                Task2,       /* Function that implements the task. */
                "NAME2",          /* Text name for the task. */
                4096,      /* Stack size in words, not bytes. */
                ( void * ) 1,    /* Parameter passed into the task. */
                tskIDLE_PRIORITY,/* Priority at which the task is created. */
                &xHandle );      /* Used to pass out the created task's handle. */
                    
    for (;;){ vTaskDelay(1000 / portTICK_PERIOD_MS);}
}
