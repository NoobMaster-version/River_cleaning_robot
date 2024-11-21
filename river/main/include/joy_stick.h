#ifndef JOY_STICK_H
#define JOY_STICK_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_adc/adc_oneshot.h"
#include "sdkconfig.h"

// Function to convert GPIO to ADC1 channel
adc_channel_t gpio2adc(int gpio);

// Calibration function for joystick
void calibration(adc_oneshot_unit_handle_t adc1_handle, 
                 adc_channel_t adc1_channel_vrx, 
                 adc_channel_t adc1_channel_vry, 
                 int32_t *adc_avr);

// // Mapping function 
// int map(int x, int in_min, int in_max, int out_min, int out_max);

// Main joystick task
void joy_stick(void *pvParameters);

// Key input task
void keyin(void *pvParameters);

// NVS (Non-Volatile Storage) helper function prototypes
esp_err_t NVS_check_key(nvs_handle_t my_handle, char * key);
esp_err_t NVS_read_key(nvs_handle_t my_handle, char * key, int32_t *value);
esp_err_t NVS_write_key(nvs_handle_t my_handle, char * key, int32_t value);

#endif // JOY_STICK_H