#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

START_TEST(s21_round_test) {
  uint32_t exp = 2 << 16;
  s21_decimal value_1 = {{362, 0, 0, exp}};
  s21_decimal result = {0};
  int ret = s21_round(value_1, &result);
  ck_assert_uint_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], 4);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], 0);
}
END_TEST

TCase *s21_round_testing() {
  TCase *test_result = tcase_create("s21_round_testing");
  tcase_add_test(test_result, s21_round_test);
  return test_result;
}
