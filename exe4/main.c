#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int PIN_LED_R = 5;
const int PIN_LED_P = 8;
const int PIN_LED_B = 11;
const int PIN_LED_Y = 15;

const int PIN_BTN_R = 28;

int main() {
  stdio_init_all();
  gpio_init(PIN_LED_R);
  gpio_init(PIN_LED_P);
  gpio_init(PIN_LED_B);
  gpio_init(PIN_LED_Y);
  gpio_init(PIN_BTN_R);

  gpio_set_dir(PIN_LED_R, GPIO_OUT);
  gpio_set_dir(PIN_LED_P, GPIO_OUT);
  gpio_set_dir(PIN_LED_B, GPIO_OUT);
  gpio_set_dir(PIN_LED_Y, GPIO_OUT);
  gpio_set_dir(PIN_BTN_R, GPIO_IN);

  gpio_pull_up(PIN_BTN_R);


  while (true) {
    if (!gpio_get(PIN_BTN_R)) {
      gpio_put(PIN_LED_R, 1);
      sleep_ms (300);
      gpio_put(PIN_LED_R, 0);
      gpio_put(PIN_LED_P, 1);
      sleep_ms (300);
      gpio_put(PIN_LED_P, 0);
      gpio_put(PIN_LED_B, 1);
      sleep_ms (300);
      gpio_put(PIN_LED_B, 0);
      gpio_put(PIN_LED_Y, 1);
      sleep_ms (300);
      gpio_put(PIN_LED_Y, 0);
    }
  }
}
