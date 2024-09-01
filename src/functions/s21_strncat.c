#include <stdio.h>

#include "../s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки,
// на которую указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest + s21_strlen(dest);
  while (*src != '\0' && n--) {
    *ptr++ = *src++;
  }
  *ptr = '\0';
  return dest;
}
