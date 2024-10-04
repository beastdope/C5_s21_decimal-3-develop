#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  memset(result, 0, sizeof(s21_decimal));
  int check = 0;
  if (s21_get_sign_31(value) == 1) {
    Plus(&value);
  } else {
    Min(&value);
  }
  *result = value;
  return check;
}