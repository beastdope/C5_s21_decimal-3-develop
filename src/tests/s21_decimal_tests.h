#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>
#include <stdlib.h>

TCase *s21_add_testing();
TCase *s21_is_less_testing();
TCase *s21_is_greater_testing();
TCase *s21_is_greater_or_equal_testing();
TCase *s21_is_less_or_equal_testing();
TCase *s21_is_equal_testing();
TCase *s21_is_not_equal_testing();
TCase *s21_sub_testing();
TCase *s21_from_decimal_to_int_testing();
TCase *s21_from_decimal_to_float_testing();
TCase *test_from_int_to_decimal_testing();
TCase *s21_from_float_to_decimal_testing();
TCase *s21_div_testing();
TCase *s21_negate_testing();
TCase *s21_floor_testing();
TCase *s21_round_testing();
TCase *s21_truncate_testing();
TCase *s21_mul_testing();
// Дополнительные функции для создания тестов...

#endif  // S21_DECIMAL_TESTS_H
