//C Headers
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "freertos/message_buffer.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "motor_driver.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "soc/adc_channel.h"
#include "esp_adc/adc_oneshot.h"
#include "sdkconfig.h"
#include "servo.h"
static const char *TAG = "MAIN";
QueueHandle_t xQueueCmd;
//Components
#include "all_components.h"

int direction_flag;
void pwm_task(void *arg)
{
	setup_gpio();
	motor_handle_t motor_a_0, motor_a_1;
	ESP_ERROR_CHECK(enable_motor_driver(&motor_a_0, MOTOR_A_0)); // Enable motor driver A0
	ESP_ERROR_CHECK(enable_motor_driver(&motor_a_1, MOTOR_A_1)); // Enable motor driver A1


	// Make the Motors go forward & backward alternatively, at different PWM from 60 to 100
	while (1)
	{
		if( direction_flag == 1){
			
			setup_pwm(SERVO_PIN);
			set_servo_angle(45); // Move to 0 degrees
            printf("Moving to 45 degrees\n");
            vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 0.5s
		}
		if( direction_flag == 2){
			
			setup_pwm(SERVO_PIN2);
			set_servo_angle(45); // Move to 0 degrees
            printf("Moving to 45  degrees\n");
            vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 0.5s

		}
		if( direction_flag == 3){
			for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++)
			{
				// setting motor speed of MOTOR A0 in forward direction with duty cycle
				set_motor_speed(motor_a_0, MOTOR_BACKWARD, duty_cycle);

				// setting motor speed of MOTOR A1 in forward direction with duty cycle
				set_motor_speed(motor_a_1, MOTOR_BACKWARD, duty_cycle);

				// adding delay of 100ms
				vTaskDelay(100 / portTICK_PERIOD_MS);
			}

		}
		if( direction_flag == 4){
			for (int duty_cycle = 60; duty_cycle <= 100; duty_cycle++)
			{
				// setting motor speed of MOTOR A0 in forward direction with duty cycle
				set_motor_speed(motor_a_0, MOTOR_FORWARD, duty_cycle);

				// setting motor speed of MOTOR A1 in forward direction with duty cycle
				set_motor_speed(motor_a_1, MOTOR_FORWARD, duty_cycle);

				// adding delay of 100ms
				vTaskDelay(100 / portTICK_PERIOD_MS);
			}

		}


		// stopping the MOTOR A0
		set_motor_speed(motor_a_0, MOTOR_STOP, 0);

		// stopping the MOTOR A1
		set_motor_speed(motor_a_1, MOTOR_STOP, 0);

		// adding delay of 100ms
		vTaskDelay(100 / portTICK_PERIOD_MS);
	}
}

void app_main()
{
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	xQueueCmd = xQueueCreate( 1, sizeof(int16_t) );
	configASSERT( xQueueCmd );
	// Basic Function for task creation
	xTaskCreate(keyin, "KEYIN", 1024*4, NULL, 2, NULL);
	xTaskCreate(joy_stick, "STICK", 1024*4, NULL, 5, NULL);

	xTaskCreate(&pwm_task, "pwm_task", 4096, NULL, 1, NULL);
	vTaskDelay(100);

}

