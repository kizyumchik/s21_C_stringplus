#include <stdio.h>

#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t count) {
  const unsigned char *stru1, *stru2;
  int res = 0;
  for (stru1 = str1, stru2 = str2; 0 < count; ++stru1, ++stru2, count--)
    if ((res = *stru1 - *stru2) != 0) break;
  return res;
}
