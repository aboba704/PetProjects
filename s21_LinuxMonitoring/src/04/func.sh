gen_log_day() {
  local day="$1" # формат YYYY-MM-DD
  local file="$2"
  local n=$((RANDOM % 901 + 100)) # 100–1000 записей

  # Стартовая точка времени: начало дня
  local ts_start="${day} 00:00:00"
  local epoch_start=$(date -d "$ts_start" +%s)

  for ((i = 0; i < n; i++)); do
    # Случайный оффсет в пределах дня
    local offs=$((RANDOM % 86400))
    local ts=$(date -d "@$((epoch_start + offs))" +"%d/%b/%Y:%H:%M:%S %z")

    # Случайный IP
    local ip="$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256))"
    local code=${CODES[RANDOM % ${#CODES[@]}]}
    local method=${METHODS[RANDOM % ${#METHODS[@]}]}
    local url=${URL[RANDOM % ${#URL[@]}]}
    local proto="HTTP/1.1"
    local agent=${AGENTS[RANDOM % ${#AGENTS[@]}]}

    local size=$((RANDOM % 5000 + 200))

    printf '%s - - [%s] "%s %s %s" %s %s "-" "%s"\n' \
      "$ip" "$ts" "$method" "$url" "$proto" "$code" "$size" "$agent" >>"$file"
  done
}
