#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *firstStr = (const unsigned char *)str1;
  const unsigned char *secStr = (const unsigned char *)str2;

  for (s21_size_t i = 0; i < n; i++) {
    if (firstStr[i] != secStr[i]) {
      return (int)(firstStr[i] - secStr[i]);
    }
  }

  return 0;
}
