#include "s21_test_string.h"

START_TEST(test_to_lower_1) {
  char str_src[30] = "hELLO, WORLD!";
  char str_res[] = "hello, world!";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str_src[30] = "\nH\t\\G123123";
  char str_res[30] = "\nh\t\\g123123";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_3) {
  char str_src[30] = "already lower";
  char str_res[30] = "already lower";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_4) {
  char str_src[30] = "";
  char str_res[30] = "";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_5) {
  char str_src[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str_res[30] = "abcdefghijklmnopqrstuvwxyz";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_6) {
  char str_src[30] = "_?};!234";
  char str_res[30] = "_?};!234";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *str_src = S21_NULL;
  char *str_res = S21_NULL;
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("\033[45m S21_TO_LOWER \033[0m");
  TCase *tc = tcase_create("to_lower_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);
  tcase_add_test(tc, test_to_lower_5);
  tcase_add_test(tc, test_to_lower_6);
  tcase_add_test(tc, test_to_lower_7);

  suite_add_tcase(s, tc);
  return s;
}
