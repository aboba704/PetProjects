function check() {
  if [[ $# -ne 1 ]]; then
    read -p "enter one argument: " var
  else
    var=$1
  fi

  while ! [[ "$var" =~ ^[1-3]$ ]]; do
    read -p "enter number from 1 to 3: " var
  done
}
