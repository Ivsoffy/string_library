#include "./s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = S21_NULL;
    int exit_flag = 0;
    for (int i = 0; str1[i] != '\0' && exit_flag == 0; i++) {
        for (int j = 0; str2[j] != 0; j++) {
            if (str1[i] == str2[j]) {
                result = (char *)str1 + 1;
                exit_flag = 1;
            break;
            }
        }
    }
    return result;
}

char *s21_strrchr(const char *str, int c) {
    char *result = S21_NULL;
    while (*str != '\0') {
        if (*str == (unsigned char)c) {
            result = (char *)str;
        }
        str++;
    }
    return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t result = 0;
    int exit_flag = 0;
    const char *ptr1;
    const char *ptr2;

    for (ptr1 = str1; *ptr1 && exit_flag == 0; ptr1++) {
        for (ptr2 = str2; ; ptr2++) {
            if (*ptr2 == '\0') {
                result = (ptr1 - str1);
                exit_flag = 1;
                break;
            } else {
                if (*ptr1 == *ptr2) {
                    break;
                }
            }
        }
    }
    if (exit_flag == 0) {
        result = (ptr1 - str1);
    }
    return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *result = S21_NULL;
    int exit_flag = 0;

    if (*needle == '\0') {
        result = (char *)haystack;
        exit_flag = 1;
    }
    if (exit_flag == 0) {
        for (int i = 0; haystack[i] != '\0' && exit_flag == 0; i++) {
            int temp = i;
            int j = 0;
            while (haystack[i++] == needle[j++]) {
                if (needle[j] == '\0') {
                    result = (char *)&haystack[temp];
                    exit_flag = 1;
                    break;
                }
            }
            i = temp;
        }
    }
    return result;
}

char *s21_strtok(char *str, const char *delim) {
    char *result = S21_NULL;
    // int exit_flag = 0;
    static char *last;
    // register int ch;

    if (str == S21_NULL && delim != S21_NULL) {
        str = last;
    }
    if (str != S21_NULL && delim != S21_NULL) {
        s21_size_t str1 = 0, str2 = 0;
        for (; str[str1] && str[str2] != delim[str2]; str2++) {
            if (delim[str2] == '\0') {
                str1++;
                str2 = -1;
            }
        }
        if (str[str1] == '\0' || str[str1 + 1] == '\0') {
                str[str1] = '\0';
                last = S21_NULL;
        } else {
            str[str1] = '\0';
            last = (char *)&str[str1 + 1];
        }
        result = str;
    }
    return result;
}
