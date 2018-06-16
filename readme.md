# my wip dotfiles for wsl

## installing linux dotfiles

- in WSL bash:
- `$ git clone https://github.com/sleepingkiwi/wsl-dotfiles.git ~/.dotfiles`
- `$ bash ~/.dotfiles/_install.sh`
- `$ cd ~/`
- `$ nano .bashrc`
- paste contents from `.bashrc` in this repo at the bottom of existing file.

## updating dotfiles

- `$ cd ~/.dotfiles`
- `$ git pull`
- `$ bash ~/.dotfiles/_install.sh`

---

## what is

### `.nanorc`

adding syntax highlighting to make quick edits easier

### `.bashrc and .bash_sleepingkiwi`

customising bash, adding aliases, defining colours etc.

all custom stuff is kept in .bash_sleepingkiwi and just imported into .bashrc because tons of other programs want to be editing .bashrc all the time and it gets noisy in there.

### `.inputrc`

customisations to _READLINE_, autocomplete settings mainly.

### `base16.yml`

scheme file for custom [base 16](http://chriskempson.com/projects/base16/) colour scheme.

### `ConEmu.xml`

settings, theme and colours for conemu terminal emulator

#### installing

- easiest option might be just copying file contents over to the settings file at `/mnt/c/Users/`__joe__`/AppData/Roaming/ConEmu.xml`
- symlinking might be risky because ConEmu expects to be able to write back to this file.


### `./rainmeter`

layout and skins for rainmeter

#### installing

- install [rainmeter](https://www.rainmeter.net/)
- these will overwrite existing files:
- `$ cp -rf ~/.dotfiles/rainmeter/skins/sleepingkiwi/ "/mnt/c/Users/`__joe__`/Documents/Rainmeter/Skins/"`
- `$ cp -rf ~/.dotfiles/rainmeter/layout/sleepingkiwi/ "/mnt/c/Users/`__joe__`/AppData/Roaming/Rainmeter/Layouts/"`
- activate the layout from rainmeter settings

### `sleepingkiwi-vscode`

colour theme and syntax highlighting for vs code using sleepingkiwi base16 colours

#### installing

- install [vs code](https://code.visualstudio.com/)
- this will overwrite existing files:
- `$ cp -rf ~/.dotfiles/sleepingkiwi-vscode/ "/mnt/c/Users/`__joe__`/.vscode/extensions/"`
- activate the theme from vs code settings

👻
