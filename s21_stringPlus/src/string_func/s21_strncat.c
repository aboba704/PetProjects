#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t destLength = 0;
  while (dest[destLength] != '\0') destLength++;

  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[destLength + i] = src[i];
  }

  if (n > 0) {
    dest[destLength + i] = '\0';
  }

  return dest;
}