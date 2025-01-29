#include "s21_test_string.h"

START_TEST(trim_1) {
  char src[] = "    Hello, World!  ";
  char trim_src[] = " ";
  char *result = s21_trim(src, trim_src);
  ck_assert_str_eq("Hello, World!", result);
  free(result);
}
END_TEST

START_TEST(trim_2) {
  char src[] = "*****Hello, World!**";
  char trim_src[] = "*";
  char *result = s21_trim(src, trim_src);
  ck_assert_str_eq("Hello, World!", result);
  free(result);
}
END_TEST

START_TEST(trim_3) {
  char src[] = "Hello, World!";
  char trim_src[] = " ";
  char *result = s21_trim(src, trim_src);
  ck_assert_str_eq("Hello, World!", result);
  free(result);
}
END_TEST

START_TEST(trim_4) {
  char src[] = "";
  char trim_src[] = " ";
  char *result = s21_trim(src, trim_src);
  ck_assert_str_eq("", result);
  free(result);
}
END_TEST

START_TEST(trim_5) {
  char src[] = "*****Hello, World!!!**";
  char trim_src[] = "*!";
  char *result = s21_trim(src, trim_src);
  ck_assert_str_eq("Hello, World", result);
  free(result);
}
END_TEST

START_TEST(trim_6) {
  char *src = NULL;
  char trim_src[] = "*";
  char *result = s21_trim(src, trim_src);
  ck_assert_ptr_eq(S21_NULL, result);
  free(result);
}
END_TEST

START_TEST(trim_7) {
  char src[] = "HIII";
  char *trim_src = NULL;
  char *result = s21_trim(src, trim_src);
  ck_assert_ptr_eq(S21_NULL, result);
  free(result);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("\033[45m S21_TRIM \033[0m");
  TCase *tc = tcase_create("trim_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, trim_7);

  suite_add_tcase(s, tc);
  return s;
}