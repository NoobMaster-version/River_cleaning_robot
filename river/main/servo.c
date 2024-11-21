#include "servo.h"

void setup_pwm(uint8_t SERVO_PIN) {
    // Configure the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = SPEED_MODE,
        .timer_num        = TIMER_NUM,
        .duty_resolution  = DUTY_RESOLUTION,
        .freq_hz          = FREQUENCY,
        .clk_cfg          = CLK_CONFIG
    };
    ledc_timer_config(&ledc_timer);

    // Configure the LEDC channel
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = SPEED_MODE,
        .channel        = CHANNEL,
        .timer_sel      = TIMER_NUM,
        .intr_type      = INTR_TYPE,
        .gpio_num       = SERVO_PIN,
        .duty           = 0, // Initial duty cycle
        .hpoint         = 0
    };
    ledc_channel_config(&ledc_channel);
}

void set_servo_angle(int angle) 
{
    // Convert angle to duty cycle
    int pulsewidth = SERVO_MIN_PULSEWIDTH + ((SERVO_MAX_PULSEWIDTH - SERVO_MIN_PULSEWIDTH) * angle) / SERVO_MAX_DEGREE;
    int duty = (pulsewidth * 8192) / 20000; // 8192 is 2^13 for 13-bit resolution
    ledc_set_duty(SPEED_MODE, CHANNEL, duty);
    ledc_update_duty(SPEED_MODE, CHANNEL);
}
void setup_gpio()
{
    //configure input pins
    gpio_config_t pin_config;
    pin_config.intr_type = GPIO_INTR_DISABLE;
    pin_config.mode = GPIO_MODE_INPUT;
    pin_config.pin_bit_mask = (1ULL << INPUT_PIN_1) | (1ULL << INPUT_PIN_2) | (1ULL << INPUT_PIN_3) | (1ULL << INPUT_PIN_4);
    pin_config.pull_up_en = GPIO_PULLUP_ENABLE;
    pin_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_config(&pin_config);
}

// void app_main(void)
// {
//     setup_gpio();
//     setup_pwm(SERVO_PIN);
//     while(1)
//     {
//         int sensor01 = gpio_get_level(INPUT_PIN_1);
//         int sensor02 = gpio_get_level(INPUT_PIN_2);        
//         int sensor03 = gpio_get_level(INPUT_PIN_3);
//         int sensor04 = gpio_get_level(INPUT_PIN_4);

//         if(sensor01)
//         {
//             set_servo_angle(0); // Move to 0 degrees
//             printf("Moving to 0 degrees\n");
//             vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 0.5s
//         }
//         else if(sensor02)
//         {
//             set_servo_angle(30); // Move back to 30 degrees
//             printf("Returning to 30 degrees\n");
//             vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 0.5s
//         }
//         else if(sensor03)
//         {
//             set_servo_angle(60); // Move back to 60 degrees
//             printf("Returning to 60 degrees\n");
//             vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 0.5s
//         }
//         else if(sensor04)
//         {
//             set_servo_angle(90); // Move back to 90 degrees
//             printf("Returning to 90 degrees\n");
//             vTaskDelay(pdMS_TO_TICKS(500)); // Wait for 0.5s
//         }
//         vTaskDelay(pdMS_TO_TICKS(1));
//     }
// }