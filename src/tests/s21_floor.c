#include "../s21_decimal.h"
#include "s21_decimal_tests.h"

START_TEST(s21_floor_test_positive_number) {
  uint32_t exp = 1 << 16;
  s21_decimal value_1 = {{34, 0, 0, exp}};
  s21_decimal result = {0};
  int ret = s21_floor(value_1, &result);
  ck_assert_uint_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], 3);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_floor_test_negative_number) {
  uint32_t exp = 1 << 16;
  s21_decimal value_1 = {{34, 0, 0, MINUS_KRIS | exp}};
  s21_decimal result = {0};
  int ret = s21_floor(value_1, &result);
  ck_assert_uint_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], 4);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], MINUS_KRIS);
}
END_TEST

TCase *s21_floor_testing() {
  TCase *test_result = tcase_create("s21_floor_testing");
  tcase_add_test(test_result, s21_floor_test_positive_number);
  tcase_add_test(test_result, s21_floor_test_negative_number);
  return test_result;
}