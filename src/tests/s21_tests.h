#ifndef SRC_TESTS_S21_TESTS_H_
#define SRC_TESTS_S21_TESTS_H_

#include <check.h>

#include "../s21_matrix.h"

Suite *suite_manage();

Suite *suite_eq();

Suite *suite_arifmethic(void);

Suite *suite_transpose();

Suite *suite_calc_complements();

Suite *suite_determinant();

Suite *suite_inverse();

#endif  // SRC_TESTS_S21_TESTS_H_
