#!/bin/bash

source info.sh
source color.sh

if [[ $def_bg1 -eq $def_f1 || $def_bg2 -eq $def_f2 ]]; then
  echo "error: font and background colors of column must not match"
elif [[ ! $def_bg1 =~ ^[1-6]$ || ! $def_f1 =~ ^[1-6]$ || ! $def_bg2 =~ ^[1-6]$ || ! $def_f2 =~ ^[1-6]$ ]]; then
  echo "error: colors should be in between 1 and 6"
else
  get_sys_info
fi
