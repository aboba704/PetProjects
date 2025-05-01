#!/bin/bash

# Font color
WHITE_f="\033[37m"
RED_f="\033[31m"
GREEN_f="\033[32m"
BLUE_f="\033[34m"
PURPLE_f="\033[35m"
BLACK_f="\033[30m"

# BG color
WHITE_bg="\033[47m"
RED_bg="\033[41m"
GREEN_bg="\033[42m"
BLUE_bg="\033[44m"
PURPLE_bg="\033[45m"
BLACK_bg="\033[40m"

res='\033[0m'

case $1 in
1) bg1=$WHITE_bg ;;
2) bg1=$RED_bg ;;
3) bg1=$GREEN_bg ;;
4) bg1=$BLUE_bg ;;
5) bg1=$PURPLE_bg ;;
6) bg1=$BLACK_bg ;;
esac

case $2 in
1) f1=$WHITE_f ;;
2) f1=$RED_f ;;
3) f1=$GREEN_f ;;
4) f1=$BLUE_f ;;
5) f1=$PURPLE_f ;;
6) f1=$BLACK_f ;;
esac

case $3 in
1) bg2=$WHITE_bg ;;
2) bg2=$RED_bg ;;
3) bg2=$GREEN_bg ;;
4) bg2=$BLUE_bg ;;
5) bg2=$PURPLE_bg ;;
6) bg2=$BLACK_bg ;;
esac

case $4 in
1) f2=$WHITE_f ;;
2) f2=$RED_f ;;
3) f2=$GREEN_f ;;
4) f2=$BLUE_f ;;
5) f2=$PURPLE_f ;;
6) f2=$BLACK_f ;;
esac
