#ifndef S21_STRING

#include <inttypes.h>  // int32_t
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)
#if defined(__APPLE__) || defined(__MACH__)
#define ERROR "Unknown error: "
#elif defined(__linux__)
#define ERROR "Unknown error "
#endif

typedef unsigned long s21_size_t;

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

s21_size_t s21_strlen(const char *str);
char *s21_strcpy(char *str1, const char *str2);
void s21_strcat(char *str2, const char *str1);
char *s21_itoa(int num, char *str, int base);
char *s21_itoa_int64(int64_t val, char *ret, int base);
char *s21_itoa_uint64(uint64_t val, char *ret, int base);
void s21_reverse(char str[], int len);
char *s21_ftoa(double num, char *buffer, int afterpoint);

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memset(void *std, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
const char *s21_strerror(int errnum);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
char *s21_strpbrk(const char *str1, const char *str2);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strchr(const char *str, int c);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);

int s21_sprintf(char *str, const char *format, ...);

#endif  // S21_STRING