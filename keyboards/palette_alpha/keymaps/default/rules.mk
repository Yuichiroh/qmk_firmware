# For using per-key effects, uncomment these lines
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = WS2812
# RGB_MATRIX_ENABLE = no

MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
# CONSOLE_ENABLE = yes

ENCODER_ENABLE = yes

# if firmware size over limit, try this option
CFLAGS += -flto
