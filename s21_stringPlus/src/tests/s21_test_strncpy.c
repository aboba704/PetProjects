#include "s21_test_string.h"

START_TEST(strncpy_1) {
  char dest1[20];
  char dest2[20];
  char src[] = "Hello, World!";
  s21_size_t n = 5;
  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);
  dest1[n] = '\0';
  dest2[n] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_2) {
  char dest1[20];
  char dest2[20];
  char src[] = "Hello, World!";
  s21_size_t n = 0;
  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);
  dest1[n] = '\0';
  dest2[n] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_3) {
  char dest1[20];
  char dest2[20];
  char src[] = "Hello, World!";
  s21_size_t n = 20;
  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);
  dest1[13] = '\0';
  dest2[13] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_4) {
  char dest1[20];
  char dest2[20];
  char src[] = "Hello, World!";
  s21_size_t n = 7;
  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);
  dest1[n] = '\0';
  dest2[n] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_5) {
  char dest1[20];
  char dest2[20];
  char src[] = "";
  s21_size_t n = 5;
  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);
  dest1[0] = '\0';
  dest2[0] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncpy_6) {
  char dest1[20];
  char dest2[20];
  char src[] = "Hello, World!";
  s21_size_t n = 3;
  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);
  dest1[n] = '\0';
  dest2[n] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("\033[45m S21_STRNCPY \033[0m");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);

  suite_add_tcase(s, tc);
  return s;
}