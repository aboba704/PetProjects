#!/bin/bash

source color.sh

get_sys_info() {
  echo -e "${bg1}${f1}HOSTNAME =${bg2}${f2} $(hostname)${DEF}
${bg1}${f1}TIMEZONE =${bg2}${f2} "$(timedatectl | grep 'Time zone' | awk '{print $3, $4, $5}')"${DEF}
${bg1}${f1}USER =${bg2}${f2} $(whoami)${DEF}
${bg1}${f1}OS =${bg2}${f2} $(lsb_release -ds)${DEF}
${bg1}${f1}DATE =${bg2}${f2} $(date '+%d %B %y %H:%M:%S')${DEF}
${bg1}${f1}UPTIME =${bg2}${f2} $(uptime -p)${DEF}
${bg1}${f1}UPTIME_SEC =${bg2} ${f2}$(cat /proc/uptime | awk '{print int($1)}')${DEF}
${bg1}${f1}IP =${bg2}${f2} $(ip a | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}' | cut -d/ -f1 | head -n 1)${DEF}
${bg1}${f1}MASK =${bg2}${f2} $(ip a | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}' | cut -d/ -f2 | head -n 1)${DEF}
${bg1}${f1}GATEWAY =${bg2}${f2} $(ip r | grep default | awk '{print $3}')${DEF}
${bg1}${f1}RAM_TOTAL =${bg2}${f2} $(free -m | grep Mem | awk '{printf "%.3f GB", $2/1024}')${DEF}
${bg1}${f1}RAM_USED =${bg2}${f2} $(free -m | grep Mem | awk '{printf "%.3f GB", $3/1024}')${DEF}
${bg1}${f1}RAM_FREE =${bg2}${f2} $(free -m | grep Mem | awk '{printf "%.3f GB", $4/1024}')${DEF}
${bg1}${f1}SPACE_ROOT =${bg2}${f2} $(df / | grep / | awk '{printf "%.2f MB", $2/1024}')${DEF}
${bg1}${f1}SPACE_ROOT_USED =${bg2}${f2} $(df / | grep / | awk '{printf "%.2f MB", $3/1024}')${DEF}
${bg1}${f1}SPACE_ROOT_FREE =${bg2}${f2} $(df / | grep / | awk '{printf "%.2f MB", $4/1024}')${DEF}"
}
