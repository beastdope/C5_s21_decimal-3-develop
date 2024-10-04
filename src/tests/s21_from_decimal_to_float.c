#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

/**
 * Функция преобразует десятичное число в число с плавающей запятой с
 * определенным коэффициентом масштабирования.
 */
START_TEST(from_decimal_to_float_0) {
  s21_decimal number = {{123456789, 0, 0, 0}};
  s21_set_scale_ratio_16_23(5, &number);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(number, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_float_1) {
  s21_decimal number = {{12345, 0, 0, 0}};
  s21_set_scale_ratio_16_23(2, &number);
  float res = 123.45;
  float tmp = 0.;
  float *dst = &tmp;
  s21_from_decimal_to_float(number, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

TCase *s21_from_decimal_to_float_testing() {
  TCase *test_result = tcase_create("from_decimal_to_float");
  tcase_add_test(test_result, from_decimal_to_float_0);
  tcase_add_test(test_result, from_decimal_to_float_1);
  return test_result;
}