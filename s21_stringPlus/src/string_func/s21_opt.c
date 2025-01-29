#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (*str) {
    length++;
    str++;
  }
  return length;
}

char *s21_strcpy(char *str1, const char *str2) {
  int i = 0;
  while (str2[i] != '\0') {
    str1[i] = str2[i];
    i++;
  }
  str1[i] = '\0';

  return str1;
}

void s21_strcat(char *str2, const char *str1) {
  int length = 0;
  while (str2[length] != '\0') {
    length++;
  }

  int i = 0;
  while (str1[i] != '\0') {
    str2[length + i] = str1[i];
    i++;
  }
  str2[length + i] = '\0';
}

void s21_reverse(char str[], int len) {
  int start, end;
  for (start = 0, end = len - 1; start < end; start++, end--) {
    char temp;
    temp = *(str + start);
    *(str + start) = *(str + end);
    *(str + end) = temp;
  }
}

char *s21_itoa(int num, char *str, int base) {
  int i = 0;
  int isNegative = 0;

  if (num == -2147483648) return "-2147483648";  // for handling INT_MIN

  if (num == 0) {
    str[i] = '0';
    str[i + 1] = '\0';
    return str;
  }

  if (num < 0 && base == 10) {
    isNegative = 1;
    num = -num;
  }

  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
    num = num / base;
  }

  if (isNegative) {
    str[i++] = '-';
  }

  str[i] = '\0';

  s21_reverse(str, i);

  return str;
}

char *s21_itoa_int64(int64_t num, char *str, int base) {
  int i = 0;
  int isNegative = 0;

  if (num == 0) {
    str[i] = '0';
    str[i + 1] = '\0';
    return str;
  }

  if (num < 0 && base == 10) {
    isNegative = 1;
    num = -num;
  }

  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
    num = num / base;
  }

  if (isNegative) {
    str[i++] = '-';
  }

  str[i] = '\0';

  s21_reverse(str, i);

  return str;
}

char *s21_ftoa(double num, char *buffer, int afterpoint) {
  // Handling negative numbers.
  if (num < 0) {
    buffer[0] = '-';
    num = -num;
  }

  // Integer part.
  int int_part = (int)num;
  double float_part = num - int_part;

  // Conversion of the integer part to a string.
  int i = 0;
  if (int_part == 0) {
    buffer[i++] = '0';
  } else {
    while (int_part) {
      buffer[i++] = (int_part % 10) + '0';
      int_part /= 10;
    }
  }
  s21_reverse(buffer, i);
  buffer[i] = '.';  // Adding a decimal point.
  i++;

  // Conversion of the fractional part to a string.
  for (int j = 0; j < afterpoint - 1; j++) {
    float_part *= 10;
    int fractional_part = (int)float_part;
    buffer[i++] = fractional_part + '0';
    float_part -= fractional_part;
  }

  int float_part_1 = (int)(float_part * 100) % 10;
  if (float_part_1 >= 5) {
    float_part = float_part * 10 + 1;
    int fractional_part = (int)(float_part);
    buffer[i++] = fractional_part + '0';

  } else {
    float_part = float_part * 10;
    int fractional_part = (int)float_part;
    buffer[i++] = fractional_part + '0';
  }

  buffer[i] = '\0';
  return buffer;
}

char *s21_itoa_uint64(uint64_t num, char *str, int base) {
  int i = 0;

  if (num == 0) {
    str[i] = '0';
    str[i + 1] = '\0';
    return str;
  }

  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
    num = num / base;
  }

  str[i] = '\0';

  s21_reverse(str, i);

  return str;
}