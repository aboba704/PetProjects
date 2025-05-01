source ../common/make_names.sh

function clean_log() {
  cd ../02
  paths=$(awk '{print $1}' "Part2.log")
  for path in $paths; do
    rm -rf $path
  done
}

function clean_time() {
  echo "enter date and time to start generating files. example: '2025-01-01 01:01'"
  read start
  check_time $start
  echo "enter the date and time to end generating files. example: '2025-01-01 01:01'"
  read end
  check_time $end

  delete_dir=$(find / -ignore_readdir_race -type d -newermt "$start:00" ! -newermt "$end:59" | grep $(date +"%d%m%y") 2>/dev/null)
  delete_file=$(find / -ignore_readdir_race -type f -newermt "$start:00" ! -newermt "$end:59" | grep $(date +"%d%m%y") 2>/dev/null)

  rm -rf $delete_dir
  rm -rf $delete_file
}

function check_time() {
  str1=$1
  str2=$2
  Date='^[1-9][0-9]{3}-([1][0-2]|[0][0-9])-([3][0-1]|[0-2][0-9])'
  Time='([0-1][0-9]|[2][0-3]):([0-5][0-9])$'

  if ! [[ $1 =~ $Date ]] || [[ $1 =~ $Time ]] || [[ ${#str1} -ne 10 ]] || [[ ${#str2} -ne 5 ]]; then
    echo "check_time error!"
    exit 1
  fi
}

function clean_mask() {
  echo "enter mask, example: az_010101"
  read mask
  check_mask $mask
  # Удаляет все до первого символа подчеркивания, оставляя только часть строки после _
  date="_${mask#*_}"
  # Заменяет первое подчеркивание на *_
  date="${date/_/*_}"
  # Поиска всех файлов на системе, название которых соответствует date
  delete=$(find / -ignore_readdir_race -name "$date" -print0 | xargs -0 echo)

  rm -rf -- $delete
}

function check_mask() {
  if ! [[ $1 =~ ^[a-zA-Z]{1,7}_([3][0-1]|[0-2][0-9])+$|([.][a-zA-Z]{1,3})+$ ]]; then
    echo "enter valid mask"
    exit 1
  fi
}
