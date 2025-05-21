# King44

_King44 is a 3x6+4 split keyboard, with additional 2x mouse switch options_

- Keyboard Maintainer: [@idank](https://github.com/idank)
- Hardware Supported: [spankbd](https://github.com/idank/spankbd)
- Hardware Availability: _[holykeebs](https://holykeebs.com)_

Make example for this keyboard (after setting up your build environment):

    make king/King44:default

Flashing example for this keyboard:

    make king/king44:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard.
- **Physical reset button**: Briefly press the button on the front of the PCB. Double tap for pro micro, 1 second press for Sea Picro / RP2040s.
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.

# Make

```
make \
    king/king44:vial:flash \
    -e POINTING_DEVICE=vendor \
    -e POINTING_DEVICE_POSITION=right \
    -e OLED=yes \
    -j20
```

# -e USER_NAME=king \
