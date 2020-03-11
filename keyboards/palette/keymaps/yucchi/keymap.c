#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _CLANDOR 1
// #define _WORKMAN 1
// #define _ASTARTEY 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _FN 5

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

#define BRMD      KC_BRMD
#define BRMU      KC_BRMU
#define KC_VOLDOWN   KC__VOLDOWN
#define KC_VOLUP     KC__VOLUP
#define KC_EJECT     KC_MEDIA_EJECT


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FN,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
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
               TAB,   ESC, RAISE,  LGUI,   SPC,                  LOWER, RAISE,  LALT, TG(_CLANDOR), BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'
  ),

  [_CLANDOR] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
               TAB,     W,     R,     D,     B,                      F,     J,     U,     P,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,     A,     S,     H,     T,     G,                      Y,     N,     E,     O,     I,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     M,     V,                      L,     K,  COMM,   DOT,  SLSH,    FN,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
               TAB,     Q, RAISE,  LGUI,   SPC,                  LOWER, RAISE,  LALT, TG(_CLANDOR), SFT(KC_TAB)  \
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
               TAB,   ESC, RAISE,  LGUI,   SPC,                  LOWER, RAISE,  LALT,   ESC,  BSPC  \
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
               TAB,   ESC, RAISE,  LGUI,   SPC,                  LOWER, RAISE,  LALT,   ESC,  BSPC  \
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
               TAB,   ESC, RAISE,  LGUI,   SPC,                  LOWER, RAISE,  LALT,   ESC,  BSPC  \
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
               TAB,   ESC, RAISE,  LGUI,   SPC,                  LOWER, RAISE,  LALT,   ESC,  BSPC  \
         //`------+------+------+------+------+------'  `------+------+------+------+------+------'
  )
};

int RGB_current_mode;

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
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_rgb_info(void);
const char *read_rgb_mat_info(void);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    // matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    matrix_write_ln(matrix, read_rgb_mat_info());
    // matrix_write_ln(matrix, read_rgb_info());
    // matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  if (record->event.pressed) {
#ifdef SSD1306OLED
    // set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
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
