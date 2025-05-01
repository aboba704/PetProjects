function check() {
  if [[ $# -ne 6 ]]; then
    echo "usage: main.sh <path> <folders_count> <folders_letters> <files_count> <files_letters> <size_kb>"
    exit 1
  elif ! [[ -d $1 ]] || [[ ${1:0:1} != "/" ]]; then
    echo "error: path must exist and be absolute"
    exit 1
  elif ! [[ $2 =~ ^[0-9]+$ ]] || ! [[ $4 =~ ^[0-9]+$ ]]; then
    echo "args 2 & 4 must be positive number"
    exit 1
  elif ! [[ $3 =~ ^[a-zA-Z]{1,7}$ ]] || ! [[ $5 =~ ^[a-zA-Z]{1,7}+([.][a-zA-Z]{1,3})?$ ]]; then
    echo "args 3 & 5 must have letters, max name len - 7, max ext len - 3"
    exit 1
  elif ! [[ $6 =~ ^[1-9][0-9]?[0]?kb$ ]]; then
    echo "file size in Kb up to 100"
    exit 1
  fi
}
