#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTN_R_PIN = 28;
const int BTN_G_PIN = 26;

int main() {
  stdio_init_all();
  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);
  gpio_init(BTN_R_PIN);
  gpio_init(BTN_G_PIN);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  gpio_set_dir(BTN_R_PIN, GPIO_IN);
  gpio_set_dir(BTN_G_PIN, GPIO_IN);

  gpio_pull_up(BTN_R_PIN);
  gpio_pull_up(BTN_G_PIN);

  while (true) {
    if (!gpio_get(BTN_R_PIN)) {
      if (gpio_get(LED_PIN_R)) {
        while (!gpio_get(BTN_R_PIN)) {
          gpio_put(LED_PIN_R, 0);
        }
      } else {
        while (!gpio_get(BTN_R_PIN)) {
          gpio_put(LED_PIN_R, 1);
        }
      }
    }
    if (!gpio_get(BTN_G_PIN)) {
      if (gpio_get(LED_PIN_G)) {
        while (!gpio_get(BTN_G_PIN)) {
          gpio_put(LED_PIN_G, 0);
        }
      } else {
        while (!gpio_get(BTN_G_PIN)) {
          gpio_put(LED_PIN_G, 1);
        }
      }
    } 
  }
}


