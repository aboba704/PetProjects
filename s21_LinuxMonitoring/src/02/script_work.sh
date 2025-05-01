function start_script {
  start_diff=$(date +'%s%N')
  start_log=$(date +'%Y-%m-%d %H:%M:%S')
  echo "Время начала работы скрипта: $start_log" >>$log_path/$log_name
  echo "Время начала работы скрипта: $start_log"
}

function stop_script {
  end_diff=$(date +'%s%N')
  end_log=$(date +'%Y-%m-%d %H:%M:%S')
  echo "Время окончания работы скрипта: $end_log" >>$log_path/$log_name
  echo "Время окончания работы скрипта: $end_log"
  DIFF=$((($end_diff - $start_diff) / 100000000))
  echo "Общее время работы скрипта: $(($DIFF / 10)).$(($DIFF % 10))" >>$log_path/$log_name
  echo "Общее время работы скрипта: $(($DIFF / 10)).$(($DIFF % 10))"
}
