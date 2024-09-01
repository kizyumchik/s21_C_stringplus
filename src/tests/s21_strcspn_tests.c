#include "../s21_test.h"

START_TEST(s21_strcspn_test_passed) {
  char str[29] = "Hello World! I am a student!";
  char str1[29] = "Hello World! I am a dinasaur!";
  ck_assert_int_eq(s21_strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test2_passed) {
  char str[29] = "Hello World! I am a student!";
  char str1[] = "\0";
  char str2[] = " \0";
  ck_assert_int_ne(s21_strcspn(str, str1), strcspn(str, str2));
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strcspn");
  tc = tcase_create("strcspn");

  tcase_add_test(tc, s21_strcspn_test_passed);
  tcase_add_test(tc, s21_strcspn_test2_passed);
  suite_add_tcase(s, tc);

  return s;
}
