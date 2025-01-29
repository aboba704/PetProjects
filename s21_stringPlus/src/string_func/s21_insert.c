#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == NULL || str == NULL) return S21_NULL;

  s21_size_t srclen = s21_strlen(src);
  s21_size_t strlen = s21_strlen(str);

  if (start_index > srclen) {
    return S21_NULL;
  }

  char *newStr = calloc((srclen + strlen + 1), sizeof(char));
  if (newStr != NULL) {
    s21_memcpy(newStr, src, start_index);
    s21_memcpy(newStr + start_index, str, strlen);
    s21_memcpy(newStr + start_index + strlen, src + start_index,
               srclen - start_index + 1);
  }

  return newStr;
}