#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

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
}
END_TEST

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

int main() {
  Suite *suite = suite_create("S21_STRING");
  SRunner *srunner = srunner_create(suite);

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

  srunner_run_all(srunner, CK_VERBOSE);
  srunner_free(srunner);

  return 0;
}
