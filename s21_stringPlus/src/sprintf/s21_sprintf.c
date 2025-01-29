#include "s21_sprintf.h"

#include <ctype.h>  // isdigit

// Returns the number of characters actually stored in the array.
int s21_sprintf(char *str, const char *format, ...) {
  struct flags fl = {0};
  va_list input;            // Initialize the list, naming it input.
  va_start(input, format);  // Starting (after the format argument)
  const char *start = str;
  int val = 0;
  while (*format) {
    if (*format != '%') {
      s21_memset(str++, *(format++), 1);  // Copy the string up to %
      continue;
    } else {
      ++format;
      s21_memset(&fl, 0, sizeof(struct flags));  // Reset the flags.
    }

    format = get_flags(format, &fl);
    format = get_width(format, &fl);
    format = get_precision(format, &fl);
    format = get_length(format, &fl);

    fl.specifier = *format;

    switch (*format++) {
      case 'c':
        s21_parse_c(&str, fl, &input);
        break;
      case 'd':
        s21_parse_d(&str, fl, &input);
        break;
      case 'f':
        s21_parse_f(&str, fl, &input);
        break;
      case 's':
        s21_parse_s(&str, fl, &input);
        break;
      case 'u':
        s21_parse_u(&str, fl, &input);
        break;
      case '%':
        s21_memset(str++, '%', 1);
        break;
      default:
#if defined(__MACH__) || defined(__APPLE__)
        val = 0;
#elif defined(__linux__)
        val = -1;
#endif
        break;
    }
  }
  s21_memset(str, 0, 1);
  va_end(input);
  if (!val) {
    val = s21_strlen(start);
  }

  return val;
}

const char *get_flags(const char *format, struct flags *f) {  // флаги
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '-':
        f->minus = true;
        break;
      case '+':
        f->plus = true;
        break;
      case ' ':
        f->space = true;
        break;
      default:
        break;
    }
    ++format;
  }
  return format;
}

const char *get_width(const char *format, struct flags *f) {
  if (isdigit(*format)) {
    char tmp[BUFSIZ] = {0};
    for (int i = 0; isdigit(*format); ++i, ++format) tmp[i] = *format;
    f->width = atoi(tmp);
  }
  return format;
}

const char *get_precision(const char *format, struct flags *f) {
  if (*format == '.') {
    f->is_precision_set = true;
    format++;
  }
  if (isdigit(*format)) {
    char tmp[BUFSIZ] = {0};
    for (int i = 0; isdigit(*format); i++, format++) tmp[i] = *format;
    f->precision = atoi(tmp);
  }
  return format;
}

const char *get_length(const char *format, struct flags *f) {  // length
  switch (*format) {
    case 'h':
      f->length = 'h';
      ++format;
      break;
    case 'l':
      f->length = 'l';
      ++format;
      break;
      // case 'L':
      //   f->length = 'L';
      //   ++format;
      //   break;
  }
  return format;
}

int s21_parse_c(char **str, struct flags f, va_list *va) {
  char p[50] = {'\0'};
  if (f.length == 'l') {
    wchar_t w_c = va_arg(*va, wchar_t);
    char tmp[50] = {'\0'};
    // Create an array for storing a wide character.
    const wchar_t w_char[] = {w_c, L'\0'};
    // Convert the wide character to a multibyte string.
    size_t len = wcstombs(tmp, w_char, sizeof(tmp));
    if (len == (size_t)-1) {
      // Error handling for conversion
      return -1;  // or another value indicating an error.
    }

    if (!f.minus && f.width) {
      for (size_t i = 0; i < (size_t)f.width - len; i++) p[i] = ' ';
      s21_strcat(p, tmp);
    } else if (f.width) {
      s21_strcpy(p, tmp);
      for (size_t i = s21_strlen(p); i < (size_t)f.width; i++) p[i] = ' ';
    } else {
      s21_strcpy(p, tmp);
    }
  } else {
    char c = va_arg(*va, int);
    if (!f.minus && f.width) {
      for (size_t i = 0; i < (size_t)f.width - 1; i++) p[i] = ' ';
      p[f.width - 1] = c;  // last symbol
    } else if (f.width) {
      p[0] = c;
      for (size_t i = 1; i < (size_t)f.width; i++) p[i] = ' ';
    } else {
      p[0] = c;
    }
  }
  p[s21_strlen(p)] = '\0';  // Make sure that the string ends.
  s21_memcpy((*str), p, s21_strlen(p) + 1);
  (*str) += s21_strlen(p);
  return s21_strlen(p);
}

int s21_parse_d(char **str, struct flags f, va_list *va) {
  char temp[1024];
  int64_t d = va_arg(*va, int64_t);  // extract the variable.
  switch (f.length) {
    case 0:
      d = (int32_t)d;
      break;
    case 'h':
      d = (int16_t)d;
      break;
  }
  char *p = s21_itoa_int64(d, temp, 10);  // int to str

  format_precision(p, f);
  format_flags(p, f);

  while (*p) {
    s21_memset((*str)++, *p, 1);  // Filling the buffer.
    ++p;
  }
  return s21_strlen(temp);
}

int s21_parse_f(char **str, struct flags f, va_list *va) {
  char temp[1024] = {'\0'}, *p;
  double val = va_arg(*va, double);

  if (!f.is_precision_set) f.precision = 6;

  p = s21_ftoa(val, temp, f.precision);  // Processing float precision.
  const char *ptr = s21_strchr(p, '.');
  p[ptr - p + f.precision + 1] = '\0';

  format_flags(p, f);

  while (*p) {
    s21_memset((*str)++, *p, 1);  // Filling the buffer.
    ++p;
  }
  return s21_strlen(temp);
}

int s21_parse_s(char **str, struct flags f, va_list *va) {
  char *s = va_arg(*va, char *);
  char tmp[8192] = {'\0'};
  s21_strcpy(tmp, s);

  // Considering precision.
  if (f.is_precision_set && f.precision < (int)s21_strlen(tmp)) {
    tmp[f.precision] = '\0';
  }

  int len = s21_strlen(tmp);
  int shift = f.width - len;

  // Processing width.
  if (f.minus && shift > 0) {
    s21_strcpy(s, tmp);
    s21_memset(s + len, ' ', shift);
    s21_memset(s + len + shift, 0, 1);
  } else if (shift > 0) {
    s21_memset(s, ' ', shift);
    s21_strcpy(s + shift, tmp);
  } else {
    s21_strcpy(s, tmp);
  }

  // Filling the buffer.
  while (*s != '\0') {
    s21_memset((*str)++, *s, 1);
    ++s;
  }
  return s21_strlen(tmp);
}

int s21_parse_u(char **str, struct flags f, va_list *va) {
  char temp[1024];
  uint64_t d = va_arg(*va, uint64_t);  // extract the variable.
  switch (f.length) {
    case 0:
      d = (uint32_t)d;
      break;
    case 'h':
      d = (uint16_t)d;
      break;
  }
  char *p = s21_itoa_uint64(d, temp, 10);  // int to str

  format_precision(p, f);
  format_flags(p, f);

  size_t length = s21_strlen(p);

  while (*p) {
    s21_memset((*str)++, *p, 1);  // Filling the buffer.
    ++p;
  }

  return length;
}

// Processing flags +, -, ' ' and width.
void format_flags(char *buf, struct flags f) {
  char tmp[1024] = {'\0'};
  if (f.plus && f.specifier != 'u') {
    tmp[0] = buf[0] == '-' ? buf[0] : '+';
    s21_strcpy(tmp + 1, buf[0] == '-' ? buf + 1 : buf);
    s21_strcpy(buf, tmp);
  } else if (f.space && buf[0] != '-' && f.specifier != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buf);
    s21_strcpy(buf, tmp);
  }
  if (f.width > (int)s21_strlen(buf)) {
    int idx = f.width - s21_strlen(buf);
    if (!f.minus) {
      s21_memset(tmp, f.zero ? '0' : ' ', idx);
      s21_strcpy(tmp + idx, buf);
    } else {
      s21_strcpy(tmp, buf);
      s21_memset(tmp + s21_strlen(tmp), ' ', idx);
    }
    s21_strcpy(buf, tmp);
  }
}

void format_precision(char *buf, struct flags f) {
  char tmp[1024] = {'\0'};

  int sign = 0;
  int len = s21_strlen(buf);

  if (buf[0] == '-') {
    tmp[0] = '-';
    len--;
    sign = 1;
  }

  if (f.precision > len) {
    int idx;
    for (idx = sign; idx < f.precision - len + sign; idx++) tmp[idx] = '0';

    for (int i = sign; buf[i]; i++, idx++) tmp[idx] = buf[i];

    s21_strcpy(buf, tmp);
  }

  if (f.is_precision_set && f.precision == 0 && buf[0] == '0') buf[0] = '\0';
}
