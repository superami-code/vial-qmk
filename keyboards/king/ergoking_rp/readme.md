# ErgoKing Dactyl ErgoDox Clone

Custom Designed Modular Dactyl

Keyboard Maintainer: [Jake](https://github.com/JKing-B16)
Hardware Supported: Pro Micro ATmega32U4 / Elite-C
Hardware Availability: 

Make example for this keyboard (after setting up your build environment):

    make king/ergoking:default
    make flash king/ergoking:default

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

# For Split Keyboards See

https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_split_keyboard
https://github.com/nicinabox/lets-split-guide

# Wiring

1. Need to add 4.7k Pull Up resistors to the trrs module
2. Use SPLIT_HAND_PIN => to set which hand is which

# UDEV RULES

```
export USER_GID=`id -g`; sudo --preserve-env=USER_GID sh -c 'echo "KERNEL==\"hidraw*\", SUBSYSTEM==\"hidraw\", ATTRS{serial}==\"*vial:f64c2b3c*\", MODE=\"0660\", GROUP=\"$USER_GID\", TAG+=\"uaccess\", TAG+=\"udev-acl\"" > /etc/udev/rules.d/99-vial.rules && udevadm control --reload && udevadm trigger'
```
