#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 2 // Configura el pin GPIO que controla el LED (puedes cambiarlo según tu configuración)

void app_main(void)
{
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (true)
    {
        gpio_set_level(LED_PIN, 1); // Enciende el LED
        vTaskDelay(5000 / portTICK_PERIOD_MS); // Espera 1 segundo

        gpio_set_level(LED_PIN, 0); // Apaga el LED
        vTaskDelay(5000 / portTICK_PERIOD_MS); // Espera 1 segundo
    }
}
