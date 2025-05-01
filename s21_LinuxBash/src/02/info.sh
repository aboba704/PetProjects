#!/bin/bash

get_sys_info() {
  echo "HOSTNAME = $(hostname)
TIMEZONE = "$(timedatectl | grep 'Time zone' | awk '{print $3, $4, $5}')"
USER = $(whoami)
OS = $(lsb_release -ds)
DATE = $(date '+%d %B %y %H:%M:%S')
UPTIME = $(uptime -p)
UPTIME_SEC = $(cat /proc/uptime | awk '{print int($1)}')
IP = $(ip a | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}' | cut -d/ -f1 | head -n 1)
MASK = $(ip a | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}' | cut -d/ -f2 | head -n 1)
GATEWAY = $(ip r | grep default | awk '{print $3}')
RAM_TOTAL = $(free -m | grep Mem | awk '{printf "%.3f GB", $2/1024}')
RAM_USED = $(free -m | grep Mem | awk '{printf "%.3f GB", $3/1024}')
RAM_FREE = $(free -m | grep Mem | awk '{printf "%.3f GB", $4/1024}')
SPACE_ROOT = $(df / | grep / | awk '{printf "%.2f MB", $2/1024}')
SPACE_ROOT_USED = $(df / | grep / | awk '{printf "%.2f MB", $3/1024}')
SPACE_ROOT_FREE = $(df / | grep / | awk '{printf "%.2f MB", $4/1024}')"
}
