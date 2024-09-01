#include "../s21_test.h"

START_TEST(s21_memcmp_test_passed) {
  char str[29] = "Hello World! I am a student!";
  char str1[29] = "Hello World! I am a student!";
  ck_assert_uint_eq(s21_memcmp(str, str1, 15), memcmp(str, str1, 15));
}
END_TEST

START_TEST(s21_memcmp_test_faild) {
  char str[29] = "Hello World! I am a student!";
  char str1[] = "Hello student!";
  char str2[] = " A";
  ck_assert_uint_ne(s21_memcmp(str, str1, 10), memcmp(str, str2, 2));
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("memcmp");
  tc = tcase_create("memcmp");

  tcase_add_test(tc, s21_memcmp_test_passed);
  tcase_add_test(tc, s21_memcmp_test_faild);
  suite_add_tcase(s, tc);

  return s;
}
