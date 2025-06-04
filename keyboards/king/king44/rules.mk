# v1.0 of the board needs a replacement of the matrix.c in QMK as it require ROWS to be active HIGH
# switching to PNP transistors for the board could resolve this in future versions
SRC += matrix.c
CUSTOM_MATRIX=yes

WPM_ENABLE = yes
SERIAL_DRIVER = vendor

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
	PS2_DRIVER = interrupt
	OPT_DEFS += -DPOINTING_DEVICE_TRACKPOINT
endif

ifeq ($(strip $(POINTING_DEVICE)), busywait)
	PS2_MOUSE_ENABLE = yes
	PS2_ENABLE = yes
	PS2_DRIVER = busywait
	OPT_DEFS += -DPOINTING_DEVICE_BUSYWAIT
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
