#!/bin/bash

source info.sh

if [ $# -ne 4 ]; then
  echo "error: script must have 4 parameters"
elif [[ $1 -eq $2 || $3 -eq $4 ]]; then
  echo "error: font and background colors of column must not match"
elif [[ ! $1 =~ ^[1-6]$ || ! $2 =~ ^[1-6]$ || ! $3 =~ ^[1-6]$ || ! $4 =~ ^[1-6]$ ]]; then
  echo "error: colors should be in between 1 and 6"
else
  get_sys_info $1 $2 $3 $4
fi
