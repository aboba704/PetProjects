# Разбирает шаблон имени на имя и расширение (если это файл).
# Добавляет текущую дату к имени.
function separate_pattern() {
  date=$(date +"%d%m%y")
  pattern=$1 # заданный пользователем шаблон
  result=""  # промежуточный результат в формате az_130225
  type=""    # расширение файла в формате .az
  flag_is_file=0
  point_position=0 # позиция точки в шаблоне для файла

  if [[ $pattern == *"."* ]]; then
    flag_is_file=1
    for ((i = 0; $i < ${#pattern}; i++)); do
      if [[ ${pattern:$i:1} == "." ]]; then
        break
      fi
      ((point_position += 1))
    done
    type=$(echo ${pattern:$point_position})
    pattern=$(echo $pattern | sed "s/$type/""/")
    result=$pattern
    result+="_"
    result+=$date
  else
    result=$pattern
    result+="_"
    result+=$date
  fi
}

# Корректирует имена, чтобы они были не короче 4 символов.
function correct_result() {
  flag=0
  if [[ ${#result} == '8' ]]; then
    a=${result:0:1}
    result=$(echo $result | sed "s/$a/$a$a$a/")
  elif [[ ${#result} == '9' ]]; then
    a=${result:0:1}
    b=${result:1:1}
    result=$(echo $result | sed "s/$a$b/$a$a$b/")
  elif [[ ${#result} -ge '11' ]]; then
    flag=1
  fi
}

function generate_final_name() { # $1-num_folders, $2-sym_folders
  default=$result
  len=$((${#result} + ${#type})) # вычисляет текущую длину имени, включая расширение, если есть
  while [[ $count -lt $1 ]] && [[ $len -lt 255 ]]; do
    for ((i = 0; $i < ${#pattern} && count < $1 && $len < 255; i++)); do # Этот цикл проходит по каждому символу в шаблоне имени (pattern). Он выполняется, пока не пройдены все символы шаблона, не достигнуто нужное количество имен и длина имени не превышает 255 символов.
      if [[ $flag -eq 1 ]]; then
        ((i--))
      else
        symbol="${pattern:$i:1}" # извлечение символа из шаблона
      fi
      result_position=0
      while [[ ${result:$result_position:1} != $symbol ]]; do # Этот цикл ищет позицию символа c в текущем имени (result).
        ((result_position++))
      done
      if [[ $flag -eq 1 ]]; then
        flag=0
      else
        result=$(echo $result | sed "s/$symbol/$symbol$symbol/") # Символ c в текущем имени удваивается с помощью команды sed.
      fi
      len=$((${#result} + ${#type})) # Обновляется длина имени с учетом расширения (если есть).
      final_name=$result$type        # Формируется полное имя, включая расширение (если это файл).
      if [[ "$2" == *"."* ]] && ! [[ "${array_file[@]}" =~ "${final_name}" ]]; then
        array_file[count]=$result$type
        ((count++))
      elif ! [[ "${array_file[@]}" =~ "${final_name}" ]]; then
        array_dir[count]=$result
        ((count++))
      fi
    done
  done
}

function additional_name() { # $1-num_files - count
  if [[ $1 -gt 0 ]]; then
    pattern=$(echo $pattern | rev)
    result=$pattern
    result+="_"
    result+=$date
    correct_result
    generate_final_name $(($count + $1)) $pattern$type
  fi
}
