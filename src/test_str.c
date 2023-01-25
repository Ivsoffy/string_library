
#include <stdio.h>
#include <string.h>

int main() {
  char *src = "Take the test.";
  char dst[14 + 1]; 
//   printf("%s\n", strncpy(dst, src, 10));
  dst[0] = 'M';
  dst[4] = '\0';
//   printf("%s\n", dst);
//   printf("%d", strlen(dst));

  const char *string = "abcde312$#@";
  const char *invalid = "*$#";
  size_t valid_len = strcspn(string, invalid);
  if(valid_len != strlen(string))
  printf("'%s' contains invalid chars starting at position %zu\n",
               string, valid_len);

  return 0;
}

