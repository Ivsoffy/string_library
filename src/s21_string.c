#include "s21_string.h"

// int main() {
//   char *src = "Take the test.";
//   char dst[14 + 1]; 
//   // printf("%s\n", strncpy(dst, src, 10));
//   dst[0] = 'M';
//   dst[4] = '\0';
//   // printf("%s\n", dst);
//   // printf("%d", strlen(dst));
//   const char *string = "abcde312$#@";
//   const char *invalid = "*$#";
//   size_t valid_len = s21_strcspn(string, invalid);
//   if(valid_len != s21_strlen(string))
//   printf("'%s' contains invalid chars starting at position %zu\n",
//                string, valid_len);

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
  size_t cnt = 1;
  int j = 0;
  while ((*(str1++))&&((int)cnt!=-1)) {
    j = 0;
    while ((j<(int)s21_strlen(str2))&&((int)cnt!=-1)){
      if (*str1==str2[j]){
        rez = cnt;
        cnt = -1;
      }
      j++;
    }
    if ((int)cnt!=-1) cnt++;
  }
  return rez;
}

// char *strerror(int errnum){
  
// }