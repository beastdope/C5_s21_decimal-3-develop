#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"
#include "s21_decimal_tests.h"

START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(&val, fl1);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(&val, fl2);
  s21_from_decimal_to_float(val, &fl2_res);
  ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal val;
  s21_from_float_to_decimal(&val, 1.02E+09);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
  s21_decimal val;
  float a = 1.0 / 0.0;
  s21_from_float_to_decimal(&val, a);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

TCase *s21_from_float_to_decimal_testing() {
  TCase *test_result = tcase_create("s21_from_float_to_decimal");
  tcase_add_test(test_result, s21_from_float_to_decimal_1);
  tcase_add_test(test_result, s21_from_float_to_decimal_2);
  tcase_add_test(test_result, s21_from_float_to_decimal_3);
  return test_result;
}