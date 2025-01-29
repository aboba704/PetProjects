#include "s21_test_string.h"

START_TEST(strstr_1) {
  char haystack[] = "Hello, World!";
  char needle[] = "World";
  char *result1 = strstr(haystack, needle);
  char *result2 = s21_strstr(haystack, needle);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(strstr_2) {
  char haystack[] = "Hello, World!";
  char needle[] = "Hello";
  char *result1 = strstr(haystack, needle);
  char *result2 = s21_strstr(haystack, needle);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(strstr_3) {
  char haystack[] = "Hello, World!";
  char needle[] = "!";
  char *result1 = strstr(haystack, needle);
  char *result2 = s21_strstr(haystack, needle);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(strstr_4) {
  char haystack[] = "Hello, World!";
  char needle[] = "No";
  char *result1 = strstr(haystack, needle);
  char *result2 = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(strstr_5) {
  char haystack[] = "Hello, World!";
  char needle[] = "";
  char *result1 = strstr(haystack, needle);
  char *result2 = s21_strstr(haystack, needle);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(strstr_6) {
  char haystack[] = "";
  char needle[] = "Hello";
  char *result1 = strstr(haystack, needle);
  char *result2 = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(strstr_7) {
  char haystack[] = "";
  char needle[] = "";
  char *result1 = strstr(haystack, needle);
  char *result2 = s21_strstr(haystack, needle);
  ck_assert_str_eq(result1, result2);
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[45m S21_STRSTR \033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);

  suite_add_tcase(s, tc);
  return s;
}
