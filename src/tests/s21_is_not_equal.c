#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

START_TEST(s21_is_not_equal_0) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  first_number.bits[0] = 25;
  second_number.bits[0] = 25;
  ck_assert_int_eq(0, s21_is_not_equal(first_number, second_number));
}
END_TEST

START_TEST(s21_is_not_equal_1) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  ck_assert_int_eq(0, s21_is_not_equal(first_number, second_number));
}
END_TEST

START_TEST(s21_is_not_equal_2) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  first_number.bits[0] = 24;
  second_number.bits[0] = 25;
  ck_assert_int_eq(1, s21_is_not_equal(first_number, second_number));
}
END_TEST

START_TEST(s21_is_not_equal_3) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  first_number.bits[0] = 25;
  second_number.bits[0] = 24;
  ck_assert_int_eq(1, s21_is_not_equal(first_number, second_number));
}
END_TEST

TCase *s21_is_not_equal_testing() {
  TCase *test_result = tcase_create("s21_is_not_equal");
  tcase_add_test(test_result, s21_is_not_equal_0);
  tcase_add_test(test_result, s21_is_not_equal_1);
  tcase_add_test(test_result, s21_is_not_equal_2);
  tcase_add_test(test_result, s21_is_not_equal_3);
  return test_result;
}