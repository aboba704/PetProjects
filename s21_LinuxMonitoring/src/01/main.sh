#!/bin/bash

source check.sh
source ../common/create.sh
source ../common/make_names.sh

check $@

if [[ -f Part1.log ]]; then
  rm Part1.log
fi

touch Part1.log

array_dir=()
array_file=()

path=$1
num_folders=$2
sym_folders=$3
num_files=$4
sym_files=$5
log_name=Part1.log
log_date=$(date +%d.%m.%y)
log_size_files=$6
log_path=$(pwd)
size=$(echo $6 | sed "s/kb/K/")

count=0
separate_pattern $sym_folders
correct_result
generate_final_name $num_folders $sym_folders
additional_name $(($num_folders - $count))

count=0
separate_pattern $sym_files
correct_result
generate_final_name $num_files $sym_files
additional_name $(($num_files - $count))

create_dir $path $num_files
