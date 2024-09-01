#include "../s21_test.h"

START_TEST(s21_strpbrk_test_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[19] = "I dont mist";
  ck_assert_str_eq(s21_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(s21_strpbrk_test2_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[29] = "@";
  ck_assert_ptr_null(s21_strpbrk(str, str1));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strpbrk");
  tc = tcase_create("strpbrk");

  tcase_add_test(tc, s21_strpbrk_test_passed);
  tcase_add_test(tc, s21_strpbrk_test2_passed);
  suite_add_tcase(s, tc);

  return s;
}
