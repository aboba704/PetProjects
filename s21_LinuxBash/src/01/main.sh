#!/bin/bash

if [ $# -ne 1 ]; then
  echo "error: script must have one parameter"
elif [[ $1 =~ ^[0-9]+$ ]]; then
  echo "error: parameter must not be a number"
else
  echo "parameter: $1"
fi
