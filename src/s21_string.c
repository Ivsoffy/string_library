#include "s21_string.h"

// int main(){
//   printf("%s", s21_strerror(134));
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

char* s21_strerror(int errnum) {
    char* err[] = ERRORLIST;
    static char rez[100];
    int max = (*err[0]=='S') ? 133 : 106;
    if (errnum >= 0 && errnum <= max) {
        s21_strcpy(rez, err[errnum]);
    } else {
        s21_sprintf(rez, "%s%d", "Unknown error: ", errnum); //change to s21_spintf
    }
    return rez;
}

