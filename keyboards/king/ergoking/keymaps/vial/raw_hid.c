#include "raw_hid.h"
#include "rgblight.h"
#include "rgb.h"

#define LED_COUNT_PER_CPU 4
#define LED_CPU_COUNT 4
const uint8_t PROGMEM LED_OFFSET[LED_CPU_COUNT][LED_COUNT_PER_CPU] = {
  {9,8,7,6},
  {14,13,12,11},
  {19,18,17,16},
  {24,23,22,21}/*,
  {62,61,60,59},
  {57,56,55,54},
  {52,51,50,49},
  {47,46,45,44}*/
};

const uint8_t LED_MAX[LED_COUNT_PER_CPU] = { 0x07, 0x0F, 0x7F, 0xFF };
const uint8_t LED_SHIFT[LED_COUNT_PER_CPU] = { 6, 4, 2, 0 };

void raw_hid_receive(uint8_t *data, uint8_t length) {
    /*
  for (uint8_t i = 0; i < LED_CPU_COUNT; i++) {
    for (uint8_t j = 0; j < LED_COUNT_PER_CPU; j++) {
      rgb_cpus[(i*LED_COUNT_PER_CPU)+j].hue = 128 - (data[i] >> 1);
      rgb_cpus[(i*LED_COUNT_PER_CPU)+j].val = 255; //(data[i] > LED_MAX[j] ? 255 : (data[i] << LED_SHIFT[j]) );
    }
  }
  */

  raw_hid_send(data, length);
}
