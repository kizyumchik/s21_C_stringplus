#include <stdio.h>

#include "../s21_string.h"

// Выполняет поиск первого вхождения символа C (беззнаковый тип)
// в строке, на которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
  char *ans = s21_NULL;
  do {
    if (*str == c) {
      ans = (char *)str;
      break;
    }
  } while (*str++);
  return ans;
}