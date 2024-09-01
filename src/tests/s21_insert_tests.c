#include "../s21_test.h"

static void test(const char *str1, const char *str2, const char *answer,
                 int insert_point) {
  char *result = (char *)s21_insert(str1, str2, insert_point);
  ck_assert_str_eq(result, answer);
  free(result);
}

START_TEST(insert_1_test) {
  test("Hello World! ", "I am a student!", "Hello World! I am a student!", 13);
}
END_TEST

START_TEST(insert_2_test) {
  test("Hello World!", ", New ", "Hello, New  World!", 5);
}
END_TEST

Suite *insert_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("insert");
  tc = tcase_create("insert");

  tcase_add_test(tc, insert_1_test);
  tcase_add_test(tc, insert_2_test);
  suite_add_tcase(s, tc);

  return s;
}
