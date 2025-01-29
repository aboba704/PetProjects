#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = S21_NULL;
  unsigned char ch = (unsigned char)c;

  while (*str != '\0') {
    if (*str == ch) {
      result = str;
    }
    str++;
  }

  if (*str == ch) {
    result = str;
  }

  return (char *)result;
}