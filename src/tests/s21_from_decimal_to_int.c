#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

#define EXPONENT_MINUS_1 2147549184   // 0b10000000000000010000000000000000
#define EXPONENT_PLUS_1 65536         // 0b00000000000000010000000000000000
#define EXPONENT_PLUS_2 196608        // 0b00000000000000110000000000000000
#define EXPONENT_MINUS_28 2149318656  // 0b10000000000111000000000000000000
#define EXPONENT_PLUS_28 1835008      // 0b00000000000111000000000000000000
#define MINUS 2147483648              // 0b10000000000000000000000000000000

START_TEST(s21_test_from_decimal_to_int_0) {
  int check, result, code;
  s21_decimal a = {{100, 0, 0, 0}};
  check = 100;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_1) {
  int check, result, code;
  s21_decimal a = {{INT_MAX, 0, 0, 0}};
  check = INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_3) {
  int result, code;
  s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, 0}};
  code = s21_from_decimal_to_int(a, &result);
  // ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_6) {
  int result, code;
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, 0, 0}};
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST
START_TEST(s21_test_from_decimal_to_int_7) {
  int result, code;
  s21_decimal a = {{S21_MAX_UINT, S21_MAX_UINT, S21_MAX_UINT, 0}};
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_9) {
  int check, result, code;
  s21_decimal a = {{INT_MAX, 0, 0, MINUS}};
  check = -INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_test_from_decimal_to_int_16) {
  int check, result, code;
  s21_decimal a;
  a.bits[0] = 0b00000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = 1;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest1) {
  s21_decimal src1;
  int result;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest2) {
  s21_decimal src1;
  int result;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_intTest11) {
  s21_decimal src1;
  int result;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 1);
}
END_TEST

TCase *s21_from_decimal_to_int_testing() {
  TCase *test_result = tcase_create("s21_from_decimal_to_int_testing");
  tcase_add_test(test_result, s21_test_from_decimal_to_int_0);
  tcase_add_test(test_result, s21_test_from_decimal_to_int_1);
  tcase_add_test(test_result, s21_test_from_decimal_to_int_3);
  tcase_add_test(test_result, s21_test_from_decimal_to_int_6);
  tcase_add_test(test_result, s21_test_from_decimal_to_int_7);
  tcase_add_test(test_result, s21_test_from_decimal_to_int_9);
  tcase_add_test(test_result, s21_test_from_decimal_to_int_16);
  tcase_add_test(test_result, s21_from_decimal_to_intTest1);
  tcase_add_test(test_result, s21_from_decimal_to_intTest2);
  tcase_add_test(test_result, s21_from_decimal_to_intTest11);
  return test_result;
}
