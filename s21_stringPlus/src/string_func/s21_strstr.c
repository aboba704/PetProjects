#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *letterPointer = S21_NULL;

  for (int i = 0; haystack[i] != '\0'; i++) {
    if (haystack[i] == needle[0]) {
      int j = 0;
      while (needle[j] != '\0' && haystack[i + j] != '\0' &&
             haystack[i + j] == needle[j]) {
        j++;
      }
      if (needle[j] == '\0') {
        letterPointer = (char *)&haystack[i];
      }
    }
  }

  if (*needle == '\0') {
    letterPointer = (char *)haystack;
  }

  return letterPointer;
}