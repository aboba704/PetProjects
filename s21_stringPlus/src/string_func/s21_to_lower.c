#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *dest = S21_NULL;
  if (str != S21_NULL) {
    const char *l = str;
    s21_size_t len = 0;
    while (*l != '\0') {
      len++;
      l++;
    }
    dest = (char *)malloc((len + 1) * sizeof(char));
    char *c = dest;
    while (*str != '\0') {
      if (*str >= 'A' && *str <= 'Z') {
        *c = *str + 32;
      } else {
        *c = *str;
      }
      c++;
      str++;
    }
    *c = '\0';
  }
  return (void *)dest;
}
