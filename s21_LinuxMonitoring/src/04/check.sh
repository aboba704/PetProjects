function check() {
  if [[ $# -ne 0 ]]; then
    echo "script executes w/o args"
    exit 1
  fi
}
