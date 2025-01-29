#include "s21_test_string.h"

START_TEST(strncat_1) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "World!";
  s21_size_t n = 6;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_2) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "World!";
  s21_size_t n = 0;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_3) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "World!";
  s21_size_t n = 10;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_4) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "World!";
  s21_size_t n = 3;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_5) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "";
  s21_size_t n = 5;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_6) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "World!";
  s21_size_t n = 1;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_7) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "World!";
  s21_size_t n = 6;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_8) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  char src[] = "World!";
  s21_size_t n = 5;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_9) {
  char dest1[20] = "Test";
  char dest2[20] = "Test";
  char src[] = "String Concatenation!";
  s21_size_t n = 10;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_10) {
  char dest1[20] = "Hello-hello, ";
  char dest2[20] = "Hello-hello, ";
  char src[] = "World-world!";
  s21_size_t n = 5;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[45m S21_STRNCAT \033[0m");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);

  suite_add_tcase(s, tc);
  return s;
}
