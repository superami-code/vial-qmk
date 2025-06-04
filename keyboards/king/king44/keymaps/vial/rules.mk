VIA_ENABLE = yes
LTO_ENABLE = yes

VIAL_ENABLE = yes

HAPTIC_DRIVER = drv2605l
WPM_ENABLE = yes


#POINTING_DEVICE=vendor
#POINTING_DEVICE_POSITION=right

SERIAL_DRIVER = vendor

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

ifeq ($(strip $(SIDE)), left)
	OPT_DEFS += -DSIDE_LEFT
else
	OPT_DEFS += -DSIDE_RIGHT
endif
