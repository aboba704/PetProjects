#!/bin/bash

source info.sh

info=$(get_sys_info)

read -p "Write data to a file? (Y/N): " choice
if [[ $choice =~ ^[Yy]$ ]]; then
  filename=$(date '+%d_%m_%y_%H_%M_%S').status
  echo "$info" >$filename
  echo "Data saved to a file: $filename"
fi
