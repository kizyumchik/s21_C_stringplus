#include <stdio.h>

#include "../s21_string.h"

// Находит первый символ в строке str1, который соответствует любому
// символу, указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  const char *sc1, *sc2;
  void *ans = s21_NULL;
  for (sc1 = str1; ((*sc1) && (!ans)); ++sc1) {
    for (sc2 = str2; ((*sc2) && (!ans)); ++sc2) {
      if (*sc1 == *sc2) ans = (char *)sc1;
    }
  }
  return ans;
}
