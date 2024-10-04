#include "../s21_decimal.h"
#include "s21_decimal_tests.h"

START_TEST(s21_mul_test_1) {
  s21_decimal var1 = {{50, 0, 0, MINUS_KRIS}};
  unsigned int n = 1 << 16;
  s21_decimal var2 = {{32, 0, 0, n}};
  s21_decimal result = {{0, 0, 0, 0}};
  int ret = s21_mul(var1, var2, &result);
  ck_assert_int_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], 1600);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 2147549184);
}
END_TEST

START_TEST(mul_int_1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(mul_int_2) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_set_sign_31(1, &value_1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(mul_int_3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_set_sign_31(1, &value_1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(mul_int_4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_set_sign_31(1, &value_2);
  s21_set_sign_31(1, &value_1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(mul_float_1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_decimal result = {0};
  int code;
  s21_set_scale_ratio_16_23(2, &value_1);
  s21_set_scale_ratio_16_23(3, &value_2);
  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.bits[0], 46);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 327680);
}
END_TEST

START_TEST(mul_neg_inf) {
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{23, 0, 0, 0}};
  s21_set_sign_31(1, &value_1);
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);

  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(mul_one) {
  s21_decimal value_1 = {{155, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {0};
  int code;

  code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], 155);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

TCase *s21_mul_testing() {
  TCase *test_result = tcase_create("s21_mul_testing");
  tcase_add_test(test_result, s21_mul_test_1);
  tcase_add_test(test_result, mul_int_1);
  tcase_add_test(test_result, mul_int_2);
  tcase_add_test(test_result, mul_int_3);
  tcase_add_test(test_result, mul_int_4);
  tcase_add_test(test_result, mul_float_1);
  tcase_add_test(test_result, mul_neg_inf);
  tcase_add_test(test_result, mul_one);
  return test_result;
}