/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

// #include <serial_config.h>
//
// #define USE_I2C
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION

#ifdef USE_Link_Time_Optimization
  // LTO has issues with macros (action_get_macro) and "functions" (fn_actions),
  //  so just disable them
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION

  #define DISABLE_LEADER
#endif // USE_Link_Time_Optimization

/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    yucchi
#define PRODUCT         Palette Keyboard for Creators (Palette Alpha)
#define DESCRIPTION     A row and column staggered split keyboard with 44 keys and two rotary encoders.

#define OLED_FONT_H "keyboards/palette_alpha/glcdfont.c"
/* key matrix size */
// Rows are doubled-up
#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }

// wiring of each half
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }
// #define MATRIX_COL_PINS { B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order

// #define SPLIT_HAND_PIN B5

#define SOFT_SERIAL_PIN D2

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B4 }
// #define ENCODERS_PAD_A_RIGHT { B2 }
// #define ENCODERS_PAD_B_RIGHT { B4 }

/* specify encoders' resolution */
// #define ENCODER_RESOLUTION 4

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT {22, 22}
#define RGBLED_NUM 44    // Number of LEDs


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
