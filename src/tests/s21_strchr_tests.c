#include "../s21_test.h"

START_TEST(s21_strchr_test_passed) {
  char str[29] = "Hello World! I am a student!";
  char ch = '!';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(s21_strchr_test2_passed) {
  char str[29] = "Hello World! I am a student!";
  char ch = '\0';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strchr");
  tc = tcase_create("strchr");

  tcase_add_test(tc, s21_strchr_test_passed);
  tcase_add_test(tc, s21_strchr_test2_passed);
  suite_add_tcase(s, tc);

  return s;
}
