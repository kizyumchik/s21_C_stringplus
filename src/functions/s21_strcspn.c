#include <stdio.h>

#include "../s21_string.h"

// Вычисляет длину начального сегмента str1,
// который полностью состоит из символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p, *r;
  s21_size_t count = 0;
  for (p = str1; *p != '\0'; ++p) {
    for (r = str2; *r != '\0'; ++r) {
      if (*p == *r) break;
    }
    if (*p == *r) break;
    ++count;
  }
  return count;
}
