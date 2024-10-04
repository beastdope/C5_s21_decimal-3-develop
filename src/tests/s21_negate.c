#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

START_TEST(s21_negate_test_1) {
  s21_decimal src = {{12, 12, 12, MINUS_KRIS}};
  s21_decimal dest = {0};
  int ret = s21_negate(src, &dest);
  ck_assert_uint_eq(dest.bits[3], 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_negate_test_2) {
  s21_decimal src = {{12, 12, 12, 0}};
  s21_decimal dest = {0};
  int ret = s21_negate(src, &dest);
  ck_assert_uint_eq(dest.bits[3], MINUS_KRIS);
  ck_assert_int_eq(ret, 0);
}
END_TEST

TCase *s21_negate_testing() {
  TCase *test_result = tcase_create("s21_negate_testing");
  tcase_add_test(test_result, s21_negate_test_1);
  tcase_add_test(test_result, s21_negate_test_2);
  return test_result;
}
