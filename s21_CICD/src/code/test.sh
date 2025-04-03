#!/bin/bash

PASSED=0
FAILS=0

# Функция для проверки вывода
assert_output() {
  expected="$1"
  input="$2"
  actual=$(build/DO $input 2>&1)

  if [ "$actual" = "$expected" ]; then
    echo "PASSED: input=$input -> output='$actual'"
    ((PASSED++))
  else
    echo "FAILED: input=$input Expected: '$expected' Got: '$actual'"
    ((FAILS++))
  fi
}

# Тест 1: Проверка корректных значений (1-6)
echo "--- Тест 1: Корректные значения ---"
assert_output "Learning to Linux" "1"
assert_output "Learning to work with Network" "2"
assert_output "Learning to Monitoring" "3"
assert_output "Learning to extra Monitoring" "4"
assert_output "Learning to Docker" "5"
assert_output "Learning to CI/CD" "6"

# Тест 2: Неправильное количество аргументов
echo "--- Тест 2: Неправильное кол-во аргументов ---"
assert_output "Bad number!" "9"
assert_output "Bad number of arguments!" "1 4 2"

# Тест 3: Некорректные числовые значения
echo "--- Тест 3: Некорректные числа ---"
assert_output "Bad number!" "0"
assert_output "Bad number!" "7"
assert_output "Bad number!" "-1"

# Тест 4: Нечисловые входные данные
echo "--- Тест 4: Нечисловые данные ---"
assert_output "Bad number!" "abc"

echo "--- Тесты пройдены: --- "
echo "PASSED: $PASSED"
echo "FAILED: $FAILS"
if [ "$FAILS" != 0 ]; then exit 1; fi
