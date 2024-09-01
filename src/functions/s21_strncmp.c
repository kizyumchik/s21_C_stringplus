#include <stdio.h>

#include "../s21_string.h"

// Сравнивает не более первых n байтов str1 и str2.
// int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
//   s21_size_t i = 0;
//   for (; *str1 == *str2 && i < n - 1; str1++, str2++, i++) {
//     if (*str2 == '\0')
//       return 0;
//   }
//   return (unsigned char)*str1 - (unsigned char)*str2;
// }

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;

  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        res = str1[i] - str2[i];
        break;
      }
    }
  }

  return res;
}