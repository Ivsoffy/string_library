#include <stdio.h>
// убрать потом
#include <string.h>
#define S21_NULL (void *)0
#define s21_size_t unsigned long int

int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);