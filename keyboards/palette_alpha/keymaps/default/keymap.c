#include QMK_KEYBOARD_H
#include <stdio.h>

#include "quantum.h"
#include "palette_alpha.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _CLANDOR 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _FN 4

#define KC_RESET  RESET
#define KC_LOWER  LOWER
#define KC_RAISE  RAISE
#define KC_FN     FN
#define KC_RST    RESET
#define KC_LRST   RGBRST
#define KC_LTOG   RGB_TOG
#define KC_LHUI   RGB_HUI
#define KC_LHUD   RGB_HUD
#define KC_LSAI   RGB_SAI
#define KC_LSAD   RGB_SAD
#define KC_LVAI   RGB_VAI
#define KC_LVAD   RGB_VAD
#define KC_LSPI   RGB_SPI
#define KC_LSPD   RGB_SPD
#define KC_LMOD   RGB_MOD
#define KC_LM_P   RGB_M_P
#define KC_LM_B   RGB_M_B
#define KC_LM_R   RGB_M_R
#define KC_LM_SW  RGB_M_SW
#define KC_LM_SN  RGB_M_SN
#define KC_LM_K   RGB_M_K
#define KC_LM_X   RGB_M_X
#define KC_LM_G   RGB_M_G
#define KC_LM_T   RGB_M_T
#define KC_TG     TG
#define KC_GUI    LGUI
#define KC_SFT    LSFT
#define KC_PHOTO_MODE   PHOTO_MODE

#define BRMD      KC_BRMD
#define BRMU      KC_BRMU
#define KC_VOLDOWN   KC__VOLDOWN
#define KC_VOLUP     KC__VOLUP
#define KC_EJECT     KC_MEDIA_EJECT


enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FN,
  PHOTO_MODE,
  BACKLIT,
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
                 Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,   ENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,    FN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
               TAB,   ESC, RAISE,  LGUI,   SPC,  HOME,      END, LOWER, RAISE,  LALT, SFT(KC_TAB), BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
                 1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL, MINUS,  PMNS,   EQL,  PPLS,  LBRC,                   RBRC,  SLSH,  SCLN,  QUOT,  BSLS,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,  UNDS,  CIRC,  ASTR,  LPRN,  LCBR,                   RCBR,  RPRN,  COLN,   DQT,  PIPE,    FN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
               TAB,   ESC, RAISE,  LGUI,   SPC,  HOME,      END, LOWER, RAISE,  LALT, SFT(KC_TAB), BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'
  ),


  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
                 1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL, MINUS,  PMNS,   EQL,  PPLS,  LBRC,                   RBRC,  SLSH,  SCLN,  QUOT,  BSLS,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,  UNDS,  CIRC,  ASTR,  LPRN,  LCBR,                   RCBR,  RPRN,  COLN,   DQT,  PIPE,    FN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
               TAB,   ESC, RAISE,  LGUI,   SPC,  HOME,      END, LOWER, RAISE,  LALT, PHOTO_MODE, BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
              EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR, GRAVE,  TILD,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,  COMM,   DOT,  EXLM,  QUES,  LPRN,                   RPRN,  AMPR,  PIPE, GRAVE,  TILD,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,    F9,   F10,   F11,   F12,  CIRC,                   UNDS,  PLUS, MINUS,    NO,    NO,    FN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
               TAB,   ESC, RAISE,  LGUI,   SPC,  HOME,      END, LOWER, RAISE,  LALT, PHOTO_MODE, BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
              LRST,  LM_P,  LM_B,  LM_R, LM_SW,                     NO,    F1,    F2,    F3,    F4,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  LSPI, LM_SN,                     NO,    F5,    F6,    F7,    F8,    NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD,  LSPD,  LM_K,                     NO,    F9,   F10,   F11,   F12,    FN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
               TAB,   ESC, RAISE,  LGUI,   SPC,  HOME,      END, LOWER, RAISE,  LALT,   ESC,  BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'
  ),

[_FN] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
              BTN2,  BTN3,  MS_U,  BTN4,  WH_U,                   BRMD,  BRMU,    NO,    UP, GUI(C(KC_DLR)),\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,  BTN1,  MS_L,  MS_D,  MS_R,  WH_D,                   BTN2,  BTN1,  LEFT,  DOWN, RIGHT,   ESC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,  WH_L,  ACL0,  ACL1,  ACL2,  WH_R,                VOLDOWN, VOLUP,  MUTE, EJECT,  RSFT,    FN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
               TAB,   ESC, RAISE,  LGUI,   SPC,  HOME,      END, LOWER, RAISE,  LALT,   ESC,  BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'

  )
};

int RGB_current_mode;
bool photo_mode = false;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    #ifdef RGB_MATRIX_ENABLE
      RGB_current_mode = rgb_matrix_config.mode;
    #endif
}

#ifdef OLED_DRIVER_ENABLE
const char *read_logo(void);
char rgb_mat_names[][16] = {
  "NONE",
  "SOLID_COLOR",
  "ALPHAS_MODS",
  "GRAD_UD",
  "GRAD_LR",
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
  // "CYC_SPIRAL",
  // "DUAL_BEACON",
  "RAINB_BEACON",
  // "RAINB_PINWH,",
  "RAIN",
  "JELLYBEAN_RAIN",
  "HEATMAP",
  "DIGIT_RAIN",
  "REACT_SIMPLE",
  // "REACT",
  // "REACT_WIDE",
  "REACT_MWIDE",
  // "REACT_CROSS",
  // "REACT_MCROSS",
  // "REACT_NEXUS",
  "REACT_MNEXUS",
  "SPLASH",
  // "MSPLASH",
  // "SOLID_SPLASH",
  // "SOLID_MSPLASH"
};

void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    char enable[4];
    char rbf_info_str[24];
    snprintf(enable, sizeof(enable), "%s", rgb_matrix_config.enable ? "on" : "- ");
    snprintf(rbf_info_str, sizeof(rbf_info_str), "%s %s", enable, rgb_mat_names[rgb_matrix_config.mode]);
    oled_write_ln(rbf_info_str, false);
    if (photo_mode) {
      oled_write_ln_P(PSTR("Photo mode"), false);
    }
    else {
      oled_write_ln_P(PSTR("Scroll mode"), false);
    }
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        oled_scroll_left();  // Turns on scrolling
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif

  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_CLANDOR);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
    case PHOTO_MODE:
      if (record->event.pressed) {
        photo_mode = !photo_mode;
      }
      return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          rgb_matrix_mode(RGB_current_mode);
          rgb_matrix_step();
          RGB_current_mode = rgb_matrix_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
          RGB_current_mode = rgb_matrix_config.mode;
        }
      #endif

      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (photo_mode){
    if (index == 0) {
      if (clockwise) {
        tap_code(KC_DOT);
      } else {
        tap_code(KC_COMM);
      }
    }
    else if (index == 1) {
      if (clockwise) {
        tap_code(KC_MINUS);
      } else {
        tap_code(KC_EQL);
      }
    }
  }
  else {
    if (index == 0) {
      if (clockwise) {
        tap_code(KC_WH_R);
      } else {
        tap_code(KC_WH_L);
      }
    }
    else if (index == 1) {
      if (clockwise) {
        tap_code(KC_WH_D);
      } else {
        tap_code(KC_WH_U);
      }
    }
  }
}
