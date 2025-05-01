#!/bin/bash

source check.sh
source script_work.sh
source ../common/make_names.sh
source ../common/create.sh

path=$(find /home \
  -type d \
  -perm /u=w,g=w \
  ! \( -path "*/bin" -o -path "*/bin/*" -o -path "*/sbin" -o -path "*/sbin/*" \))

check $@

if [[ -f Part2.log ]]; then
  rm Part2.log
fi

touch Part2.log
log_name=Part2.log
log_date=$(date +"%d.%m.%y")
log_size_files=$3
log_path=$(pwd)
array_dir=()
array_file=()

start_script
size=$(echo $3 | sed "s/Mb/M/")
path=$(find /home -type d -perm /u=w,g=w ! \( -path "*/bin" -o -path "*/bin/*" -o -path "*/sbin" -o -path "*/sbin/*" \))

count=0
separate_pattern $1
correct_result
generate_final_name 100 $1

count=0
separate_pattern $2
correct_result
suffix_len=${#result}
max_file_name=$((255 - suffix_len)) # Макс. длина имени файла (255 — максимум для файловых систем типа ext4)
generate_final_name $max_file_name $2
additional_name $(($max_file_name - $count))

for i in $path; do
  for ((j = 0; $j < 100; j = $(($j + 1)))); do
    let "count_file=$RANDOM%$max_file_name"
    create_dir $i $count_file 2
  done
done

stop_script
