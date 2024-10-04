#include "../s21_decimal.h"
#include "s21_decimal_tests.h"

#define PERFECT 0

START_TEST(s21_add_testing_0) {
  s21_decimal val1 = {{10, 0, 0, 0}};
  s21_decimal val2 = {{5, 0, 0, 0}};
  s21_decimal result;
  s21_decimal expected = {{15, 0, 0, 0}};

  s21_add(val1, val2, &result);

  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_add_testing_1) {
  s21_decimal val1 = {{5, 0, 0, 0}};
  s21_decimal val2 = {{5, 0, 0, 0}};
  s21_decimal result;
  s21_decimal expected = {{10, 0, 0, 0}};
  s21_add(val1, val2, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_add_testing_2) {
  s21_decimal val1 = {{5, 0, 0, 0}};
  s21_decimal val2 = {{3, 0, 0, 0}};
  s21_decimal result;
  s21_decimal expected = {{8, 0, 0, 0}};
  s21_add(val1, val2, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_add_testing_3) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal result;
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_add(val1, val2, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], expected.bits[i]);
  }
}
END_TEST

START_TEST(s21_add_testing_4) {
  s21_decimal val1 = {{10, 0, 0, 0}};
  s21_decimal val2 = {{5, 0, 0, 0}};
  s21_decimal result;
  s21_decimal expected = {{15, 0, 0, 0}};
  s21_add(val1, val2, &result);
  for (int i = 0; i < 4; i++) {
    ck_assert_uint_eq(result.bits[i], expected.bits[i]);
  }
}
END_TEST

TCase *s21_add_testing() {
  TCase *tc = tcase_create("s21_add_testing");
  tcase_add_test(tc, s21_add_testing_0);
  tcase_add_test(tc, s21_add_testing_1);
  tcase_add_test(tc, s21_add_testing_2);
  tcase_add_test(tc, s21_add_testing_3);
  tcase_add_test(tc, s21_add_testing_4);
  // Добавление остальных тестов...

  return tc;
}
