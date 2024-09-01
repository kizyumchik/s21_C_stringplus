#include <stdio.h>

#include "../s21_string.h"

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в
// строке, на которую указывает аргумент str.

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  s21_size_t len = s21_strlen(str);

  for (int i = len; i >= 0; i--) {
    if (str[i] == c) {
      res = ((char *)str) + i;
      break;
    }
  }

  return res;
}