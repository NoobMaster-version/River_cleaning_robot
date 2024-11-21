#include"mcpwm_interface.h"
#include"motor_driver.h"
#include"pin_defs.h"
#include"utils.h"
#include "joy_stick.h"
#include "servo.h"
#include "freertos/event_groups.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/message_buffer.h"
#include "esp_log.h"
#include "soc/adc_channel.h"
#include "esp_adc/adc_oneshot.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "driver/gpio.h"
#include <math.h>
#include <time.h>
#include "esp_system.h"
#include "esp_event.h"


#define CONFIG_VRX_GPIO 32
#define CONFIG_VRY_GPIO 33
#define CONFIG_SW_GPIO 15