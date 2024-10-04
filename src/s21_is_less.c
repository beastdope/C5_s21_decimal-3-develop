#include "s21_decimal.h"

/**
 * Функция `s21_is_less` сравнивает два значения s21_decimal и возвращает 1,
 * если первое значение меньше второго значения, и 0 в противном случае.
 *
 * @param value_1 Переменная типа s21_decimal, который представляет собой
 * пользовательский тип данных, представляющий 21-битное десятичное число. Он
 * содержит массив из 4 целых чисел, каждое из которых представляет 5 бит числа.
 * @param value_2 Параметр value_2 имеет тип s21_decimal, который является
 * пользовательским типом данных. Он представляет десятичное число в
 * определенном формате. Функция s21_is_less сравнивает два значения
 * s21_decimal: value_1 и value_2.
 *
 * @return целочисленное значение. Возвращаемое значение равно 0, если первое
 * значение s21_decimal не меньше второго значения s21_decimal, и 1, если первое
 * значение s21_decimal меньше второго значения s21_decimal.
 */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal res = {0};
  s21_normalization(&value_1, &value_2, &res);
  int result = 0;  // 0 - первое не меньше второго, 1 - первое меньше второго
  int sign_1 = s21_get_sign_31(value_1);
  int sign_2 = s21_get_sign_31(value_2);
  if (sign_2 != sign_1) {
    result = sign_1 ? 1 : 0;
  } else {
    for (int i = 3; i >= 0 && result == 0; i--) {
      if (value_1.bits[i] < value_2.bits[i]) {
        result = sign_1 ? 0 : 1;
      } else if (value_1.bits[i] > value_2.bits[i]) {
        result = sign_1 ? 1 : 0;
      }
    }
  }
  return result;
}