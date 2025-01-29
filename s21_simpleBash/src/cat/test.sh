T0="test/test0.txt"
T1="test/test1.txt"
T2="test/test2.txt"
T3="test/test3.txt"
T4="test/bytes.txt"
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color
SUCC_RES="Files s21_cat.txt and cat.txt are identical"

FILES_ARRAY=($T0 $T1 $T2 $T3)
TEST_ARRAY1=(-b -e -n -s -t -v)
TEST_ARRAY2=(-be -bn -bs -bt -bv -eb -en -es -et -ev -nb -ne -ns -nt -nv -sb -se -sn -st -sv -tb -te -tn -ts -tv -vb -ve -vn -vs -vt)
TEST_ARRAY3=(-bnestv)
TEST_ARRAY4=(--number-nonblank -E --number --number --squeeze-blank -T)

FAILS=0
SUCCESS=0
run_test() {
  local TEST=$1

  rm -rf cat.txt s21_cat.txt

  cat ${TEST} "${FILES_ARRAY[@]}" &>cat.txt
  ./s21_cat ${TEST} "${FILES_ARRAY[@]}" &>s21_cat.txt

  DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
  if [ "$DIFF_RES" == "$SUCC_RES" ]; then
    printf "cat $TEST ${FILES_ARRAY[@]} ${GREEN}SUCCESS${NC}\n"
    ((SUCCESS++))
  else
    printf "cat $TEST ${FILES_ARRAY[@]} ${RED}FAIL${NC}\n"
    diff -n s21_cat.txt cat.txt
    ((FAILS++))
  fi
}

## 1
printf "${BLUE}Testing with one parameter:${NC}\n"
for TEST in "${TEST_ARRAY1[@]}"; do
  run_test "$TEST"
done

## 2
printf "\n${BLUE}Testing with two parameters:${NC}\n"
for TEST in "${TEST_ARRAY2[@]}"; do
  run_test "$TEST"
done

#  ALL
printf "\n${BLUE}Testing with all parameters:${NC}\n"
for TEST in "${TEST_ARRAY3[@]}"; do
  run_test "$TEST"
done

# GNU
printf "\n${BLUE}GNU testing:${NC}\n"
G1="--number-nonblank"
G2="-E"
G3="--number"
G4="--squeeze-blank"
G5="-T"

rm -rf cat.txt s21_cat.txt
cat -b "${FILES_ARRAY[@]}" &>cat.txt
./s21_cat $G1 "${FILES_ARRAY[@]}" &>s21_cat.txt
DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF_RES" == "$SUCC_RES" ]; then
  printf "cat $G1 ${FILES_ARRAY[@]} ${GREEN}SUCCESS${NC}\n"
  ((SUCCESS++))
else
  printf "cat $G1 ${FILES_ARRAY[@]} ${RED}FAIL${NC}\n"
  diff -n s21_cat.txt cat.txt
  ((FAILS++))
fi

rm -rf cat.txt s21_cat.txt
cat -n "${FILES_ARRAY[@]}" &>cat.txt
./s21_cat $G3 "${FILES_ARRAY[@]}" &>s21_cat.txt
DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF_RES" == "$SUCC_RES" ]; then
  printf "cat $G3 ${FILES_ARRAY[@]} ${GREEN}SUCCESS${NC}\n"
  ((SUCCESS++))
else
  printf "cat $G3 ${FILES_ARRAY[@]} ${RED}FAIL${NC}\n"
  diff -n s21_cat.txt cat.txt
  ((FAILS++))
fi

rm -rf cat.txt s21_cat.txt
cat -s "${FILES_ARRAY[@]}" &>cat.txt
./s21_cat $G4 "${FILES_ARRAY[@]}" &>s21_cat.txt
DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF_RES" == "$SUCC_RES" ]; then
  printf "cat $G4 ${FILES_ARRAY[@]} ${GREEN}SUCCESS${NC}\n"
  ((SUCCESS++))
else
  printf "cat $G4 ${FILES_ARRAY[@]} ${RED}FAIL${NC}\n"
  diff -n s21_cat.txt cat.txt
  ((FAILS++))
fi
rm -rf cat.txt s21_cat.txt

echo "\n${BLUE}Results:${NC}"
echo "SUCCESS: $SUCCESS"
echo "FAIL: $FAILS"
