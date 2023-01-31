#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

//  Otheymal block code
START_TEST(s21_memchr_test) {
  unsigned char str1[15]="1234567890";
    ck_assert_str_eq(s21_memchr(str1, '3', 3), memchr(str1, '3', 3));
  unsigned char str2[15]="Hello world";
    ck_assert_str_eq(s21_memchr(str2, ' ', 7), memchr(str2, ' ', 7));
  unsigned char str3[15]="Hello world\0";
    ck_assert_pstr_eq(s21_memchr(str3, 'o', 1), memchr(str3, 'o', 1));
  unsigned char str4[15]="1234 67890";
    ck_assert_str_eq(s21_memchr(str4, ' ', 7), memchr(str4, ' ', 7));
  unsigned char str5[15]="a\n\0";
    ck_assert_str_eq(s21_memchr(str5, 'a', 1), memchr(str5, 'a', 1));
  unsigned char str6[15]=" \n\0";
    ck_assert_str_eq(s21_memchr(str6, ' ', 7), memchr(str6, ' ', 7));
  unsigned char str7[15]="World 67890";
    ck_assert_str_eq(s21_memchr(str7, ' ', 1), memchr(str7, ' ', 1));
  unsigned char str8[15]="167890";
    ck_assert_pstr_eq(s21_memchr("\n\0", '0', 1), memchr("\n\0", '0', 1));
  unsigned char str9[15]="1234567890";
    ck_assert_str_eq(s21_memchr(str9, '1', 6), memchr(str9, '1', 6));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char str_11[50] = "bebra";
  char str_21[50] = "aboba";
    ck_assert_int_eq(s21_memcmp(str_11, str_21, 4), memcmp(str_11, str_21), 4));
  char str_12[50] = "bebra";
  char str_22[50] = "";
    ck_assert_int_eq(s21_memcmp(str_12, str_22, 4), memcmp(str_12, str_22, 4));
  char str_13[50] = "\0";
  char str_23[50] = "aboba";
    ck_assert_int_eq(s21_memcmp(str_13, str_23, 5), memcmp(str_13, str_23, 5));
  char str_14[50] = "\n\n\n\0\n";
  char str_24[50] = "aboba";
    ck_assert_int_eq(s21_memcmp(str_14, str_24, 7), memcmp(str_14, str_24, 7));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char str11[20] = "42\0";
  char str21[20] = "Hello\0";
    ck_assert_str_eq(s21_memcpy(str11, str21, 20), memcpy(str11, str21, 20));
  char str21[20] = "a\n\0";
  char str22[20] = " \n\0";
    ck_assert_str_eq(s21_memcpy(str21, str22, 1), memcpy(str21, str22, 1));
  char str31[20] = "\0";
  char str32[20] = "\n\0";
    ck_assert_str_eq(s21_memcpy(str31, str32, 1), memcpy(str31, str32, 1));
  char str42[20] = "42";
  char str41[20] = "Hello";
    ck_assert_str_eq(s21_memcpy(str41, str42, 20), memcpy(str41, str42, 20));
}
END_TEST

START_TEST(s21_memmove_test) {
  char str1[20] = "1234567890";
    ck_assert_str_eq(s21_memmove(&str1[4], &str1[3], 3), memmove(&str1[4], &str1[3], 3));
  char str2[20] = "Hello world";
    ck_assert_str_eq(s21_memmove(&str2[4], &str2[3], 3), memmove(&str2[4], &str2[3], 3));
  char str3[20] = "Hello world\0";
    ck_assert_str_eq(s21_memmove(&str3[4], &str3[3], 3), memmove(&str3[4], &str3[3], 3));
  char str4[20] = "Hello world\n\0";
    ck_assert_str_eq(s21_memmove(&str4[4], &str4[3], 3), memmove(&str4[4], &str4[3], 3));
  char str5[20] = "a\n\0";
    ck_assert_str_eq(s21_memmove(&str5[1], &str5[1], 1), memmove(&str5[1], &str5[1], 1));
  char str6[20] = " \n\0";
    ck_assert_str_eq(s21_memmove(&str6[1], &str6[1], 1), memmove(&str6[1], &str6[1], 1));
  char str7[20] = " \0";
    ck_assert_str_eq(s21_memmove(&str7[1], &str7[1], 1), memmove(&str7[1], &str7[1], 1));
  char str8[20] = "\n\0";
    ck_assert_str_eq(s21_memmove(&str8[1], &str8[1], 1), memmove(&str8[1], &str8[1], 1));
  char str9[20] = "\0";
    ck_assert_str_eq(s21_memmove(&str9[1], &str9[1], 1), memmove(&str9[1], &str9[1], 1));
}
END_TEST

START_TEST(s21_memset_test) {
  char str1[20] = "1234567890";
    ck_assert_str_eq(s21_memset(str1, '1', 5), memset(str1, '1', 5));
  char str2[20] = "Hello world\0";
    ck_assert_str_eq(s21_memset(str2, 'H', 12), memset(str2, 'H', 12));
  char str3[20] = "Hello world\n\0";
    ck_assert_str_eq(s21_memset(str3, 'H', 12), memset(str3, 'H', 12));
  char str4[20] = "a\n\0";
    ck_assert_str_eq(s21_memset(str4, 'm', 3), memset(str4, 'H', 3));
  char str5[20] = " \n\0";
    ck_assert_str_eq(s21_memset(str5, 'm', 3), memset(str5, 'H', 3));
  char str6[20] = " \0";
    ck_assert_str_eq(s21_memset(str6, 'm', 3), memset(str6, 'H', 3));
  char str7[20] = "\n\0";
    ck_assert_str_eq(s21_memset(str7, 'm', 3), memset(str7, 'H', 3));
  char str8[3] = "\0";
    ck_assert_str_eq(s21_memset(str8, 'm', 1), memset(str8, 'H', 1));
}
END_TEST

// Vileplme block code
START_TEST(s21_strncmp_test) {
  ck_assert_int_eq(strncmp("bebra", "e", 1), s21_strncmp("bebra", "e", 1));
  ck_assert_int_eq(strncmp("bebra", "e", 6), s21_strncmp("bebra", "e", 6));
  ck_assert_int_eq(strncmp("bebra", "e", 0), s21_strncmp("bebra", "e", 0));
  ck_assert_int_eq(strncmp("bebra", "Z", 10), s21_strncmp("bebra", "Z", 10));
  ck_assert_int_eq(strncmp("", "abe", 10), s21_strncmp("", "abe", 10));
  ck_assert_int_eq(strncmp("", "", 10), s21_strncmp("", "", 10));
  ck_assert_int_eq(strncmp("bebra", "bebra", 10),
                   s21_strncmp("bebra", "bebra", 10));
  ck_assert_int_eq(strncmp("abo\0ba", "abo\0aa", 10),
                   s21_strncmp("abo\0ba", "abo\0aa", 10));
  ck_assert_int_eq(strncmp("aBoba", "b", 10), s21_strncmp("aBoba", "b", 10));


START_TEST(s21_strcmp_test) {
  ck_assert_int_gt(strcmp("abob3a", "abo\nba"), 0);
  ck_assert_int_gt(s21_strcmp("abob3a", "abo\nba"), 0);
  ck_assert_int_le(strcmp("\n\0\0\0", "\n\n\0"), 0);
  ck_assert_int_le(s21_strcmp("\n\0\0\0", "\n\n\0"), 0);
  ck_assert_int_le(strcmp("", "\n\n\0"), 0);
  ck_assert_int_le(s21_strcmp("", "\n\n\0"), 0);
  ck_assert_int_gt(strcmp("abob3a", ""), 0);
  ck_assert_int_gt(s21_strcmp("abob3a", ""), 0);
  ck_assert_int_eq(strcmp("", ""), s21_strcmp("", ""));
  ck_assert_int_eq(strcmp("bebra", "bebra"), s21_strcmp("bebra", "bebra"));
  ck_assert_int_eq(strcmp("abo\0ba", "abo\0aa"),
                   s21_strcmp("abo\0ba", "abo\0aa"));
  ck_assert_int_eq(strcmp("aBoba", "b"), s21_strcmp("aBoba", "b"));
}
END_TEST

START_TEST(s21_strchr_test) {
  ck_assert_ptr_eq(s21_strchr("Hello, World!", 'l'),
                   strchr("Hello, World!", 'l'));
  ck_assert_ptr_eq(s21_strchr("Hello, World!", 'A'),
                   strchr("Hello, World!", 'A'));
  ck_assert_ptr_eq(s21_strchr("Hello, World!", 5), strchr("Hello, World!", 5));
  ck_assert_ptr_eq(s21_strchr("Hello, World!", '\0'),
                   strchr("Hello, World!", '\0'));
  ck_assert_ptr_eq(s21_strchr("", '\0'), strchr("", '\0'));
}
END_TEST

START_TEST(s21_strcat_test) {
  char str_11[50] = "bebra";
  char str_21[50] = "aboba";
    ck_assert_str_eq(strcat(str_11, str_21), s21_strcat(str_11, str_21));
  char str_12[50] = "bebra";
  char str_22[50] = "";
    ck_assert_str_eq(strcat(str_12, str_22), s21_strcat(str_12, str_22));
  char str_13[50] = "\0";
  char str_23[50] = "aboba";
    ck_assert_str_eq(strcat(str_13, str_23), s21_strcat(str_13, str_23));
  char str_14[50] = "\n\n\n\0\n";
  char str_24[50] = "aboba";
    ck_assert_str_eq(strcat(str_14, str_24), s21_strcat(str_14, str_24));
  char str_15[50] = "\n\n\n\0\n";
  char str_25[50] = "\n\0\n";
    ck_assert_str_eq(strcat(str_15, str_25), s21_strcat(str_15, str_25));
  char str_16[50] = "\0";
  char str_26[50] = "\n\0\n";
    ck_assert_str_eq(strcat(str_16, str_26), s21_strcat(str_16, str_26));
}
END_TEST

START_TEST(s21_strncat_test) {
  char str_11[50] = "bebra";
  char str_21[50] = "aboba";
    ck_assert_str_eq(strncat(str_11, str_21, 3), s21_strncat(str_11, str_21, 3));
  char str_17[50] = "bebra";
  char str_27[50] = "aboba";
    ck_assert_str_eq(strncat(str_17, str_27, 0), s21_strncat(str_17, str_27, 0));
  char str_12[50] = "bebra";
  char str_22[50] = "";
    ck_assert_str_eq(strncat(str_12, str_22, 3), s21_strncat(str_12, str_22, 3));
  char str_13[50] = "\0";
  char str_23[50] = "aboba";
    ck_assert_str_eq(strncat(str_13, str_23, 7), s21_strncat(str_13, str_23, 7));
  char str_14[50] = "\n\n\n\0\n";
  char str_24[50] = "aboba";
    ck_assert_str_eq(strncat(str_14, str_24, 2), s21_strncat(str_14, str_24, 2));
  char str_15[50] = "\n\n\n\0\n";
  char str_25[50] = "\n\0\n";
    ck_assert_str_eq(strncat(str_15, str_25, 1), s21_strncat(str_15, str_25, 1));
  char str_16[50] = "\0";
  char str_26[50] = "\n\0\n";
    ck_assert_str_eq(strncat(str_16, str_26, 0), s21_strncat(str_16, str_26, 0));
}
END_TEST

START_TEST(s21_sprintf_test) {
  char str1[2048];
  char str2[2048];
  int rv1;
  int rv2;
    rv1 = sprintf(str1, "|%-20.5s% 15dA", "abacaba12345", -123);
    rv2 = s21_sprintf(str2, "|%-20.5s% 15dA", "abacaba12345", -123);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%0lu%%%15hd", (long unsigned int)1234567, -123);
    rv2 = s21_sprintf(str2, "%0lu%%%15hd", (long unsigned int)1234567, -123);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%d%ld%lld%hd", (int)99999999999,(long int)99999999999,(long long int)99999999999,(short int)99999999999);
    rv2 = s21_sprintf(str2, "%d%ld%lld%hd", 99999999999,99999999999,99999999999,99999999999);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%20d%10ld%5lld%33hd", (int)99999999999,(long int)99999999999,(long long int)99999999999,(short int)99999999999);
    rv2 = s21_sprintf(str2, "%20d%10ld%5lld%33hd", 99999999999,99999999999,99999999999,99999999999);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%+d% ld%-20lld%-10hd", (int)99999999999,(long int)99999999999,(long long int)99999999999,(short int)99999999999);
    rv2 = s21_sprintf(str2, "%+d% ld%-20lld%-10hd", 99999999999,99999999999,99999999999,99999999999);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%-.3s%2c%i", "aboba",'\t', 12345);
    rv2 = s21_sprintf(str2, "%-.3s%2c%i", "aboba", '\t', 12345);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%-15.3s%-23c%i", "aboba",'A', 12345);
    rv2 = s21_sprintf(str2, "%-15.3s%-23c%i", "aboba", 'A', 12345);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%s%c%i", "aboba",'\t', 12345);
    rv2 = s21_sprintf(str2, "%s%c%i", "aboba", '\t', 12345);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%+5d", 25);
    rv2 = s21_sprintf(str2, "%+5d", 25);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    char *null = S21_NULL;
    rv1 = sprintf(str1, "%s", null);
    rv2 = s21_sprintf(str2, "%s", null);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%15s", "bebra");
    rv2 = s21_sprintf(str2, "%15s", "bebra");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%+-15d", 15);
    rv2 = s21_sprintf(str2, "%+-15d", 15);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%15u%lu%-llu%15hu", (unsigned int)123, (long unsigned int)54345, (long long unsigned int)34354, (short int)534435);
    rv2 = s21_sprintf(str2, "%15u%lu%-llu%15hu", 123, 54345, 34354, 534435);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "%-15u%lu%-llu%15hu", (unsigned int)123, (long unsigned int)54345, (long long unsigned int)34354, (short int)534435);
    rv2 = s21_sprintf(str2, "%-15u%lu%-llu%15hu", 123, 54345, 34354, 534435);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
    rv1 = sprintf(str1, "% -15d", 15);
    rv2 = s21_sprintf(str2, "% -15d", 15);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(rv1, rv2);
}
END_TEST

// Errokele block code
START_TEST(s21_strcspn_test) {
  char s01[] = "test started";
  char s02[] = "start";
    ck_assert_int_eq(strcspn(s01, s02), s21_strcspn(s01, s02));
  char s11[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s12[] = "Hello, world!";
    ck_assert_int_eq(strcspn(s11, s12), s21_strcspn(s11, s12));
  char s21[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s22[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
    ck_assert_int_eq(strcspn(s21, s22), s21_strcspn(s21, s22));
  char s31[] = "v";
  char s32[] = "vendetta";
    ck_assert_int_eq(strcspn(s31, s32), s21_strcspn(s31, s32));
  char s41[] = "";
  char s42[] = "Hello, world!";
    ck_assert_int_eq(strcspn(s41, s42), s21_strcspn(s41, s42));
  char s51[] = "Hello, world!";
  char s52[] = "";
    ck_assert_int_eq(strcspn(s51, s52), s21_strcspn(s51, s52));
  char s61[] = "6";
  char s62[] = "67";
    ck_assert_int_eq(strcspn(s61, s62), s21_strcspn(s61, s62));
  char s71[] = "69917020";
  char s72[] = "69917020";
    ck_assert_int_eq(strcspn(s71, s72), s21_strcspn(s71, s72));
  char s81[] = "69917020";
  char s82[] = "69917020";
    ck_assert_int_eq(strcspn(s81, s82), s21_strcspn(s81, s82));
  char s91[] = "699";
  char s92[] = "69917020";
    ck_assert_int_eq(strcspn(s91, s92), s21_strcspn(s91, s92));
  char s111[] = "69917020";
  char s112[] = "699";
    ck_assert_int_eq(strcspn(s111, s112), s21_strcspn(s111, s112));
  char s121[] = "";
  char s122[] = "";
    ck_assert_int_eq(strcspn(s121, s122), s21_strcspn(s121, s122));
}
END_TEST

START_TEST(s21_strlen_test) {
  ck_assert_int_eq(strlen("213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 \"\"21"), s21_strlen("213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 \"\"21"));
  ck_assert_int_eq(strlen("Hello, world!"), s21_strlen("Hello, world!"));
  ck_assert_int_eq(strlen("\0"), s21_strlen("\0"));
  ck_assert_int_eq(strlen("I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!"), s21_strlen("I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!"));
  ck_assert_int_eq(strlen(""), s21_strlen(""));
  ck_assert_int_eq(strlen("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"), s21_strlen("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"));
  ck_assert_int_eq(strlen("          00000000           ......  "), s21_strlen("          00000000           ......  "));
  ck_assert_int_eq(strlen("\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n"), s21_strlen("\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n"));
  ck_assert_int_eq(strlen("\0\0\0\0\n"), s21_strlen("\0\0\0\0\n"));
  ck_assert_int_eq(strlen("\t\t"), s21_strlen("\t\t"));
  ck_assert_int_eq(strlen("\0test"), s21_strlen("\0test"));
  ck_assert_int_eq(strlen("wtf \0 wtf"), s21_strlen("wtf \0 wtf"));
}
END_TEST

START_TEST(s21_strcpy_test){
  char str11[100] = "testing_this";
  char str12[] = "testing_this";
  char str13[100] = "testing_this";
    ck_assert_pstr_eq(strcpy(str11, str12), s21_strcpy(str13, str12));
  char str21[100] = "testing\nthis";
  char str22[] = "testing_this";
  char str23[100] = "testing\nthis";
    ck_assert_pstr_eq(strcpy(str21, str22), s21_strcpy(str23, str22));
  char str31[100] = "testing\0this";
  char str32[] = "testing_this";
  char str33[100] = "testing\0this";
    ck_assert_pstr_eq(strcpy(str31, str32), s21_strcpy(str33, str32));
  char str41[100] = "testing_this";
  char str42[] = "testing\0this";
  char str43[100] = "testing_this";
    ck_assert_pstr_eq(strcpy(str41, str42), s21_strcpy(str43, str42));
  char str51[100] = "\0";
  char str52[] = "testing_this";
  char str53[100] = "\0";
    ck_assert_pstr_eq(strcpy(str51, str52), s21_strcpy(str53, str52));
  char str61[100] = "testing_this";
  char str62[] = "\0";
  char str63[100] = "testing_this";
    ck_assert_pstr_eq(strcpy(str61, str62), s21_strcpy(str63, str62));
  char str71[100] = " ";
  char str72[] = "";
  char str73[100] = " ";
    ck_assert_pstr_eq(strcpy(str71, str72), s21_strcpy(str73, str72));
  char str81[100] = "";
  char str82[] = " ";
  char str83[100] = "";
    ck_assert_pstr_eq(strcpy(str81, str82), s21_strcpy(str83, str82));
  char str91[100] = "this\0\0\0";
  char str92[] = "\0this\0";
  char str93[100] = "this\0\0\0";
    ck_assert_pstr_eq(strcpy(str91, str92), s21_strcpy(str93, str92));
  char str101[100] = "thi00s";
  char str102[] = "\0testing_this";
  char str103[100] = "thi00s";
    ck_assert_pstr_eq(strcpy(str101, str102), s21_strcpy(str103, str102));
}
END_TEST

START_TEST(s21_strncpy_test){
  char s11[20] = "Hello, world!";
  char s12[20] = "Hello, world!";
  char s13[] = "Good";
  size_t n = 5;
    ck_assert_pstr_eq(strncpy(s11, s13, n), s21_strncpy(s12, s13, n));
  char s21[20] = "Hello, world!";
  char s22[20] = "Hello, world!";
  char s23[] = "\0";
  n = 1;
    ck_assert_pstr_eq(strncpy(s21, s23, n), s21_strncpy(s22, s23, n));
  char s31[30] = "Hello, world!";
  char s32[30] = "Hello, world!";
  char s33[] = "fг-аг-аг";
  n = 1;
    ck_assert_pstr_eq(strncpy(s31, s33, n), s21_strncpy(s32, s33, n));
  char s41[5] = "";
  char s42[5] = "";
  char s43[] = "";
  n = 0;
    ck_assert_pstr_eq(strncpy(s41, s43, n), s21_strncpy(s42, s43, n));
  char s51[70] = "";
  char s52[70] = "";
  char s53[] =
       "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  n = strlen(s53);
    ck_assert_pstr_eq(strncpy(s51, s53, n), s21_strncpy(s52, s53, n));
  char s61[5] = "";
  char s62[5] = "";
  char s63[] = "\0";
  n = 1;
    ck_assert_pstr_eq(strncpy(s61, s63, n), s21_strncpy(s62, s63, n));
}
END_TEST

START_TEST(s21_strerror_test){
  for (int i = 0; i < 150; i++) {
      ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

//  Zasteran block code
START_TEST(s21_memchr_test) {

}
END_TEST

START_TEST(s21_memcmp_test) {

}
END_TEST

START_TEST(s21_memcpy_test) {

}
END_TEST

START_TEST(s21_memmove_test) {

}
END_TEST

START_TEST(s21_memset_test) {

}
END_TEST


int main() {
  Suite *suite = suite_create("S21_STRING");
  SRunner *srunner = srunner_create(suite);
// otheymal block code
  TCase *s21_memchr_tcase = tcase_create("s21_memchr_test");
  suite_add_tcase(suite, s21_memchr_tcase);
  tcase_add_test(s21_memchr_tcase, s21_memchr_test);

  TCase *s21_memcmp_tcase = tcase_create("s21_memcmp_test");
  suite_add_tcase(suite, s21_memcmp_tcase);
  tcase_add_test(s21_memcmp_tcase, s21_memcmp_test);

  TCase *s21_memcpy_tcase = tcase_create("s21_memcpy_test");
  suite_add_tcase(suite, s21_memcpy_tcase);
  tcase_add_test(s21_memcpy_tcase, s21_memcpy_test);

  TCase *s21_memmove_tcase = tcase_create("s21_memmove_test");
  suite_add_tcase(suite, s21_memmove_tcase);
  tcase_add_test(s21_memmove_tcase, s21_memmove_test);

  TCase *s21_memset_tcase = tcase_create("s21_memset_test");
  suite_add_tcase(suite, s21_memset_tcase);
  tcase_add_test(s21_memset_tcase, s21_memset_test);
// Vileplme block code
  TCase *s21_sprintf_tcase = tcase_create("s21_sprintf_test");
  suite_add_tcase(suite, s21_sprintf_tcase);
  tcase_add_test(s21_sprintf_tcase, s21_sprintf_test);

  TCase *s21_strncmp_tcase = tcase_create("s21_strncmp_test");
  suite_add_tcase(suite, s21_strncmp_tcase);
  tcase_add_test(s21_strncmp_tcase, s21_strncmp_test);

  TCase *s21_strcmp_tcase = tcase_create("s21_strcmp_test");
  suite_add_tcase(suite, s21_strcmp_tcase);
  tcase_add_test(s21_strcmp_tcase, s21_strcmp_test);

  TCase *s21_strchr_tcase = tcase_create("s21_strchr_test");
  suite_add_tcase(suite, s21_strchr_tcase);
  tcase_add_test(s21_strchr_tcase, s21_strchr_test);

  TCase *s21_strcat_tcase = tcase_create("s21_strcat_test");
  suite_add_tcase(suite, s21_strcat_tcase);
  tcase_add_test(s21_strcat_tcase, s21_strcat_test);

  TCase *s21_strncat_tcase = tcase_create("s21_strncat_test");
  suite_add_tcase(suite, s21_strncat_tcase);
  tcase_add_test(s21_strncat_tcase, s21_strncat_test);
// Errokele block code
  TCase *s21_strcspn_tcase = tcase_create("s21_strcspn_test");
  suite_add_tcase(suite, s21_strcspn_tcase);
  tcase_add_test(s21_strcspn_tcase, s21_strcspn_test);

  TCase *s21_strlen_tcase = tcase_create("s21_strlen_test");
  suite_add_tcase(suite, s21_strlen_tcase);
  tcase_add_test(s21_strlen_tcase, s21_strlen_test);

  TCase *s21_strcpy_tcase = tcase_create("s21_strcpy_test");
  suite_add_tcase(suite, s21_strcpy_tcase);
  tcase_add_test(s21_strcpy_tcase, s21_strcpy_test);

  TCase *s21_strncpy_tcase = tcase_create("s21_strncpy_test");
  suite_add_tcase(suite, s21_strncpy_tcase);
  tcase_add_test(s21_strncpy_tcase, s21_strncpy_test);

  TCase *s21_strerror_tcase = tcase_create("s21_strerror_test");
  suite_add_tcase(suite, s21_strerror_tcase);
  tcase_add_test(s21_strerror_tcase, s21_strerror_test);

// Zasteran block code
  TCase *s21_strpbrk_tcase = tcase_create("s21_strpbrk_test");
  suite_add_tcase(suite, s21_strpbrk_tcase);
  tcase_add_test(s21_strpbrk_tcase, s21_strpbrk_test);

  TCase *s21_strrchr_tcase = tcase_create("s21_strrchr_test");
  suite_add_tcase(suite, s21_strrchr_tcase);
  tcase_add_test(s21_strrchr_tcase, s21_strrchr_test);

  TCase *s21_strspn_tcase = tcase_create("s21_strspn_test");
  suite_add_tcase(suite, s21_strspn_tcase);
  tcase_add_test(s21_strspn_tcase, s21_strspn_test);

  TCase *s21_strstr_tcase = tcase_create("s21_strstr_test");
  suite_add_tcase(suite, s21_strstr_tcase);
  tcase_add_test(s21_strstr_tcase, s21_strstr_test);

  TCase *s21_strtok_tcase = tcase_create("s21_strtok_test");
  suite_add_tcase(suite, s21_strtok_tcase);
  tcase_add_test(s21_strtok_tcase, s21_strtok_test);

  srunner_run_all(srunner, CK_VERBOSE);
  srunner_free(srunner);

  return 0;
}

