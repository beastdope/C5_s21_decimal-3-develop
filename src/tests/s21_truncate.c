#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

START_TEST(s21_truncate_test) {
  uint32_t exp = 2 << 16;
  s21_decimal value_1 = {{342, 0, 0, MINUS_KRIS | exp}};
  s21_decimal result = {0};
  int ret = s21_truncate(value_1, &result);
  ck_assert_uint_eq(ret, 0);
  ck_assert_uint_eq(result.bits[0], 3);
  ck_assert_uint_eq(result.bits[1], 0);
  ck_assert_uint_eq(result.bits[2], 0);
  ck_assert_uint_eq(result.bits[3], MINUS_KRIS);
}
END_TEST

TCase *s21_truncate_testing() {
  TCase *test_result = tcase_create("s21_truncate_testing");
  tcase_add_test(test_result, s21_truncate_test);
  return test_result;
}
