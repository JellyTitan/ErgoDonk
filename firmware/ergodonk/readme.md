# ergodonk_v2

![ergodonk_v2](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Ryan Neff](https://github.com/JellyTitan)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make ergodonk_v2:default

Flashing example for this keyboard:

    make ergodonk:default:flash
    For EE_HANDS (Extra steps required on ARM @todo maybe pull this?)
    make ergodonk:default:flash:dfu-util-split-left
    make ergodonk:default:flash:dfu-util-split-right


    qmk compile -kb ergodonk_v2 -km default

    c2json (Must run from inside keymap folder)
    `qmk c2json -kb ergodonk -km default keymap.c`
    
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
