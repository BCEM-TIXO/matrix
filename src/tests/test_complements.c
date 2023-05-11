#include "s21_tests.h"

START_TEST(test1) {
  matrix_t A;
  matrix_t res, expect;
  double a[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double exp[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  int errorA = s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expect);
  ck_assert_int_eq(errorA, kOk);
  enter_matrix_double(&A, a);
  enter_matrix_double(&expect, exp);
  ck_assert_int_eq(s21_calc_complements(&A, &res), kOk);
  ck_assert_int_eq(s21_eq_matrix(&res, &expect), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expect);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  matrix_t res, expect;
  int errorA = s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &expect);
  ck_assert_int_eq(errorA, kOk);
  A.matrix[0][0] = 1.4;
  expect.matrix[0][0] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &res), kOk);
  ck_assert_int_eq(s21_eq_matrix(&expect, &res), kEq);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expect);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  matrix_t res;
  int errorA = s21_create_matrix(1, 2, &A);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(s21_calc_complements(&A, &res), kMatrCacl);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test4) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_calc_complements(NULL, &res), kMatrIncorrect);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), kMatrIncorrect);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("calc_complements");
  TCase *tc = tcase_create("calc_complements_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  suite_add_tcase(s, tc);

  return s;
}