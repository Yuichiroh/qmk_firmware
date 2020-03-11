
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "palette_alpha.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_ASTARTEY 2
#define L_LOWER 4
#define L_LOWER_A 6
#define L_RAISE 8
#define L_RAISE_A 10
#define L_ADJUST 16
#define L_ADJUST_A 18
#define L_ADJUST_RL 28
#define L_ADJUST_RLA 30
#define L_FN 32
#define L_FN_A 34



char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
    break;
  case L_ASTARTEY:
    // snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Astartey");
    // snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Workman");
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Clandor");
    break;
  case L_RAISE:
  case L_RAISE_A:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
  case L_LOWER_A:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_A:
  case L_ADJUST_RL:
  case L_ADJUST_RLA:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  case L_FN:
  case L_FN_A:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: FN");
    break;

  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
    // snprintf(layer_state_str, sizeof(layer_state_str), "Layer: FN");
  }

  return layer_state_str;
}
