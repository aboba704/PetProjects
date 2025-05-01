#!/bin/bash

source check.sh
source clean.sh

echo "=== ДО ЗАСОРЕНИЯ ==="
sync
df -h /

check $@

if [[ $var -eq 1 ]]; then
  clean_log
elif [[ $var -eq 2 ]]; then
  clean_time
else
  [[ $var -eq 3 ]]
  clean_mask
fi

echo "===== ПОСЛЕ ОЧИСТКИ ======"
sync
df -h --output=avail / | tail -n 1
