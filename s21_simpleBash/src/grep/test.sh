COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color
TEST_FILE1="test/test1.txt"
TEST_FILE2="test/test2.txt"
PATTERN_FILE="test/reg_exmpl.txt"
GREP_FILE="./s21_grep"
arguments=(-i -v -c -l -n -h -o -s)

TEST1="cat $TEST_FILE1"
echo "${BLUE}Testing without parameters:${NC}"
$GREP_FILE $TEST1 &>s21_grep.txt
grep $TEST1 &>grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST1 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST1 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi

TEST2="-e cat $TEST_FILE1"
echo "\n${BLUE}Testing -e:${NC}"
$GREP_FILE $TEST2 &>s21_grep.txt
grep $TEST2 &>grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST2 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST2 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi

TEST3="-e cat -e grep $TEST_FILE1"
#echo "GREP TEST 3: $TEST3"
$GREP_FILE $TEST3 &>s21_grep.txt
grep $TEST3 &>grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST3 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST3 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi

TEST4="-e cat -e grep $TEST_FILE1 $TEST_FILE2"
#echo "GREP TEST 4: $TEST4"
$GREP_FILE $TEST4 &>s21_grep.txt
grep $TEST4 &>grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST4 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST4 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi

echo "\n${BLUE}Testing with one flag:${NC}"
for var in ${arguments[@]}; do
    TEST5="$var cat $TEST_FILE1"
    #echo "GREP TEST 5 $TEST5"
    $GREP_FILE $TEST5 &>s21_grep.txt
    grep $TEST5 &>grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
        echo "$TEST5 - ${GREEN}SUCCESS${NC}"
        ((COUNTER_SUCCESS++))
    else
        echo "$TEST5 - ${RED}FAIL${NC}"
        ((COUNTER_FAIL++))
    fi
done

TEST6="-e cat -e grep $TEST_FILE1 $TEST_FILE2 ../nofile.txt"
echo "\n${BLUE}Testing with nonexisting file:${NC}"
# Send both stdout and stderr to out.log
# myprogram &> out.log
$GREP_FILE $TEST6 &>s21_grep.txt
grep $TEST6 &>grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST6 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST6 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi

TEST7="-e cat -e grep -g $TEST_FILE1 $TEST_FILE2"
echo "\n${BLUE}Testing with wrong flag:${NC}"
# Log output, hide errors.
# myprogram > out.log 2> /dev/null
rm grep.txt s21_grep.txt
$GREP_FILE $TEST7 >s21_grep.txt 2>/dev/null
grep $TEST7 >grep.txt 2>/dev/null
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST7 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST7 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi

TEST8="-f $PATTERN_FILE $TEST_FILE1 $TEST_FILE2"
echo "\n${BLUE}Testing -f flag with pattern:${NC}"
$GREP_FILE $TEST8 &>s21_grep.txt
grep $TEST8 &>grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST8 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST8 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi

echo "\n${BLUE}Testing -e flag with other flags:${NC}"
for var in ${arguments[@]}; do
    TEST9="$var -e less -e grep $TEST_FILE1 $TEST_FILE2"
    $GREP_FILE $TEST9 &>s21_grep.txt
    grep $TEST9 &>grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
        echo "$TEST9 - ${GREEN}SUCCESS${NC}"
        ((COUNTER_SUCCESS++))
    else
        echo "$TEST9 - ${RED}FAIL${NC}"
        ((COUNTER_FAIL++))
    fi
done

TEST10="less -l $TEST_FILE1 $TEST_FILE2"
#echo "GREP TEST 10: $TEST10"
$GREP_FILE $TEST10 &>s21_grep.txt
grep $TEST10 &>grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
    echo "$TEST10 - ${GREEN}SUCCESS${NC}"
    ((COUNTER_SUCCESS++))
else
    echo "$TEST10 - ${RED}FAIL${NC}"
    ((COUNTER_FAIL++))
fi
rm s21_grep.txt grep.txt

echo "\n${BLUE}Results:${NC}"
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
