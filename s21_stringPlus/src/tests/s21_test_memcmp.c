#include "s21_test_string.h"

START_TEST(memcmp_1) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "Hello";
  char str2[] = "World";
  s21_size_t n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "abc";
  char str2[] = "abcd";
  s21_size_t n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "abcd";
  char str2[] = "abc";
  s21_size_t n = 4;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  s21_size_t n = 13;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "Hello";
  char str2[] = "Hello!";
  s21_size_t n = 6;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "12345";
  char str2[] = "12344";
  s21_size_t n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "ABC";
  char str2[] = "abc";
  s21_size_t n = 3;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "abc";
  char str2[] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("\033[45m S21_MEMCMP \033[0m");
  TCase *tc = tcase_create("memcmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);

  suite_add_tcase(s, tc);
  return s;
}