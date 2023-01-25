#ifndef S21_STRING_H_
#define S21_STRING_H_

typedef long unsigned s21_size_t;

#define S21_NULL ((void *)0)

// Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2);

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, 
// на которую указывает аргумент str.
char *s21_strrchr(const char *str, int c);

// Вычисляет длину начального сегмента str1, который полностью состоит из символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2);

// Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), 
// которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle);

// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim);

#endif  // S21_STRING_H_