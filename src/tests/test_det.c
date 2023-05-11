#include "s21_tests.h"

START_TEST(test1) {
  matrix_t A;
  double res, expect;
  double mat[] = {1.4, 2, 3, -4, 5, 6, 2, 3, 7};
  expect = 37.8;
  int errorA = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(errorA, kOk);
  enter_matrix_double(&A, mat);
  ck_assert_int_eq(s21_determinant(&A, &res), kOk);
  ck_assert_double_eq_tol(res, expect, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  double res, expect;
  expect = 1.4;
  int errorA = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(errorA, kOk);
  A.matrix[0][0] = 1.4;
  ck_assert_int_eq(s21_determinant(&A, &res), kOk);
  ck_assert_double_eq_tol(res, expect, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  double res, expect;
  double mat[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  expect = 0;
  int errorA = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(errorA, kOk);
  enter_matrix_double(&A, mat);
  ck_assert_int_eq(s21_determinant(&A, &res), kOk);
  ck_assert_double_eq_tol(res, expect, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test4) {
  matrix_t A;
  double res;
  int errorA = s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(s21_determinant(&A, &res), kMatrCacl);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test5) {
  matrix_t A;
  double res, expect;
  expect = 0;
  int errorA = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(s21_determinant(&A, &res), kOk);
  ck_assert_double_eq_tol(res, expect, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test7) {
  double res;
  ck_assert_int_eq(s21_determinant(NULL, &res), kMatrIncorrect);
}
END_TEST

Suite *suite_determinant(void) {
  Suite *s = suite_create("suite_determinant");
  TCase *tc = tcase_create("determinant_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test7);
  suite_add_tcase(s, tc);

  return s;
}