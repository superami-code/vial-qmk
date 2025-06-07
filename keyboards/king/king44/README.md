# King44

_King44 is a 3x6+4 split Optical keyboard, with additional 2x mouse switch options_

- Keyboard Maintainer: [@superami-codeCode](https://github.com/superami-code)
- Hardware Supported: [king44](https://github.com/superami-code/King44)

Make example for this keyboard (after setting up your build environment):

```sh
./keybaords/king/king44/make_king44_left.sh
./keybaords/king/king44/make_king44_right.sh
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Special Features

- Keychron Optical switches
  - This necessitates special timings as the IR and PT switches have ramp up times of 10µs each.
  - Also the initial PCB layout uses logic high instead of the standard logic low of QMK
- Haptic Feedback
  - DRV2605L Linear Actuator Haptic Breakout from Pimoroni
  - Being able to feel layer changes and mod keys is really great
- Trackpoint
  - Having a trackpoint directly in the keyboard is wonderful
  - There is even a key (MA_SLS) to switch the trackpoint into a scroll wheel for more controlled scrolling that just middle click
- Auto Mouse Layer
  - Moving the trackpoint activates a mouse layer.
  - This has a definable timeout
  - Stays active if any mouse button is pressed
  - Can be toggled or left via special user keycodes MA_TOG, MA_OFF
- OLED
  - Hardware supports both Nice!Nano and generic OLED SSD1306
- Per Key RGB

## Known Issues

- Per Key RGB
  - Current code only has layer level solid color switching
  - I plan to add some more mapped layer colors to indicate keys and key types in the layers

## Bootloader

Enter the bootloader in 3 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard.
- **Physical reset button**: Briefly press the button on the front of the PCB. Double tap for pro micro, 1 second press for Sea Picro / RP2040s.
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.

## Ideas for the Future

- Improve Timings of IR / PT scanning
