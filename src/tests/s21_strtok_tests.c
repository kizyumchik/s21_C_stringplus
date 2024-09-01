#include "../s21_test.h"

START_TEST(s21_strtok_test_passed) {
  char str[100] = "Hello World! I am a student!";
  char str1[100] = " ";
  ck_assert_str_eq(s21_strtok(str, str1), strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test2_passed) {
  char str[100] = "Hello World! Hello students!";
  char str1[100] = "\0";
  ck_assert_str_eq(s21_strtok(str, str1), strtok(str, str1));
}
END_TEST

START_TEST(s21_strtok_test3_passed) {
  char str[100] = "Hello World! Hello students!";
  char str1[100] = "";
  ck_assert_ptr_nonnull(s21_strtok(str, str1));
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strtok");
  tc = tcase_create("strtok");

  tcase_add_test(tc, s21_strtok_test_passed);
  tcase_add_test(tc, s21_strtok_test2_passed);
  tcase_add_test(tc, s21_strtok_test3_passed);
  suite_add_tcase(s, tc);

  return s;
}
