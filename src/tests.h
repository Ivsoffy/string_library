#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

Suite *test_strcpy(void);
Suite *test_strncpy(void);
Suite *test_strcspn(void);
Suite *test_strlen(void);

#endif  // SRC_TESTS_ME_H
