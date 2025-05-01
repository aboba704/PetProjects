# Создает папки на основе имен из массива array_dir.
# Для каждой созданной папки вызывает create_file для создания файлов внутри этой папки.
function create_dir() { # $1 - path $2 - count_file
	for i in ${array_dir[@]}; do
		cd $1
		mkdir -p $i
		echo "$1/$i $log_date" >>$log_path/$log_name
		path2=$(pwd)/$i
		create_file $path2 $2 $3
	done
}

# Создает файлы на основе имен из массива array_file.
# Проверяет свободное место на диске. Если свободного места меньше 1 Гб, скрипт завершает работу.
# Использует команду fallocate для создания файлов определенного размера.
function create_file() { # $1 - path $2 - max_num_files
	cd $1
	# Цикл выполняется, пока не будет создано нужное количество файлов ($2) или не будут исчерпаны все имена из массива array_file.
	for ((j = 0; $j < $2 && $j < ${#array_file[*]}; j++)); do
		sync
		avail=$(df --output=avail / | tail -n1)
		if ((avail <= 1024 * 1024)); then
			# echo "Out of memory, 1G left"
			if [[ "$3" -eq "2" ]]; then
				stop_script
			fi
			exit 1
		else
			touch ${array_file[j]}
			fallocate -l $size ${array_file[j]}
			echo "$1/${array_file[j]} $log_date $log_size_files" >>$log_path/$log_name
		fi
	done
}
