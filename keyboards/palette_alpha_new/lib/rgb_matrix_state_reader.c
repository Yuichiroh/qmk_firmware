#ifdef RGB_MATRIX_ENABLE

#include QMK_KEYBOARD_H
#include <stdio.h>

#include "quantum.h"

char rbf_info_str[24];

char rgb_mat_names[][16] = {
  "NONE",
  "SOLID_COLOR",
  "ALPHAS_MODS",
  "GRAD_U_D",
  "BREATH",
  // "B_SAT",
  // "B_VAL",
  // "B_PINWH_S",
  // "B_PINWH_V",
  // "B_SPIRAL_S",
  // "B_SPIRAL_V",
  // "CYC_ALL",
  // "CYC_LR",
  "CYC_UD",
  // "RAINBOW_CHEV",
  // "CYC_OI",
  // "CYC_OI_DUAL,",
  // "CYC_PINWH",
  "CYC_SPIRAL",
  // "DUAL_BEACON",
  "RAINB_BEACON",
  // "RAINB_PINWH,",
  "RAIN",
  "JELLYBEAN_RAIN",
  "HEATMAP",
  "DIGIT_RAIN",
  "REACT_SIMPLE",
  // "REACT",
  "REACT_WIDE",
  "REACT_MWIDE",
  // "REACT_CROSS",
  // "REACT_MCROSS",
  "REACT_NEXUS",
  // "REACT_MNEXUS",
  "SPLASH",
  // "MSPLASH",
  "SOLID_SPLASH",
  // "SOLID_MSPLASH"
};

const char *read_rgb_mat_info(void) {
  char enable[4];
  snprintf(enable, sizeof(enable), "%s", rgb_matrix_config.enable ? "on" : "- ");
  snprintf(rbf_info_str, sizeof(rbf_info_str), "%s %s", enable, rgb_mat_names[rgb_matrix_config.mode]);
  return rbf_info_str;
}
#endif
