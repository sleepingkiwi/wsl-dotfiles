# your .bashrc file gets real messy real fast.
# loads of tools add lines or make edits.
# to keep our custom functions neat they all live in .bash_sleepingkiwi
# -
# add the following to your existing .bashrc file to import custom functions!
# -
# source: https://github.com/sleepingkiwi/wsl-dotfiles
# -
# ref: https://unix.stackexchange.com/questions/270833/how-can-i-source-several-files-into-my-bashrc
# ref: https://stackoverflow.com/questions/4952177/include-additional-files-in-bashrc



# include custom functions if they exist
# --------------------------------------------------------------------------------------------------

if [ -f "$HOME/.bash_sleepingkiwi" ]
then
  source "$HOME/.bash_sleepingkiwi"
fi
