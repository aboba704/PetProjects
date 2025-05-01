function check() {
  LOG_DIR="/DO4/04/logs"
  PATTERN="$LOG_DIR"/*.log

  if [[ ! -d "$LOG_DIR" ]]; then
    echo "Directory $LOG_DIR not found!" >&2
    exit 1
  fi

  if [[ $# -ne 1 || ! "$1" =~ ^[1-4]$ ]]; then
    echo "Usage: $0 <1|2|3|4>"
    echo " 1 — all entries sorted by status code"
    echo " 2 — all unique client IPs"
    echo " 3 — all error entries (4xx and 5xx)"
    echo " 4 — unique client IPs among errors"
    exit 1
  fi
}
