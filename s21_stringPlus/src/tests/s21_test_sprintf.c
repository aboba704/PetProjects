#include "s21_test_string.h"

START_TEST(test_no_args) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Hello, world!");
  sprintf(assert, "Hello, world!");
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %c", 'a');
  sprintf(assert, "Count: %c", 'a');
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_int_default) {
  char result[20];
  char assert[20];
  int d = 57;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_int_multy) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %d %d %d %d", -4, 8, 15, 16);
  sprintf(assert, "Count: %d %d %d %d", -4, 8, 15, 16);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_char_default) {
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c", c);
  sprintf(assert, "Char: %c", c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_char_multy) {
  char c = 'B';
  char result[20];
  char assert[20];
  s21_sprintf(result, "Char: %c%c%c", 'A', c, 'C');
  sprintf(assert, "Char: %c%c%c", 'A', c, 'C');
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_double_default) {
  char result[20];
  char assert[20];
  double f = 3.14;
  s21_sprintf(result, "Pi: %f", f);
  sprintf(assert, "Pi: %f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

// DOUBLE FLAGS
START_TEST(f_minus) {
  char result[20];
  char assert[20];
  double f = 3.14;
  s21_sprintf(result, "Pi: %.2f", f);
  sprintf(assert, "Pi: %.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(f_plus) {
  char result[20];
  char assert[20];
  double f = 3.14;
  s21_sprintf(result, "Pi: %.2f", f);
  sprintf(assert, "Pi: %.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(f_space) {
  char result[20];
  char assert[20];
  double f = 3.14;
  s21_sprintf(result, "Pi: %.2f", f);
  sprintf(assert, "Pi: %.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(f_width) {
  char result[20];
  char assert[20];
  double f = 3.14;
  s21_sprintf(result, "Pi: %.2f", f);
  sprintf(assert, "Pi: %.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(f_precision) {
  char result[20];
  char assert[20];
  double f = 3.14;
  s21_sprintf(result, "Pi: %.2f", f);
  sprintf(assert, "Pi: %.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(f_multy) {
  char result[20];
  char assert[20];
  double f = 3.145678;
  s21_sprintf(result, "Pi: %+10.2f", f);
  sprintf(assert, "Pi: %+10.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_double_NOTdefault) {
  char result[20];
  char assert[20];
  double f = 3.14;
  s21_sprintf(result, "Pi: %.2f", f);
  sprintf(assert, "Pi: %.2f", f);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default13) {
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default14) {
  char result[20];
  char assert[20];
  int d = 0;
  s21_sprintf(result, "Count: %d abc", d);
  sprintf(assert, "Count: %d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default15) {
  char result[20];
  char assert[20];
  int d = 1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default16) {
  char result[20];
  char assert[20];
  int d = -1;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default17) {
  char result[20];
  char assert[20];
  int d = -0;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default18) {
  char result[40];
  char assert[40];
  int d = 2147483647;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_default19) {
  char result[40];
  char assert[40];
  int d = -2147483648;
  s21_sprintf(result, "Count: % d abc", d);
  sprintf(assert, "Count: % d abc", d);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(string_1) {
  char result[40];
  char assert[40];
  char str[] = "hello world!";
  char *format = "I said %.5s";
  ck_assert_int_eq(s21_sprintf(result, format, str),
                   sprintf(assert, format, str));
  // sprintf(assert, "I said %.5s", str);
  // s21_sprintf(result, "I said %.5s", str);

  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(string_precision) {
  char result[100];
  char assert[100];

  char val[] = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  // sprintf(assert, "%.15s", val);
  // s21_sprintf(result, "%.15s", val);
  char *format = "%.15s";
  ck_assert_int_eq(s21_sprintf(result, format, val),
                   sprintf(assert, format, val));

  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(string_width) {
  char result[100];
  char assert[100];

  char val[] = "69 IS MY FAVORITE NUMBER";
  // sprintf(assert, "%15.9s", val);
  // s21_sprintf(result, "%15.9s", val);
  char *format = "%15.9s";
  sprintf(assert, format, val);
  s21_sprintf(result, format, val);
  // ck_assert_int_eq(s21_sprintf(result, format, val), sprintf(assert, format,
  // val));
  ck_assert_str_eq(result, assert);
}
END_TEST
START_TEST(string_flags) {
  char result[100];
  char assert[100];

  char val[] = "69 IS MY FAVORITE NUMBER";
  // sprintf(assert, "%-15.9s", val);
  // s21_sprintf(result, "%-15.9s", val);
  char *format = "%-15.9s";
  ck_assert_int_eq(s21_sprintf(result, format, val),
                   sprintf(assert, format, val));

  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(string_long) {
  char result[100];
  char assert[100];

  char val[] =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  sprintf(assert, "%s", val);
  s21_sprintf(result, "%s", val);

  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(string_many) {
  char result[200];
  char assert[200];

  char val[] =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char s1[] = "";
  char s2[] = "87418347813748913749871389480913";
  char s3[] = "HAHAABOBASUCKER";
  sprintf(assert, "%s%s%s%s", val, s1, s2, s3);
  s21_sprintf(result, "%s%s%s%s", val, s1, s2, s3);

  ck_assert_str_eq(result, assert);
}

START_TEST(flag_minus) {
  char result[40];
  char assert[40];
  int d = 125;
  // s21_sprintf(result, "%-5d", d);
  // sprintf(assert, "%-5d", d);
  char *format = "%-5d";
  ck_assert_int_eq(s21_sprintf(result, format, d), sprintf(assert, format, d));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(flag_plus) {
  char result[40];
  char assert[40];
  int d = 125;
  // s21_sprintf(result, "%+d", d);
  // sprintf(assert, "%+d", d);
  char *format = "%+d";
  ck_assert_int_eq(s21_sprintf(result, format, d), sprintf(assert, format, d));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(flag_space_plus) {
  char result[40];
  char assert[40];
  int d = 125;
  // s21_sprintf(result, "% d", d);
  // sprintf(assert, "% d", d);
  char *format = "% d";
  ck_assert_int_eq(s21_sprintf(result, format, d), sprintf(assert, format, d));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(flag_space_minus) {
  char result[40];
  char assert[40];
  int d = -125;
  // s21_sprintf(result, "% d", d);
  // sprintf(assert, "% d", d);
  char *format = "% d";
  ck_assert_int_eq(s21_sprintf(result, format, d), sprintf(assert, format, d));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(width_num) {
  char result[40];
  char assert[40];
  int d = 125;
  char *format = "%5d";
  ck_assert_int_eq(s21_sprintf(result, format, d), sprintf(assert, format, d));
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[40];
  char str2[40];

  long int val = 698518581899;
  char *format = "%ld";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int2) {
  char str1[40];
  char str2[40];

  char *format = "%+5.31ld";
  long int val = 698518581899;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(flags_long_int3) {
  char str1[40];
  char str2[40];

  long int val = 698518581899;
  char *format = "%-5.31ld";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[40];
  char str2[40];

  short int val = 6958;
  char *format = "%hd";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_unsigned_int) {
  char str1[40];
  char str2[40];

  unsigned int val = 3000000000;
  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(lu) {
  char str1[40];
  char str2[40];

  unsigned long val = 998518581899;
  char *format = "%lu";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hu) {
  char str1[40];
  char str2[40];

  unsigned short val = 14;
  char *format = "%hu";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(wc) {
  char str1[40];
  char str2[40];

  char format[] = "%lc";
  wchar_t val = L'\x3b1';
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(wc_minus) {
  char str1[40];
  char str2[40];

  char format[] = "%-5lc";
  wchar_t val = L'\x3b1';
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(wc_more) {
  char str1[40];
  char str2[40];

  char format[] = "%5lc";
  wchar_t val = L'\x3b1';
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(с_width) {
  char str1[40];
  char str2[40];

  char format[] = "%5c";
  char val = 'a';
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(с_more) {
  char str1[40];
  char str2[40];

  char format[] = "%-5c";
  char val = 'c';
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[40];
  char str2[40];

  s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's');
  sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's');

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(percent) {
  char str1[40];
  char str2[40];

  int val = 12;
  char *format = "%% %d";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(wrong_spec) {
  char str1[40];
  char str2[40];

  int val = 12;
  char *format = "%% %t";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(wrong_flag) {
//   char str1[40];
//   char str2[40];

//   int val = 12;
//   char *format = "%% %:d";
//   s21_sprintf(str1, format, val);
//   sprintf(str2, format, val);

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

Suite *test_sprintf(void) {
  Suite *s1 = suite_create("\033[45m S21_SPRINTF \033[0m");
  TCase *tc1_1 = tcase_create("sprintf_tc");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_no_args);
  tcase_add_test(tc1_1, test_default);
  tcase_add_test(tc1_1, test_int_default);
  tcase_add_test(tc1_1, test_int_multy);
  tcase_add_test(tc1_1, test_char_default);
  tcase_add_test(tc1_1, test_char_multy);
  tcase_add_test(tc1_1, test_double_default);
  tcase_add_test(tc1_1, f_minus);
  tcase_add_test(tc1_1, f_plus);
  tcase_add_test(tc1_1, f_space);
  tcase_add_test(tc1_1, f_width);
  tcase_add_test(tc1_1, f_precision);
  tcase_add_test(tc1_1, f_multy);
  tcase_add_test(tc1_1, test_double_NOTdefault);
  tcase_add_test(tc1_1, test_default13);
  tcase_add_test(tc1_1, test_default14);
  tcase_add_test(tc1_1, test_default15);
  tcase_add_test(tc1_1, test_default16);
  tcase_add_test(tc1_1, test_default17);
  tcase_add_test(tc1_1, test_default18);
  tcase_add_test(tc1_1, test_default19);
  tcase_add_test(tc1_1, string_1);
  tcase_add_test(tc1_1, string_precision);
  tcase_add_test(tc1_1, string_width);
  tcase_add_test(tc1_1, string_flags);
  tcase_add_test(tc1_1, string_long);
  tcase_add_test(tc1_1, string_many);
  tcase_add_test(tc1_1, flag_minus);
  tcase_add_test(tc1_1, flag_plus);
  tcase_add_test(tc1_1, flag_space_plus);
  tcase_add_test(tc1_1, flag_space_minus);
  tcase_add_test(tc1_1, width_num);
  tcase_add_test(tc1_1, flags_long_int);
  tcase_add_test(tc1_1, wc);
  tcase_add_test(tc1_1, wc_minus);
  tcase_add_test(tc1_1, wc_more);
  tcase_add_test(tc1_1, с_width);
  tcase_add_test(tc1_1, с_more);
  tcase_add_test(tc1_1, test_many_char);
  tcase_add_test(tc1_1, flags_long_int2);
  tcase_add_test(tc1_1, flags_long_int3);
  tcase_add_test(tc1_1, flags_short_int);
  tcase_add_test(tc1_1, flags_unsigned_int);
  tcase_add_test(tc1_1, lu);
  tcase_add_test(tc1_1, hu);
  tcase_add_test(tc1_1, flags_unsigned_int);
  tcase_add_test(tc1_1, percent);
  tcase_add_test(tc1_1, wrong_spec);
  // tcase_add_test(tc1_1, wrong_flag);

  suite_add_tcase(s1, tc1_1);
  return s1;
}
