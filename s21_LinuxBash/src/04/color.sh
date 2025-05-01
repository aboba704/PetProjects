#!/bin/bash

source color.conf

DEF='\033[0m'

def_bg1=${column1_background:-1}
def_f1=${column1_font_color:-5}
def_bg2=${column2_background:-5}
def_f2=${column2_font_color:-1}

colors=("white" "red" "green" "blue" "purple" "black")
color_f=("\033[37m" "\033[31m" "\033[32m" "\033[34m" "\033[35m" "\033[30m")
color_b=("\033[47m" "\033[41m" "\033[42m" "\033[44m" "\033[45m" "\033[40m")

bg1=${color_b[$((def_bg1 - 1))]}
f1=${color_f[$((def_f1 - 1))]}
bg2=${color_b[$((def_bg2 - 1))]}
f2=${color_f[$((def_f2 - 1))]}
