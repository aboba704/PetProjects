#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) return S21_NULL;

  const char *start = src;
  while (*start != '\0' && s21_strpbrk(start, trim_chars) == start) {
    start++;
  }

  const char *end = src + s21_strlen(src) - 1;
  while (end >= start && s21_strpbrk(end, trim_chars) == end) {
    end--;
  }
  s21_size_t trimLength = end - start + 1;
  char *trimStr = calloc(trimLength + 1, sizeof(char));
  int flag = 0;
  if (trimStr == NULL) {
    flag = 1;
  } else {
    s21_strncpy(trimStr, start, trimLength);
    trimStr[trimLength] = '\0';
  }
  return flag == 1 ? S21_NULL : trimStr;
}