#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 2 // Configura el pin GPIO que controla el LED (puedes cambiarlo según tu configuración)

uint8_t led_level = 0;

esp_err_t init_led(void);
esp_err_t blink_led(void);

void app_main(void)
{
    init_led(); // inicializamos el pint/GPIO

    while (true) 
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Espera 1 segundo
        blink_led(); // Cambiamos de estado el pin
        printf("Led level: %u\n", led_level); // imprimo el nivel
    }

}

esp_err_t init_led(void){
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    return ESP_OK;
}


/*esp_err_t es un tipo de datos definido en el ESP-IDF (Espressif IoT Development Framework) 
para representar códigos de error en las funciones. Es un tipo enumerado (enum) que contiene 
una lista de valores que representan diferentes resultados posibles de una operación. 
Este tipo se utiliza comúnmente en las funciones del ESP-IDF para indicar si la operación se 
realizó con éxito o si ocurrió algún error, y en caso de error, qué tipo de error fue. 
Por ejemplo, en una función que inicializa un dispositivo, esp_err_t podría ser utilizado
para devolver ESP_OK si la inicialización fue exitosa, o un código de error como ESP_FAIL 
si la inicialización falló por algún motivo. Usar esp_err_t permite a los programadores verificar 
fácilmente si una operación tuvo éxito o no, y tomar las acciones necesarias en consecuencia.*/

esp_err_t blink_led(void){
led_level = !led_level;
gpio_set_level(LED_PIN, led_level);
return ESP_OK;
}



/*

-- VTASKDELAY EXPLICACION --

En el contexto de FreeRTOS en el ESP-IDF, vTaskDelay toma 
como argumento el tiempo en milisegundos durante el cual se 
debe suspender la tarea. En el ejemplo que has dado, 1000 / portTICK_PERIOD_MS, 
se divide 1000 por portTICK_PERIOD_MS. Este último es una constante que 
representa la duración de un tick de tiempo en el sistema. 
Un tick es la unidad básica de tiempo en FreeRTOS y su duración depende 
de la configuración del sistema y la frecuencia del tick del sistema.

Al dividir 1000 por portTICK_PERIOD_MS, se obtiene el número de ticks 
equivalente a 1000 milisegundos. Por lo tanto, la tarea se suspende 
durante 1000 milisegundos o 1 segundo, en este caso.

Esta función es útil para introducir retrasos en el código de una tarea
sin bloquear todo el sistema, lo que permite que otras tareas continúen ejecutándose.

*/