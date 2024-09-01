#include "../s21_test.h"

START_TEST(s21_trim_test_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[100] = "H I";
  ck_assert_str_eq(s21_trim(str, str1), "ello World! I am a student!");
}
END_TEST

START_TEST(s21_trim_test2_passed) {
  char str[100] = "  Hello World! Hello students!  ";
  char str1[100] = " ";
  ck_assert_str_eq(s21_trim(str, str1), "Hello World! Hello students!");
}
END_TEST

Suite *trim_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("trim");
  tc = tcase_create("trim");

  tcase_add_test(tc, s21_trim_test_passed);
  tcase_add_test(tc, s21_trim_test2_passed);
  suite_add_tcase(s, tc);

  return s;
}
