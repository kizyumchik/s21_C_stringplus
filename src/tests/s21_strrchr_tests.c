#include "../s21_test.h"

START_TEST(s21_strrchr_test_passed) {
  char str[] = "Hello World! I am a student!";
  char ch = 100;
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_test2_passed) {
  char str[] = "Hello World! I am a student!";
  char ch = 108;
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_test3_passed) {
  char str[] = "Hello World! I am a student!";
  char ch = 200;
  ck_assert_ptr_null(s21_strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_test4_passed) {
  char str[] = "";
  char ch = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_test5_passed) {
  char str1[] = "floppabazbazkotya";
  char str2[] = "floppabaz";
  s21_size_t n_byte = 10;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("strrchr");
  tc = tcase_create("strrchr");

  tcase_add_test(tc, s21_strrchr_test_passed);
  tcase_add_test(tc, s21_strrchr_test2_passed);
  tcase_add_test(tc, s21_strrchr_test3_passed);
  tcase_add_test(tc, s21_strrchr_test4_passed);
  tcase_add_test(tc, s21_strrchr_test5_passed);
  suite_add_tcase(s, tc);

  return s;
}
