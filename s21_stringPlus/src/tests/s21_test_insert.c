#include "s21_test_string.h"

START_TEST(insert_1) {
  char str[] = "Hello, World!";
  char *insert_str = " ";
  s21_size_t len = s21_strlen(str);
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("Hello, World! ", result);
  free(result);
}
END_TEST

START_TEST(insert_2) {
  char str[] = "Hello, world!";
  char *insert_str = "h";
  s21_size_t len = s21_strlen(str);
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("Hello, world!h", result);
  free(result);
}
END_TEST

START_TEST(insert_3) {
  char str[] = "Hello, world!";
  char *insert_str = "1";
  s21_size_t len = s21_strlen(str);
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("Hello, world!1", result);
  free(result);
}
END_TEST

START_TEST(insert_4) {
  char str[] = "Hello, world!";
  char *insert_str = "A";
  s21_size_t len = s21_strlen(str);
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("Hello, world!A", result);
  free(result);
}
END_TEST

START_TEST(insert_5) {
  char str[] = "Hello, world!";
  char *insert_str = "l";
  s21_size_t len = 5;
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("Hellol, world!", result);
  free(result);
}
END_TEST

START_TEST(insert_6) {
  char str[] = "Hello, world!";
  char *insert_str = "";
  s21_size_t len = 5;
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("Hello, world!", result);
  free(result);
}
END_TEST

START_TEST(insert_7) {
  char str[] = "4238432";
  char *insert_str = "5";
  s21_size_t len = 4;
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("42385432", result);
  free(result);
}
END_TEST

START_TEST(insert_8) {
  char str[] = "00000000";
  char *insert_str = "6";
  s21_size_t len = s21_strlen(str);
  char *result = s21_insert(str, insert_str, len);
  ck_assert_str_eq("000000006", result);
  free(result);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[45m S21_INSERT \033[0m");
  TCase *tc = tcase_create("insert_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);
  tcase_add_test(tc, insert_7);
  tcase_add_test(tc, insert_8);

  suite_add_tcase(s, tc);
  return s;
}