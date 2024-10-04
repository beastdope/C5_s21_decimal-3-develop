#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

#define TEST_CONVERSION_OK 0

void test_from_int_to_decimal(int number, s21_decimal decimal_check) {
  s21_decimal result;
  int code = s21_from_int_to_decimal(&result, number);

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
START_TEST(test_from_int_to_decimal_1) {
  int number = -2147483647;
  s21_decimal decimal_check = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_2) {
  int number = -2147483648;
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_3) {
  int number = -1000;
  s21_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_4) {
  int number = -214748;
  s21_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_5) {
  int number = 1;
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_6) {
  int number = -1;
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_int_to_decimal(number, decimal_check);
}

START_TEST(test_from_int_to_decimal_7) {
  int number = 0;
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_from_int_to_decimal(number, decimal_check);
}

TCase *test_from_int_to_decimal_testing() {
  TCase *test_result = tcase_create("test_from_int_to_decimal");
  tcase_add_test(test_result, test_from_int_to_decimal_1);
  tcase_add_test(test_result, test_from_int_to_decimal_2);
  tcase_add_test(test_result, test_from_int_to_decimal_3);
  tcase_add_test(test_result, test_from_int_to_decimal_4);
  tcase_add_test(test_result, test_from_int_to_decimal_5);
  tcase_add_test(test_result, test_from_int_to_decimal_6);
  tcase_add_test(test_result, test_from_int_to_decimal_7);
  return test_result;
}
