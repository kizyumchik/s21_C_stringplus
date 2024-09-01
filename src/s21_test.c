#include "s21_test.h"

static int run_test_suite(Suite *test_suite) {
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = srunner_create(test_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed);
}

int main() {
  int number_failed = 0;
  Suite *suite_array[] = {
      memset_suite(),  memchr_suite(),   memcmp_suite(),   strlen_suite(),
      memcpy_suite(),  strchr_suite(),   strcspn_suite(),  strncat_suite(),
      strncmp_suite(), strncpy_suite(),  strpbrk_suite(),  strrchr_suite(),
      strstr_suite(),  strtok_suite(),   to_lower_suite(), to_upper_suite(),
      insert_suite(),  strerror_suite(), sprintf_suite(),  NULL};
  printf("\n");
  for (size_t i = 0; suite_array[i]; ++i) {
    number_failed += run_test_suite(suite_array[i]);
    printf("\n");
  }

  return (number_failed ? EXIT_FAILURE : EXIT_SUCCESS);
}
