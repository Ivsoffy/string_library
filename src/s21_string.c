#include "s21_string.h"



int s21_strcmp(const char *str1, const char *str2) {
    char *str_1 = (char *)str1;
    char *str_2 = (char *)str2;
    for (; *str_1 && *str_1 == *str_2; str_1++, str_2++);
    return *str_1 - *str_2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int rv = 0;
    char *str_1 = (char *)str1;
    char *str_2 = (char *)str2;
    for (s21_size_t i = 0; i < n && *str_1 && *str_1 == *str_2; str_1++, str_2++, i++);
    if (n == 0) {
        rv = 0;
    } else {
        rv = *str_1 - *str_2;
    }
    return rv;
}

char *s21_strchr(const char *str, int c) {
    int have = 0;
    while (*str != '\0') {
        if (*str == (unsigned char)c) {
            have = 1;
            break;
        }
        str++;
    }
    char *rv = (char *)str;
    if (*str == '\0' && c == '\0') {
        rv = (char *)str;
    } else if (have == 0) {
        rv = S21_NULL;
    }
    return rv;
}

char *s21_strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*ptr) {
        ptr++;
    }
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *ptr = dest;
    while (*ptr) {
        ptr++;
    }
    s21_size_t i = 0;
    while (*src != '\0' && i < n) {
        *ptr = *src;
        ptr++;
        src++;
        i++;
    }
    *ptr = '\0';
    return dest;
}
