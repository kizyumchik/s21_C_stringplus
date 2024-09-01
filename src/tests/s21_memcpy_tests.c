#include "../s21_test.h"

START_TEST(s21_memcpy_test_passed) {
  char str[29] = "Hello World! I am a student!";
  char str1[13] = "Hello World!";
  char str2[29] = "Hello World! I am a student!";
  char str3[13] = "Hello World!";
  ck_assert_str_eq(s21_memcpy(str, str1, 5), memcpy(str2, str3, 5));
}
END_TEST

START_TEST(s21_memcpy_test2_passed) {
  char str[29] = "Hello World! I am a student!";
  char str1[] = " \0";
  char str2[29] = "Hello World! I am a student!";
  char str3[] = " ";
  ck_assert_str_eq(s21_memcpy(str, str1, 1), memcpy(str2, str3, 1));
}
END_TEST

START_TEST(s21_memcpy_test_faild) {
  char str[29] = "Hello World! I am a student!";
  char str1[] = " \0";
  char str2[29] = "Hello World! I am a student!";
  char str3[] = " \n\0";
  ck_assert_str_eq(s21_memcpy(str, str1, 1), memcpy(str2, str3, 1));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("memcpy");
  tc = tcase_create("memcpy");

  tcase_add_test(tc, s21_memcpy_test_passed);
  tcase_add_test(tc, s21_memcpy_test2_passed);
  tcase_add_test(tc, s21_memcpy_test_faild);
  suite_add_tcase(s, tc);

  return s;
}
