# Geonix 40 Rev 2

Layout matches planck [layout](http://www.keyboard-layout-editor.com/#/gists/8c8d6f69549e8be3e37c62b79ac65f7f) with a few geonix specific adjustments to the `adjust` layer.

To install the layout: You can just use the [.bin file in this repo](./geonix40_geonix40_sleepingkiwi.bin) to get a via compatible layout with the sleepingkiwi qmk keymap (including the triple bracket tapdances)

you can then see your current keylayout etc. at: https://usevia.app/

---

Board: https://chosfox.com/collections/40-keyboard/products/chosfox-x-masro-geonix-rev-2?variant=45511588839618

These details were put together with much help from: https://github.com/breakds/keymaps/tree/main/geonix_rev2

---

## Option A — VIA (recommended for quick edits)

If the keyboard is running the included sleepingkiwi firmware (or another via compatible one), use the web app:

1. Open **VIA**: https://usevia.app/
2. Enable **Settings → Show Design tab**.
3. Go to **Design** and **Load** the local file: [`geonix_via_design.json`](via/geonix_via_design.json).
4. Switch back to **Configure** and remap keys/layers as needed.

The directory [`via`](via) contains:
- My customized VIA keymap JSON
- The original factory VIA keymap JSON (for reference/backups)

> **Note (hardware mode):** Use a **USB-C ↔ USB-C** cable and make sure the keyboard is in **USB mode** before using VIA.
> **Important (safety key):** Always keep a key that can switch back to **USB mode** (e.g., a `TO_USB`/mode key). If you drop into a wireless mode while editing, VIA (which talks over USB) won’t see the board until you switch back.

---

## Option B — QMK firmware (compile + flash)

You can also build/flash the vendor’s QMK tree
It has a custom qmk build with some extra bits for bluetooth support etc.

> **Vendor tree**: use the **Geonix-supplied** [qmk_firmware](https://drive.google.com/drive/folders/1QNRFeJZBt527T0AZcOdAccgRrbsD4zqa) (not upstream). I store it in dropbox:
> [`Joe > everything > _utilising`](https://www.dropbox.com/scl/fi/7m2qe7f1opbkqiyh2y34v/qmk_firmware_geonix40.zip?rlkey=a0wthagnplx6f5wnmv96q57nm&dl=0)

### Point the QMK CLI at the vendor tree

- unzip the custom qmk firmware for geonix (it's currently quite different to the main qmk repo)
- then:

```bash
qmk qmk config /Users/sleepingkiwi/Desktop/qmk_firmware_geonix40
qmk cd
```

> **Note**: May have to install/upgrade qmk CLI tool and deps via brew - use `qmk setup` to health check it

### Compile (VIA keymap) and flash

Copy the [`sleepingkiwi`](geonix40/keymaps/sleepingkiwi/) dir into the `geonix40/geonix40/keymaps` dir wherever it is that you unzipped the geonix qmk files

```bash
# build the VIA-enabled firmware
qmk compile -kb geonix40/geonix40 -km sleepingkiwi
```

I just ignored the the warnings about LEDs

We now need to flash the bin file into the keyboard. Note that `qmk flash` command won't work because geonix rev 2 comes with a custom bootloader. (see `keyboards/geonix40/geonix40/info.json` line 79)

We should:

1. Enter the bootloader mode by holding the top-left key (Bootmagic) while plugging it in with the USB-C to USB-C cable
2. You will see an USB disk being mounted (mine says 109KB)
3. Copy the generated bin file from the compilation to this disk. The completion of the copy kicks off the flash process.
4. Wait and do nothing until the flash is done. The USB disk will be ejected automatically and the keyboard become usable.

### Troubleshooting

After flashing the VIA keymap firmware to the Geonix40 keyboard, the keyboard exhibits unwanted sleep behavior in Bluetooth mode:
- The keyboard automatically turns off after 3-5 minutes of inactivity
- Keypresses do not wake the keyboard
- The physical power switch must be toggled off and on to restore functionality
- This issue does not occur with the original firmware

#### Solution
Add a periodic reset of the `Usb_Change_Mode_Delay` counter to prevent it from reaching the sleep threshold. This is implemented using the `matrix_scan_user()` callback which runs continuously during the keyboard's main loop.

Please see the updated `keymap.c`  [geonix40/geonix40/keymaps/via/keymap.c](geonix40/keymaps/sleepingkiwi/keymap.c).
