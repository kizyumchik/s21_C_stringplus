#include "../s21_test.h"

// Нужно ли выделять динамически?
START_TEST(s21_strncat_test_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[10] = "Everybody";
  char str2[100] = "Hello World! I am a student!";
  ck_assert_pstr_eq(s21_strncat(str, str1, 5), strncat(str2, str1, 5));
}
END_TEST

START_TEST(s21_strncat_test_faild) {
  char str[100] = "Hello World! I am a student!";
  char str1[10] = "Everybody";
  char str2[100] = "Hello World! I am a student!";
  ck_assert_ptr_ne(s21_strncat(str, str1, 2), strncat(str2, str1, 1));
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strncat");
  tc = tcase_create("strncat");

  tcase_add_test(tc, s21_strncat_test_passed);
  tcase_add_test(tc, s21_strncat_test_faild);
  suite_add_tcase(s, tc);

  return s;
}
