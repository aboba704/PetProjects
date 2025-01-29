#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *i;
  for (i = (char *)str; *i != c && *i != '\0'; i += 1);
  return (*i == c ? i : S21_NULL);
}