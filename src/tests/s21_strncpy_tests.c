#include "../s21_test.h"

// Нужно ли выделять динамически?
START_TEST(s21_strncpy_test_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[19] = "Halo ";
  char str2[100] = "Hello World! I am a student!";
  ck_assert_str_eq(s21_strncpy(str, str1, 5), strncpy(str2, str1, 5));
}
END_TEST

START_TEST(s21_strncpy_test_faild) {
  char str[100] = "Hello World! I am a student!";
  char str1[29] = "Hello student!";
  char str2[100] = "Hello World! I am a student!";
  ck_assert_str_ne(s21_strncpy(str, str1, 6), strncpy(str2, str1, 7));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strncpy");
  tc = tcase_create("strncpy");

  tcase_add_test(tc, s21_strncpy_test_passed);
  tcase_add_test(tc, s21_strncpy_test_faild);
  suite_add_tcase(s, tc);

  return s;
}
