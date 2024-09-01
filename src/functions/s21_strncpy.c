#include <stdio.h>

#include "../s21_string.h"

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;
  while (n) {
    if ((*tmp = *src) != 0) src++;
    tmp++;
    n--;
  }
  return dest;
}