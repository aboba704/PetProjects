#!/bin/bash

start_time=$(date +%s.%N)

if [ $# -ne 1 ]; then
  echo "error: script must have one parameter"
elif [[ $1 =~ ^[0-9]+$ ]]; then
  echo "error: parameter must be a string"
elif [[ ${1: -1} != "/" ]]; then
  echo "path must end with '/'"
elif [[ ! -d $1 ]]; then
  echo "error: must be an actual path"
else
  dir=$1

  folder_count=$(find "$dir" -type d | wc -l)
  top_5_folders=$(du -h --max-depth=1 "$dir" 2>/dev/null | sort -hr | head -n 5)
  file_count=$(find "$dir" -type f | wc -l)
  conf_count=$(find "$dir" -type f -name "*.conf" | wc -l)
  txt_count=$(find "$dir" -type f -exec file --mime-type {} + | grep 'text/' | wc -l)
  exec_count=$(find "$dir" -type f -executable | wc -l)
  log_count=$(find "$dir" -type f -name "*.log" | wc -l)
  arch_count=$(find "$dir" -type f \( -name "*.tar" -o -name "*.gz" -o -name "*.zip" -o -name "*.rar" \) | wc -l)
  symlink_count=$(find "$dir" -type l | wc -l)
  top_10_files=$(
    find "$dir" -type f -exec du -h {} + 2</dev/null | sort -hr | head -n 10 |
      awk '{print NR " - " $2 ", " $1 ", " (match ($2, /\.[^.]*$/) ? substr($2, RSTART+1) : "unknown") }'
  )
  top_10_exec=$(
    find "$dir" -type f -executable -exec du -h {} + 2</dev/null | sort -hr | head -n 10 |
      awk '{cmd = "md5sum \"" $2 "\" | awk \"{print \$1}\""; cmd | getline hash; close(cmd); print NR " - " $2 ", " $1 ", " hash }'
  )

  echo "Total number of folders (including all nested ones) = $folder_count
TOP 5 folders of maximum size arranged in descending order (path and size):
$top_5_folders 
Total number of files = $file_count
Number of:  
Configuration files (with the .conf extension) = $conf_count
Text files = $txt_count
Executable files = $exec_count
Log files (with the extension .log) = $log_count  
Archive files = $arch_count
Symbolic links = $symlink_count
TOP 10 files of maximum size arranged in descending order (path, size and type):  
$top_10_files
TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):  
$top_10_exec"
  end_time=$(date +%s.%N)
  echo "Script execution time (in seconds) = $(echo "$end_time - $start_time" | bc)"
fi
