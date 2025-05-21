VIA_ENABLE = yes
LTO_ENABLE = yes

VIAL_ENABLE = yes

#TAP_DANCE_ENABLE = yes
#CAPS_WORD_ENABLE = yes
WPM_ENABLE = yes

#RGB_MATRIX_ENABLE = yes
#RGB_MATRIX_DRIVER = ws2812
#VIALRGB_ENABLE = yes

#USER=idank
#POINTING_DEVICE=vendor
#POINTING_DEVICE_POSITION=right
#OLED=yes

SERIAL_DRIVER = vendor
#SRC += $(USER_PATH)/idank.c

# Disable things we don't support that take up unnecessary space.
#RGBLIGHT_SUPPORTED = no
#RGB_MATRIX_SUPPORTED = no

ifeq ($(strip $(POINTING_DEVICE_POSITION)), left)
	OPT_DEFS += -DPOINTING_DEVICE_POSITION_LEFT
else ifeq ($(strip $(POINTING_DEVICE_POSITION)), thumb)
	OPT_DEFS += -DPOINTING_DEVICE_POSITION_THUMB
else ifeq ($(strip $(POINTING_DEVICE_POSITION)), middle)
	OPT_DEFS += -DPOINTING_DEVICE_POSITION_MIDDLE
else
	OPT_DEFS += -DPOINTING_DEVICE_POSITION_RIGHT
endif

ifeq ($(strip $(POINTING_DEVICE)), trackball)
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball

	ifeq ($(strip $(TRACKBALL_RGB_RAINBOW)), yes)
		SRC += quantum/color.c $(USER_PATH)/trackball_rgb_rainbow.c
	endif
endif

ifeq ($(strip $(POINTING_DEVICE)), trackpoint)
	PS2_MOUSE_ENABLE = yes
	PS2_ENABLE = yes
	# PS2_DRIVER = busywait
	PS2_DRIVER = interrupt
endif

ifeq ($(strip $(POINTING_DEVICE)), vendor)
	PS2_MOUSE_ENABLE = yes
	PS2_ENABLE = yes
	PS2_DRIVER = vendor
	OPT_DEFS += -DPOINTING_DEVICE_TRACKPOINT_VENDOR
endif

MOUSEKEY_ENABLE = yes

ifeq ($(strip $(OLED)), yes)
	OLED_ENABLE     = yes
	OLED_DRIVER     = ssd1306
else
	OLED_ENABLE     = no
endif
