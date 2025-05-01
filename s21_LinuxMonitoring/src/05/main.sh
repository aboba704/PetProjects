#!/bin/bash

source check.sh

check $@

case $1 in

1) # Все записи, отсортированные по коду ответа
  awk '{print $0}' $PATTERN | sort -nk 9 ;;
2) # Все уникальные IP
  awk '{ print $1 }' $PATTERN | sort -u ;;
3) # Все записи с ошибками (4xx и 5xx)
  awk '$9 ~ /^[45][0-9][0-9]$/ ' $PATTERN ;;
4) # Все уникальные IP, которые встречаются среди ошибочных запросов
  awk '$9 ~ /^[45][0-9][0-9]$/ { print $1 }' $PATTERN | sort -u ;;
esac
