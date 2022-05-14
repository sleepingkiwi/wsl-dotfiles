#!/bin/bash

##
# this file creates a full archive of ~/dev
# -
# if you just need one directory archived you should do that manually!
##

TODAY=`date "+%Y-%m-%d--%H-%M-%S"`

echo -e "\n\033[0;90m--------------------\033[0m\n\033[0;32m👻 starting to archive ~/dev\n\033[0m\033[0;90m${TODAY}\n--------------------\033[0m\n"

# remove previous backup if it exists
\rm /home/sleepingkiwi/dev.tar.gz

# archive and compress ~/dev
# ignore node_modules
tar -zcvf /home/sleepingkiwi/dev.tar.gz --exclude "node_modules" /home/sleepingkiwi/dev

# archive complete - notify and move
echo -e "\n\033[0;90m--------------------\033[0m\n\033[0;32m👻 ~/dev was archived and compressed. Moving to /s/Dropbox/_sleepingkiwi/_dev-backups/ubuntu-dev/dev--${TODAY}.tar.gz\n\033[0m\033[0;90m--------------------\033[0m\n"

# move archive into Dropbox

mv /home/sleepingkiwi/dev.tar.gz /s/Dropbox/_sleepingkiwi/_dev-backups/ubuntu-dev/dev--${TODAY}.tar.gz

# cleanly exit
FILE=/s/Dropbox/_sleepingkiwi/_dev-backups/ubuntu-dev/dev--${TODAY}.tar.gz
if [ ! -e "$FILE" ]; then
    echo -e "\n\033[0;90m--------------------\033[0m\n\033[0;31m👻 cannot find the file /home/sleepingkiwi/dev.tar.gz /s/Dropbox/_sleepingkiwi/_dev-backups/ubuntu-dev/dev--${TODAY}.tar.gz - something's gone wrong...\n\033[0m\033[0;90m--------------------\033[0m\n"
else
    echo -e "\n\033[0;90m--------------------\033[0m\n\033[0;32m👻 it has been done.\n\033[0m\033[0;90m--------------------\033[0m\n"
fi
exit 0
