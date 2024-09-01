#include "../s21_test.h"

// Нужно ли выделять динамически?
START_TEST(s21_strncmp_test_passed) {
  char str[29] = "Hello World! I am a student!";
  char str1[19] = "Hello student!";
  ck_assert_int_eq(s21_strncmp(str, str1, 5), strncmp(str, str1, 5));
}
END_TEST

START_TEST(s21_strncat_test_faild) {
  char str[29] = "Hello World! I am a student!";
  char str1[29] = "Hello student!";
  ck_assert_int_ne(s21_strncmp(str, str1, 6), strncmp(str, str1, 7));
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strncmp");
  tc = tcase_create("strncmp");

  tcase_add_test(tc, s21_strncmp_test_passed);
  tcase_add_test(tc, s21_strncat_test_faild);
  suite_add_tcase(s, tc);

  return s;
}
