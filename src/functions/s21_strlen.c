#include <stdio.h>

#include "../s21_string.h"

// Вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str) {
  const char *pointer = str;
  for (; *pointer; pointer++)
    ;
  return pointer - str;
}
