#include "../s21_test.h"

START_TEST(s21_memchr_test_passed) {
  char str[31] = "Hello World! I am a student!";
  char ch = 'I';
  ck_assert_pstr_eq(s21_memchr(str, ch, 15), memchr(str, ch, 15));
}
END_TEST

START_TEST(s21_memchr_test_faild) {
  char str[31] = "Hello World! I am a student!";
  char ch = '$';
  ck_assert_pstr_eq(s21_memchr(str, ch, 15), memchr(str, ch, 15));
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("memchr");
  tc = tcase_create("memchr");

  tcase_add_test(tc, s21_memchr_test_passed);
  tcase_add_test(tc, s21_memchr_test_faild);
  suite_add_tcase(s, tc);

  return s;
}
