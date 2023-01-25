#include "s21_string.h"

int main() {
  char *src = "Take the test.";
  char dst[14 + 1]; 
  printf("%s\n", strncpy(dst, src, 10));
  dst[0] = 'M';
  dst[4] = '\0';
  printf("%s\n", dst);
  printf("%d", strlen(dst));
  const char *string = "abcde312$#@";
  const char *invalid = "*$#";
  // size_t valid_len = strcspn(string, invalid);
  // if(valid_len != strlen(string))
  // printf("'%s' contains invalid chars starting at position %zu\n",
  //              string, valid_len);

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

// size_t strcspn(const char *str1, const char *str2){
//   size_t rez = 0;
//   size_t cnt = 0;
//   const char *str = str2;
//   while (*(str1++)) {
//     *str = str2;
//     while(*str==*str1){
//       printf("%d\n", cnt);
//       printf("yes\n");
//       if (*str2=='\0'){
//         rez = cnt;
//       }
//       *(str++);
//       *(str1++);
//     }
//     cnt++;
//   }
//   return rez;
// }