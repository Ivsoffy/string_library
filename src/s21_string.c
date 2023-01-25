#include "s21_string.h"

int main() {
  char *src = "Take the test.";
  char dst[14 + 1]; 
  // printf("%s\n", strncpy(dst, src, 10));
  dst[0] = 'M';
  dst[4] = '\0';
  // printf("%s\n", dst);
  // printf("%d", strlen(dst));
  const char *string = "abcde312$#@";
  const char *invalid = "*$#";
  size_t valid_len = strcspn(string, invalid);
  if(valid_len != strlen(string))
  printf("'%s' contains invalid chars starting at position %zu\n",
               string, valid_len);

  return 0;
}


char *strcpy(char *dest, const char *src) {
  char *cp = dest;
  while (*src) {
    *(dest++) = *(src++);
  }
  *dest = '\0';
  return cp;
}

char *strncpy(char *dest, const char *src, size_t n){
  char *cp = dest;
  int i = 0;
  while (i < n) {
    if (*(src)){
      *(dest++) = *(src++);
    }else{
      *(dest++) = '\0';
    }
    i++;
  }
  return cp;
}

size_t strlen(const char *str){
  size_t len = 0;
  while (*(str++)) {
    len++;
  }
  return len;
}

size_t strcspn(const char *str1, const char *str2){
  size_t rez = 0;
  size_t cnt = 1;
  int j = 0;
  while ((*(str1++))&&(cnt!=-1)) {
    printf("%d\n", cnt);
    j = 0;
    while ((j<strlen(str2))&&(cnt!=-1)){
      if (*str1==str2[j]){
        rez = cnt;
        cnt = -1;
      }
      j++;
    }
    if (cnt!=-1) cnt++;
  }
  return rez;
}