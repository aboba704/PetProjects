#include "s21_test_string.h"

START_TEST(test_to_upper_1) {
  char str_src[30] = "Hello, world!";
  char str_res[30] = "HELLO, WORLD!";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_2) {
  char str_src[30] = "\nh\t\\g123123";
  char str_res[30] = "\nH\t\\G123123";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str_src[30] = "ALREADY UPPER";
  char str_res[30] = "ALREADY UPPER";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_4) {
  char str_src[30] = "";
  char str_res[30] = "";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_5) {
  char str_src[50] = "abcdefghijklmnopqrstuvwxyz";
  char str_res[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_6) {
  char str_src[30] = "_?};!234";
  char str_res[30] = "_?};!234";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *str_src = S21_NULL;
  char *str_res = S21_NULL;
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("\033[45m S21_TO_UPPER \033[0m");
  TCase *tc = tcase_create("to_upper_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_upper_1);
  tcase_add_test(tc, test_to_upper_2);
  tcase_add_test(tc, test_to_upper_3);
  tcase_add_test(tc, test_to_upper_4);
  tcase_add_test(tc, test_to_upper_5);
  tcase_add_test(tc, test_to_upper_6);
  tcase_add_test(tc, test_to_upper_7);

  suite_add_tcase(s, tc);
  return s;
}
