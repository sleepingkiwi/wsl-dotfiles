#!/bin/bash

##
# this file is used to sync changes made to local repos to additional copies in the dropbox
# we don't want/need node_modules and other junk getting in the dropbox so instead we store
# clean backups using this script...
# -
# for full procedure see: https://gist.github.com/sleepingkiwi/0ff90b970d682ea3a7f3e9f2167f3bc5
##

###
# DECLARING VARIABLES
###

# http://www.thegeekstuff.com/2010/06/bash-array-tutorial
# declare an array variable
declare -a array=(
# /s/_dev repos -- Knac
"/s/Dropbox/_knac/_dev-backups/beginning-to-react"
"/s/Dropbox/_knac/_dev-backups/blurn"
"/s/Dropbox/_knac/_dev-backups/blurn-api"
"/s/Dropbox/_knac/_dev-backups/blurn-transactional-emails"
"/s/Dropbox/_knac/_dev-backups/skill-shop-admin"
"/s/Dropbox/_knac/_dev-backups/skillporium--dev"
# /s/_dev/_mampserver (WordPress) repos
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/vital"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/becomethedream"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/didactic"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/feu-et-joie"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/foundation"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/latratus-libro"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/orion-design-database"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/rebus"
"/s/Dropbox/_tedworth/website-dev/_mampserver-repo-backups/silent"
# /s/_dev/stralbery -- nick and al wedding site
"/s/Dropbox/_tedworth/website-dev/_other-dev-backups/stralbery"
# /s/_dev/wsl-dotfiles -- dotfiles for WSL config
"/s/Dropbox/_tedworth/_dotfiles-backups/wsl-dotfiles"
# /s/_dev/wordpress-docker -- docker-compose setup for starting wordpress sites!
"/s/Dropbox/_tedworth/website-dev/_config-and-docker-backups/wordpress-docker"
# /s/_dev/wordREST/wp-content/themes/wordREST -- starter theme for using WP as a CMS for an API
"/s/Dropbox/_tedworth/website-dev/_boilerplate-and-starter-backups/wordREST"
)

# declare an int to track errors
declare -i errors=0

TODAY=`date "+%Y-%m-%d--%H-%M-%S"`


###
# LOOPING THROUGH OUR ARRAY AND PULLING CHANGES
###

# get length of an array
arraylength=${#array[@]}

echo -e "\n\033[0;90m--------------------\033[0m\n\033[0;32m    starting to sync\n\033[0m\033[0;90m${TODAY}\n--------------------\033[0m\n"

# use for loop to read all values and indexes
for (( i=0; i<${arraylength}; i++ ));
do
  if cd ${array[$i]} && git pull; then
    echo -e "\033[0;32m${array[$i]}\033[0m \n  - git pull successful \n\n\033[0;90m---\033[0m\n"
  else
    echo -e "\033[0;31m${array[$i]}\033[0m \n  - git pull failed \n\n\033[0;90m---\033[0m\n"
    ((errors++))
  fi
done


###
# NOTIFYING AND EXITING
###

# cleanly exit (also changes the window name to 'exit')
echo -e "\n\033[0;90m--------------------\033[0m\n\033[0;32m     Error count: $errors\n\033[0m\033[0;90m${TODAY}\n--------------------\033[0m\n"
exit 0
