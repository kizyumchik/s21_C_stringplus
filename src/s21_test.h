#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions/s21_sprintf.h"
#include "s21_string.h"

Suite *memset_suite(void);
Suite *memchr_suite(void);
Suite *strlen_suite(void);
Suite *memcmp_suite(void);
Suite *memcpy_suite(void);
Suite *strchr_suite(void);
Suite *strcspn_suite(void);
Suite *strncat_suite(void);
Suite *strncmp_suite(void);
Suite *strncpy_suite(void);
Suite *strpbrk_suite(void);
Suite *strrchr_suite(void);
Suite *strstr_suite(void);
Suite *strtok_suite(void);
Suite *to_lower_suite(void);
Suite *to_upper_suite(void);
Suite *trim_suite(void);
Suite *insert_suite(void);
Suite *strerror_suite(void);
Suite *sprintf_suite(void);

#endif