# MCU name
#MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
#BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
#SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
#BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
#UNICODE_ENABLE = no         # Unicode
#MIDI_ENABLE = no            # MIDI controls
#BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
#AUDIO_ENABLE = no           # Audio output on port C6

#RAW_ENABLE = yes

# Ergo Dox Specific
#SWAP_HANDS_ENABLE= yes # Allow swapping hands of keyboard
#CUSTOM_MATRIX = lite # Custom matrix file
#SERIAL_LINK_ENABLE = no
#SPLIT_KEYBOARD = yes

SERIAL_DRIVER = vendor

LAYOUTS = ergodox
# SRC += rgb.c
#\
#		qmk_rc.c
# raw_hid.c
#SRC += matrix.c \
#	   led_i2c.c
#QUANTUM_LIB_SRC += i2c_master.c
