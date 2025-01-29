#pragma once

#include "../s21_string.h"

struct flags {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  int precision;
  int is_precision_set;
  int width;
  char length;
  char specifier;
};

int s21_sprintf(char *str, const char *format, ...);

const char *get_flags(const char *format, struct flags *f);
const char *get_width(const char *format, struct flags *f);
const char *get_precision(const char *format, struct flags *f);
const char *get_length(const char *format, struct flags *f);

int s21_parse_c(char **str, struct flags f, va_list *va);
int s21_parse_d(char **str, struct flags f, va_list *va);
int s21_parse_f(char **str, struct flags f, va_list *va);
int s21_parse_s(char **str, struct flags f, va_list *va);
int s21_parse_u(char **str, struct flags f, va_list *va);

void format_flags(char *buf, struct flags f);
void format_precision(char *buf, struct flags f);