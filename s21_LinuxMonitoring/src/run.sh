docker build -t do4 .

case $1 in
1) docker run --rm -v "$(pwd)/01:/DO4/01" do4 $1 /opt/test 4 az 5 az.az 3kb ;;
2) docker run --rm -v "$(pwd)/02:/DO4/02" do4 $1 az az.az 3Mb ;;
3) docker run --rm -v "$(pwd)/02:/DO4/02" -it do4 $1 ;;
4) docker run --rm -v "$(pwd)/04/logs:/DO4/04/logs" do4 $1 ;;
5) docker run --rm -v "$(pwd)/05/logs:/DO4/05/logs" do4 $1 ;;
6) docker run --rm -it -v "$(pwd)/06:/DO4/06" do4 $1 ;;
*) ;;
esac
