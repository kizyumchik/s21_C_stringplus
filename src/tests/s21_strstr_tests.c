#include "../s21_test.h"

START_TEST(s21_strstr_test_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[100] = "World!";
  ck_assert_str_eq(s21_strstr(str, str1), strstr(str, str1));
}
END_TEST

START_TEST(s21_strstr_test2_passed) {
  char str[100] = "Hello World! Hello students!";
  char str1[100] = "\0";
  ck_assert_str_eq(s21_strstr(str, str1), strstr(str, str1));
}
END_TEST

START_TEST(s21_strstr_test3_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[100] = "\0";
  ck_assert_ptr_nonnull(strstr(str, str1));
}
END_TEST

START_TEST(s21_strstr_test4_passed) {
  char str[100] = "";
  char str1[100] = "Hello";
  ck_assert_ptr_null(s21_strstr(str, str1));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strstr");
  tc = tcase_create("strstr");

  tcase_add_test(tc, s21_strstr_test_passed);
  tcase_add_test(tc, s21_strstr_test2_passed);
  tcase_add_test(tc, s21_strstr_test3_passed);
  tcase_add_test(tc, s21_strstr_test4_passed);
  suite_add_tcase(s, tc);

  return s;
}
