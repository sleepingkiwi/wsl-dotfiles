# link our custom bits - don't need to check if these exist already
ln -sf ~/.dotfiles/.bash_sleepingkiwi ~/.bash_sleepingkiwi && echo "👻 symlinked ~/.bash_sleepingkiwi"

# for all other files we check that an existing version doesn't already exist
# if it does we make a backup before creating the symlink
# -f checks if file exists and is of type file
# -d checks for directories
# arg $1 directory or file to check for
# arg $2 new file or directory
backup_and_link_file () {
  if [ ! -f $1 ]; then
    echo -e "\n\t$1 doesn't exist."
    ln -sf "$2" "$1" && echo -e "\n👻 new symlink for $1"
  elif [ -h $1 ]; then
    echo -e "\n\t$1 was already symlinked."
    ln -sf "$2" "$1" && echo -e "\n👻 replaced symlink for $1"
  else
    echo -e "\n\t$1 exists as a file."
    mv "$1" "$1".sleepingkiwi.bak && ln -sf "$2" "$1" && echo -e "\n👻 backed up and symlinked $1"
  fi
}

backup_and_link_file "$HOME/.inputrc" "$HOME/.dotfiles/.inputrc"
backup_and_link_file "$HOME/.nanorc" "$HOME/.dotfiles/.nanorc"
