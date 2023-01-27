#include "s21_string.h"
#include <string.h>

// int main() {
//   char *src = "Take the test.";
//   char dst[14 + 1]; 
//   // printf("%s\n", strncpy(dst, src, 10));
//   dst[0] = 'M';
//   dst[4] = '\0';
//   // printf("%s\n", dst);
//   // printf("%d", strlen(dst));
//   const char *invalid = "Hello, world!";
//   printf("\n%ld - %ld\n", s21_strcspn("test started", "a"), strcspn("test started", "a"));

//   return 0;
// }


char *s21_strcpy(char *dest, const char *src) {
  char *cp = dest;
  while (*src) {
    *(dest++) = *(src++);
  }
  *dest = '\0';
  return cp;
}

char *s21_strncpy(char *dest, const char *src, size_t n){
  char *cp = dest;
  int i = 0;
  while (i < (int)n) {
    if (*(src)){
      *(dest++) = *(src++);
    }else{
      *(dest++) = '\0';
    }
    i++;
  }
  return cp;
}

size_t s21_strlen(const char *str){
  size_t len = 0;
  while (*(str++)) {
    len++;
  }
  return len;
}

size_t s21_strcspn(const char *str1, const char *str2){
  size_t rez = 0;
  size_t cnt = 0;
  int i = 0, j = 0;
  while ((str1[i])&&((int)cnt!=-1)) {
    j = 0;
    while ((str2[j])&&((int)cnt!=-1)){
      if (str1[i]==str2[j]){
        rez = cnt;
        cnt = -1;
      }
      j++;
    }
    if ((int)cnt!=-1) cnt++;
    i++;
  }
  rez = s21_strlen(str2) ? rez : s21_strlen(str1);
  return rez;
}

// char *strerror(int errnum){
  
// }