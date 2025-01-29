#include "../s21_string.h"
char *s21_strtok(char *str, const char *delim) {
  static char *next_token = S21_NULL;
  char *token_start = S21_NULL;
  if (str || next_token) {
    if (str == S21_NULL) str = next_token;
    while (*str && s21_strchr(delim, *str)) str++;
    if (*str != '\0') {
      token_start = str;
      while (*str && !s21_strchr(delim, *str)) str++;
      if (*str) {
        *str = '\0';
        next_token = str + 1;
      } else
        next_token = S21_NULL;
    } else
      next_token = S21_NULL;
  }
  return token_start;
}
