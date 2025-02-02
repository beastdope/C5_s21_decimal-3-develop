#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  int data = 0;
  int scale = s21_get_scale_ratio_16_23(src);

  if (scale + 31 < 95) {
    for (int i = scale + 31; i <= 95; ++i) {
      if (s21_get_bit(src, i)) {
        flag = 1;
      }
    }
  }

  if (!flag) {
    for (int i = scale + 30; i >= scale; --i) {
      data <<= 1;
      data |= s21_get_bit(src, i);
    }
    if (s21_get_sign_31(src)) {
      data = -data;
    }
    *dst = data;
  }
  return flag;
}
