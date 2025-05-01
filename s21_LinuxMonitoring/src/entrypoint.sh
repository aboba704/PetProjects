#!/bin/bash

case $1 in
1)
  shift
  mkdir /opt/test
  cd /DO4/01 && bash main.sh "$@"
  ;;
2)
  shift
  cd /DO4/02 && bash main.sh "$@"
  ;;
3)
  shift
  echo "==== ИСХОДНОЕ СОСТОЯНИЕ ====="
  sync
  df -h --output=avail / | tail -n 1
  cd /DO4/02 && bash main.sh az az.az 5Mb
  cd /DO4/03 && bash main.sh "$@"
  ;;
4)
  shift
  cd /DO4/04 && bash main.sh "$@"
  ;;
5)
  shift
  cd /DO4/04 && bash main.sh && cd /DO4/05
  mkdir -p logs && touch logs/{1..4}.log
  bash main.sh 1 >logs/1.log
  bash main.sh 2 >logs/2.log
  bash main.sh 3 >logs/3.log
  bash main.sh 4 >logs/4.log
  ;;
6)
  shift
  cd /DO4/04 && bash main.sh
  cat logs/*.log >/DO4/06/access.log
  cd /DO4/06
  goaccess access.log -o report.html --log-format=COMBINED --real-time-html
  ;;
esac
