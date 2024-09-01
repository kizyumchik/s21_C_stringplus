#include <stdio.h>

#include "../s21_string.h"

// Находит первое вхождение всей строки needle (не включая завершающий
// нулевой символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  const char *eye_of_needle = needle;
  while (*haystack) {
    eye_of_needle = needle;
    while (*eye_of_needle && *haystack == *eye_of_needle) {
      haystack++;
      eye_of_needle++;
    }
    if (!*eye_of_needle) {
      return (char *)(haystack - (eye_of_needle - needle));
    }
    haystack++;
  }
  return s21_NULL;
}