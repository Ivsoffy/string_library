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

    srunner_run_all(srunner, CK_VERBOSE);
    srunner_free(srunner);

    return 0;
}
