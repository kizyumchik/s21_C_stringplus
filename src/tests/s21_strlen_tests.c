#include "../s21_test.h"

START_TEST(s21_strlen_test_passed) {
  char str[29] = "Hello World! I am a student!";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_passed_1) {
  char str[29] = "Hello World! I am a student!";
  ck_assert_uint_eq(s21_strlen(str), 28);
}
END_TEST

START_TEST(s21_strlen_test_faild) {
  char str[] = " \0";
  char str1[] = "\0";
  ck_assert_uint_ne(s21_strlen(str), strlen(str1));
}
END_TEST

START_TEST(s21_strlen_test_faild_1) {
  char str[29] = "Hello World! I am a student!";
  char str1[] = "\0";
  ck_assert_uint_ne(s21_strlen(str), strlen(str1));
}
END_TEST

START_TEST(s21_strlen_test_faild_2) {
  char str[] = " \0";
  ck_assert_int_ne(s21_strlen(str), -1);
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strlen");
  tc = tcase_create("strlen");

  tcase_add_test(tc, s21_strlen_test_passed);
  tcase_add_test(tc, s21_strlen_test_passed_1);
  tcase_add_test(tc, s21_strlen_test_faild);
  tcase_add_test(tc, s21_strlen_test_faild_1);
  tcase_add_test(tc, s21_strlen_test_faild_2);
  suite_add_tcase(s, tc);

  return s;
}
