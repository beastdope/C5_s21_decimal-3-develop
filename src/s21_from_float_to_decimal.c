#include "s21_decimal.h"

/**
 * Функция `s21_from_float_to_decimal` преобразует число с плавающей запятой в
 * десятичное представление с указанной точностью.
 *
 * @param dst Параметр dst — это указатель на структуру s21_decimal, в которой
 * будет храниться преобразованное десятичное значение.
 * @param input Параметр `input` в предоставленной функции
 * `s21_from_float_to_decimal` представляет собой число с плавающей запятой,
 * которое вы хотите преобразовать в десятичное представление, хранящееся в
 * структуре `s21_decimal`, на которую указывает `dst`.
 *
 * @return целочисленное значение. Если функция выполняется успешно и не
 * сталкивается с какими-либо проблемами, она возвращает 0. Если есть какие-либо
 * проблемы, например, входные данные имеют значение NaN, бесконечны или
 * превышают определенный порог, она вернет 1.
 */
int s21_from_float_to_decimal(s21_decimal* dst, float input) {
  s21_decl_to_null(dst);
  if (isnan(input) || isinf(input) || fabs(input) > MAX_DECIMAL) return 1;
  if (input < 0) {
    s21_set_sign_31(1, dst);
    input *= -1;
  }
  char str[100];
  int numChars = sprintf(str, "%.*g", 7, input);
  str[numChars] = '\0';
  char* ost;
  float res = strtof(str, &ost);
  int resint = (int)res;
  int scale = 0;
  while (res - (float)resint) {
    res *= 10;
    resint = (int)res;
    scale += 1;
  }
  s21_set_scale_ratio_16_23(scale, dst);
  dst->bits[0] = (int32_t)res;
  return 0;
}