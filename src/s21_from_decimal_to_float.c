#include "s21_decimal.h"

/**
 * Функция преобразует десятичное число в число с плавающей запятой.
 *
 * @param src Предоставленная вами функция `s21_from_decimal_to_float`, похоже,
 * преобразует десятичное число в пользовательском формате в число с плавающей
 * запятой. Функция принимает на вход тип `s21_decimal`, который не определен в
 * предоставленном вами фрагменте кода.
 * @param dst Функция s21_from_decimal_to_float принимает исходное значение
 * s21_decimal и преобразует его в значение с плавающей запятой, которое затем
 * сохраняется в переменной dst. Функция возвращает целочисленное значение
 * статуса.
 *
 * @return Функция s21_from_decimal_to_float возвращает целочисленное значение,
 * которое хранится в переменной status.
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = 0;
  *dst = 0;
  if (dst == NULL) {
  } else {
    int minus = 1;
    long double result = 0, two = 1;
    int exp = s21_get_scale_ratio_16_23(src);
    if (s21_get_sign_31(src) == 1) minus = -1;
    for (int k = 0; k < 96; k++) {
      if (s21_check_bit(k, &src)) {
        result += two;
      }
      two *= 2;
    }
    for (int k = 0; k < exp; k++) {
      result /= 10;
    }
    *dst = minus * result;
  }
  return status;
}
