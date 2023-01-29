#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#define S21_NULL (void *)0
#define s21_size_t unsigned long int

#include <stdio.h>
// убрать потом
//#include <string.h>
//#include <stdlib.h>
//#include <stdarg.h>

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// sprintf
typedef struct option {
  int work;
  int minus;
  int plus;
  int space;
  int width;
  int width_value;
  int accuracy;
  int accuracy_value;
  int l;
  int h;
} flags;

int s21_sprintf(char *str, const char *format, ...);
void update_opt(flags *opt);
void check_opt(flags *opt, int *index, const char *format);
void print_specificator(const char *format, int index, char *str, va_list args,
                        int *n, flags *opt);
int take_int(int *index, const char *format);
void print_d(char *str, va_list args, int *n, flags *opt);
long long int len_of_int(long long int x);
void paste_int(char *str_part, int *i, long long int len,
               long long int argument);
void print_int(char *str, int *n, flags *opt, long long int argument_ll);
void print_u(char *str, va_list args, int *n, flags *opt);
void print_unsigned_int(char *str, int *n, flags *opt,
                        unsigned long long int argument_ll);
void print_c(char *str, va_list args, int *n, flags *opt);
void print_s(char *str, va_list args, int *n, flags *opt);

#endif  // SRC_S21_STRING_H_
