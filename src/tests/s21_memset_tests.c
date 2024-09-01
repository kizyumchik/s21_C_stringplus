#include "../s21_test.h"

START_TEST(s21_memset_test_passed) {
  char str[31] = "Hello World! I am a student!";
  char ch = '$';
  ck_assert_pstr_eq(s21_memset(str, ch, 5), memset(str, ch, 5));
}
END_TEST

START_TEST(s21_memset_test_faild) {
  char str[31] = "Hello World! I am a student!";
  char ch = '\0';
  ck_assert_pstr_eq(s21_memset(str, ch, 1), memset(str, ch, 1));
}
END_TEST

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("memset");
  tc = tcase_create("memset");

  tcase_add_test(tc, s21_memset_test_passed);
  tcase_add_test(tc, s21_memset_test_faild);
  suite_add_tcase(s, tc);

  return s;
}
