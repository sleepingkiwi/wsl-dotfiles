# Sleepingkiwi's Iris Rev 3 Layout

[layout](http://www.keyboard-layout-editor.com/#/gists/0aa2fb4c3bd91d2dcb4a67c1fe5f9da3)

---

- extra nav layer for media control and arrows on `I`, `J`, `K`, & `L`
  - triggered by holding tab
- triple tap brackets on the bottom row for easy `([{}])`
- adjusted default layout to more closely match my Planck to allow for quicker shifting between the boards

---

__Tap dance__ is enabled in `rules.mk` and a 200ms window is set up in `config.h`
See [docs.qmk.fm/#/feature_tap_dance](https://docs.qmk.fm/#/feature_tap_dance) for details

---

`qmk compile -kb keebio/iris/rev3 -km sleepingkiwi`

to flash (first put iris into boot with button underneath) use QMK Toolbox with `.bin` generated by above command.

You need to flash both sides the first time round and then if you haven't updated QMK you can just flash one side for keymap tweaks

See [https://docs.qmk.fm/#/newbs_flashing](https://docs.qmk.fm/#/newbs_flashing) for details
