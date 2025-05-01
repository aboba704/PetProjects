#!/bin/bash

source check.sh
source func.sh

check $@

OUTDIR="logs"
mkdir -p "$OUTDIR"

CODES=(200 201 400 401 403 404 500 501 502 503)
METHODS=(GET POST PUT PATCH DELETE)
AGENTS=(
  "Mozilla/5.0 (X11; Linux x86_64)"
  "Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/90.0"
  "Opera/9.80 (Windows NT 6.0) Presto/2.12"
  "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) Safari/605.1.15"
  "Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.0)"
  "Mozilla/5.0 (Windows NT 10.0) Edge/18.19041"
)
PROTO=("HTTP/1.0" "HTTP/1.1" "HTTP/2")
URL=("/google.com" "/edu.21-school.ru" "/ya.ru" "/apple.com")

for ((d = 0; d < 5; d++)); do
  day=$(date -d "-$d day" +%Y-%m-%d)
  logfile="$OUTDIR/log$d.log"
  gen_log_day "$day" "$logfile"
  echo "generated $logfile with $(wc -l <"$logfile") entries"
done

# 200 - OK: запрос успешно обработан
# 201 - Created: ресурс создан
# 400 - Bad Request: некорректный запрос
# 401 - Unauthorized: некорректный запрос
# 403 - Forbidden: доступ запрещён
# 404 - Not Found: ресурс не найден
# 500 - Internal Server Error: внутренняя ошибка сервера
# 501 - Not Implemented: метод не поддерживается
# 502 - Bad Gateway: некорректный ответ от upstream
# 503 - Service Unavailable: служба недоступна
