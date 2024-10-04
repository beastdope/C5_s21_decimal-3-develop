#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"
/**
 * Функция `s21_is_less` сравнивает два значения s21_decimal и возвращает 1,
 * если первое значение меньше второго значения, и 0 в противном случае.
 */

START_TEST(s21_is_less_0) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  ck_assert_int_eq(0, s21_is_less(first_number, second_number));
}
END_TEST

START_TEST(s21_is_less_1) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  first_number.bits[0] = 15;
  second_number.bits[0] = 16;
  ck_assert_int_eq(1, s21_is_less(first_number, second_number));
}
END_TEST

START_TEST(s21_is_less_2) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  first_number.bits[0] = 16;
  second_number.bits[0] = 16;
  ck_assert_int_eq(0, s21_is_less(first_number, second_number));
}
END_TEST

START_TEST(s21_is_less_3) {
  s21_decimal first_number = {0};
  s21_decimal second_number = {0};
  first_number.bits[0] = 17;
  second_number.bits[0] = 16;
  ck_assert_int_eq(0, s21_is_less(first_number, second_number));
}
END_TEST

TCase *s21_is_less_testing() {
  TCase *tc = tcase_create("s21_is_less_testing");
  tcase_add_test(tc, s21_is_less_0);
  tcase_add_test(tc, s21_is_less_1);
  tcase_add_test(tc, s21_is_less_2);
  tcase_add_test(tc, s21_is_less_3);
  // Добавление остальных тестов...

  return tc;
}