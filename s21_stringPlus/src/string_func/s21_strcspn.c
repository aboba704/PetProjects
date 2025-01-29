#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int flag_stop = 0;
  for (const char *s1 = str1; *s1 != '\0'; s1++) {
    for (const char *s2 = str2; *s2 != '\0'; s2++) {
      if (*s1 == *s2) {
        flag_stop = 1;
      }
    }
    if (!flag_stop) {
      count++;
    }
  }
  return count;
}
