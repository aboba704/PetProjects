#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *ptr = (const unsigned char *)str;
  unsigned char ch = (unsigned char)c;
  const unsigned char *result = S21_NULL;

  for (s21_size_t i = 0; i < n; i++) {
    if (ptr[i] == ch) {
      result = (ptr + i);
      break;
    }
  }
  return (void *)result;
}