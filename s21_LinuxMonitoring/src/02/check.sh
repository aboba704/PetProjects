function check() {
  if [[ $# -ne 3 ]]; then
    echo "usage: <> <> <>"
    exit 1
  elif ! [[ $3 =~ ^[1-9][0-9]?[0]?Mb$ ]]; then
    echo "file size in Mbs - up to 100. example - 3Mb"
    exit 1
  elif ! [[ $1 =~ ^[a-zA-Z]{1,7}$ ]] || ! [[ $2 =~ ^[a-zA-Z]{1,7}+([.][a-zA-Z]{1,3})?$ ]]; then
    echo "args 3 & 5 must be a words, max len - 7, max ext - 3"
    exit 1
  fi
}
