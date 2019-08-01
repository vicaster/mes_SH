########################COLORS########################

DEFAULT="\033[0m"
HIGHLIGHT="\033[1m"
UNDERLINE="\033[4m"
BLINK="\033[5m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PURPLE="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

######################################################

cp -r push.sh ~
echo "alias push='sh ~/push.sh'" >> ~/.zshrc
echo "${GREEN}

           PUSH INSTALLED
${PURPLE}
Make \"exit\" on your shell to open an other shell.
And it's done you can use \"push\" to use the script.
Have fun.


                                             ${DEFAULT}by: ${RED}Vicaster
"

