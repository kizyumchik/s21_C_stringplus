#include <stdio.h>

#include "../s21_string.h"

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL.
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t len_src = s21_strlen(src), len_str = s21_strlen(str);
  char *put = s21_NULL;
  if ((len_str != 0 || len_src != 0) && start_index <= len_src) {
    s21_size_t i = 0;
    put = calloc(len_src + len_str + 2, 1);
    if (put != s21_NULL) {
      for (; i < start_index; i++) {
        put[i] = src[i];
      }
      int j = 0;
      for (; i < start_index + len_str; i++, j++) {
        put[i] = str[0 + j];
      }
      for (; i < len_src + len_str; i++) {
        put[i] = src[i - len_str];
      }
    }
  }
  return put;
}
