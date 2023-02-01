#include "./s21_string.h"

// otheymal block code
void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *rez = S21_NULL;
  int breakFlag = 0;
  for (s21_size_t i = 0; i < n && breakFlag == 0; i++) {
    if (*((char *)str + i) == c) {
      rez = (char *)str + i;
      breakFlag = 1;
    }
  }
  return rez;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int rez = 0;
  for (s21_size_t i = 0; i < n; i++) {
    rez = *s1 - *s2;
    if (*s1 != *s2)
      break;
    s1++;
    s2++;
  }
  return rez;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *startDest = dest;
  char *ptrdest = dest;
  const char *ptrsrc = src;
  while (n--) {
    *ptrdest = *ptrsrc;
    ptrdest++;
    ptrsrc++;
  }
  return startDest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *ptrdest = dest;
  const char *ptrsrc = src;
  s21_size_t i;
  for (i = 0; i < n; i++) {
    ptrdest[i] = ptrsrc[i];
  }
  return ptrdest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *istr = str;
  int i = 0;
  while (n > 0) {
    istr[i] = c;
    i++;
    n--;
  }
  return istr;
}

// Vileplme block code
int s21_strcmp(const char *str1, const char *str2) {
  unsigned char *str_1 = (unsigned char *)str1;
  unsigned char *str_2 = (unsigned char *)str2;
  for (; *str_1 && *str_1 == *str_2; str_1++, str_2++)
    ;
  return *str_1 - *str_2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int rv = 0;
  char *str_1 = (char *)str1;
  char *str_2 = (char *)str2;
  for (s21_size_t i = 0; i < n && *str_1 && *str_1 == *str_2;
       str_1++, str_2++, i++)
    ;
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

// Errokele block code
char *s21_strcpy(char *dest, const char *src) {
  char *cp = dest;
  while (*src) {
    *(dest++) = *(src++);
  }
  *dest = '\0';
  return cp;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *cp = dest;
  int i = 0;
  while (i < (int)n) {
    if (*(src)) {
      *(dest++) = *(src++);
    } else {
      *(dest++) = '\0';
    }
    i++;
  }
  return cp;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (*(str++)) {
    len++;
  }
  return len;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t rez = 0;
  s21_size_t cnt = 0;
  int i = 0, j = 0;
  while ((str1[i]) && ((int)cnt != -1)) {
    j = 0;
    while ((str2[j]) && ((int)cnt != -1)) {
      if (str1[i] == str2[j]) {
        rez = cnt;
        cnt = -1;
      }
      j++;
    }
    if ((int)cnt != -1)
      cnt++;
    i++;
  }
  rez = s21_strlen(str2) ? rez : s21_strlen(str1);
  return rez;
}

char *s21_strerror(int errnum) {
  char *err[] = ERRORLIST;
  static char rez[100];
  int max = (*err[0] == 'S') ? 107 : 133;
  if (errnum > 0 && errnum <= max) {
    s21_strcpy(rez, err[errnum]);
  } else {
    sprintf(rez, "%s %d", "Unknown error:", errnum); // change to s21_spintf
  }
  return rez;
}

// Zasteran block code
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
    for (ptr2 = str2;; ptr2++) {
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
