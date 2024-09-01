#include <stdio.h>

#include "../s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim) {
  static char *stat = s21_NULL;
  char *ret = s21_NULL;
  if (str != s21_NULL) {
    stat = str;
  }
  s21_size_t del_length = s21_strlen(delim);
  if (stat != s21_NULL) {
    while (s21_memchr(delim, *stat, del_length) != s21_NULL) {
      stat++;
    }
    if (*stat != '\0') {
      ret = stat;
      while (*stat) {
        if (s21_memchr(delim, *stat, del_length) != s21_NULL) {
          break;
        } else {
          stat++;
        }
      }
      if (*stat) {
        stat[0] = '\0';
        stat++;
      }
    }
  }
  return ret;
}
