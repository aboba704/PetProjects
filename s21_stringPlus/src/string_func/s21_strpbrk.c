#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *c = S21_NULL;
  for (int i = 0; str1[i] && c == S21_NULL; i++) {
    for (int j = 0; str2[j] && c == S21_NULL; j++) {
      if (str1[i] == str2[j]) {
        c = (char *)str1 + i;
      }
    }
  }
  return c;
}