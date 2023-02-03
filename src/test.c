#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

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
    //sprintf_f
    char str11[200];
    char str12[200];
    char *str13 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str11, str13, num, num, num, num, num),
                   s21_sprintf(str12, str13, num, num, num, num, num));
  ck_assert_pstr_eq(str11, str12);
  char str21[200];
  char str22[200];
  char *str23 = "%f TEST %.f TEST %3f TEST %4.f TEST %5.10f!";
  num = -76.756589367;
  ck_assert_int_eq(sprintf(str21, str23, num, num, num, num, num),
                   s21_sprintf(str22, str23, num, num, num, num, num));
  ck_assert_pstr_eq(str21, str22);
  char str41[400];
  char str42[400];
  char *str43 = "%20.10f\n%20.15f\n%-20.5f!";
  num = -76.756589;
  ck_assert_int_eq(sprintf(str41, str43, num, num, num),
                   s21_sprintf(str42, str43, num, num, num));
  ck_assert_pstr_eq(str41, str42);
  char str61[400];
  char str62[400];
  char *str63 = "test: %5f\ntest: %6.1f\ntest: %8.2f!";
  num = 76.756589;
  ck_assert_int_eq(sprintf(str61, str63, num, num, num),
                   s21_sprintf(str62, str63, num, num, num));
  ck_assert_pstr_eq(str61, str62);
  char str71[400];
  char str72[400];
  char *str73 = "test: %10.5f\ntest: %12.4f!";
  num = 76.756589;
  ck_assert_int_eq(sprintf(str71, str73, num, num),
                   s21_sprintf(str72, str73, num, num));
  ck_assert_pstr_eq(str71, str72);
  char str81[400];
  char str82[400];
  char *str83 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str81, str83, num, num, num),
                   s21_sprintf(str82, str83, num, num, num));
  ck_assert_pstr_eq(str81, str82);
  char str91[400];
  char str92[400];
  char *str93 = "test: %10.4f\ntest: %25.5f!";
  num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str91, str93, num, num),
                   s21_sprintf(str92, str93, num, num));
  ck_assert_pstr_eq(str91, str92);
  char str121[400];
  char str122[400];
  char *str123 = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str121, str123, num, num, num),
                   s21_sprintf(str122, str123, num, num, num));
  ck_assert_pstr_eq(str121, str122);
  char str151[400];
  char str152[400];
  char *str153 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
  num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str151, str153, num, num, num),
                   s21_sprintf(str152, str153, num, num, num));
  ck_assert_pstr_eq(str151, str152);
  char str171[400];
  char str172[400];
  char *str173 = "test: %15.13f!\ntest: %26.15f!";
  num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str171, str173, num, num),
                   s21_sprintf(str172, str173, num, num));
  ck_assert_pstr_eq(str171, str172);
  char str181[400];
  char str182[400];
  char *str183 = "test: %18.7f!\ntest: %10.15f!\ntest: %25.15f!";
  num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str181, str183, num, num, num),
                   s21_sprintf(str182, str183, num, num, num));
  ck_assert_pstr_eq(str181, str182);
  char str191[400];
  char str192[400];
  char *str193 = "test: %15.13f!\ntest: %26.15f!";
  num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str191, str193, num, num),
                   s21_sprintf(str192, str193, num, num));
  ck_assert_pstr_eq(str191, str192);
  char str201[400];
  char str202[400];
  char *str203 = "test: %18.7f!\ntest: %10.15f!";
  num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str201, str203, num, num),
                   s21_sprintf(str202, str203, num, num));
  ck_assert_pstr_eq(str201, str202);
  char str211[400];
  char str212[400];
  char *str213 = "test: %- 23.14f!\ntest: %+ 25.15f!";
  num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str211, str213, num, num),
                   s21_sprintf(str212, str213, num, num));
  ck_assert_pstr_eq(str1, str2);
  char str221[400];
  char str222[400];
  char *str223 = "test: % 15f!\ntest: % -26f!\ntest: %- 18f!";
  num = -365789.34;
  ck_assert_int_eq(sprintf(str221, str223, num, num, num),
                   s21_sprintf(str222, str223, num, num, num));
  ck_assert_pstr_eq(str1, str2);
//   char str231[400];
//   char str232[400];
//   char *str233 = "test: %+- 14f!\ntest: %+ 10f!\ntest: % +25f!";
//   num = -365789.34;
//   ck_assert_int_eq(sprintf(str231, str232, num, num, num),
//                    s21_sprintf(str232, str233, num, num, num));
//   ck_assert_pstr_eq(str231, str232);

  char str241[400];
  char str242[400];
  char *str243 = "test: % 14f!\ntest: % -27f!\ntest: %- 19f!";
  num = 365789.34;
  ck_assert_int_eq(sprintf(str241, str243, num, num, num),
                   s21_sprintf(str242, str243, num, num, num));
  ck_assert_pstr_eq(str241, str242);
  char str251[400];
  char str252[400];
  char *str253 = "test: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
  num = 365789.34;
  ck_assert_int_eq(sprintf(str251, str253, num, num, num),
                   s21_sprintf(str252, str253, num, num, num));
  ck_assert_pstr_eq(str251, str252);

  char str261[400];
  char str262[400];
  char *str263 = "fshgkaljck% 10.12f hgsakul";
  num = 0.235300;
  ck_assert_int_eq(sprintf(str261, str263, num), s21_sprintf(str262, str263, num));
  ck_assert_pstr_eq(str261, str262);
}
END_TEST


int main() {
    Suite *suite = suite_create("S21_STRING");
    SRunner *srunner = srunner_create(suite);

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

    TCase *s21_sprintf_tcase = tcase_create("s21_sprintf_test");
    suite_add_tcase(suite, s21_sprintf_tcase);
    tcase_add_test(s21_sprintf_tcase, s21_sprintf_test);



    srunner_run_all(srunner, CK_VERBOSE);
    srunner_free(srunner);

    return 0;
}
