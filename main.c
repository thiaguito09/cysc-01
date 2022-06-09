#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    adc_init ();
    adc_set_temp_sensor_enabled (true);
    adc_select_input(4);
    const float conversion_factor = 3.3f / (1 << 12);
    while (true) {
        uint16_t result = adc_read();
        float voltaje = result * conversion_factor ;
        float temperature = 27-(voltaje - 0.706)/0.001721;
        printf("Raw value: 0x%03x, voltage: %.2f V, temperatura: %.2f C° \n", result, voltaje, temperature);
        sleep_ms(500);
        
    }
    return 0;
}