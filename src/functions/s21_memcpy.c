#include <stdio.h>

#include "../s21_string.h"

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i;
  unsigned char *cdest = (unsigned char *)dest;
  const unsigned char *csrs = (const unsigned char *)src;
  for (i = 0; i < n; i++) {
    *cdest++ = *csrs++;
  }
  return dest;
}
