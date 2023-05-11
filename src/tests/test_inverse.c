#include "s21_tests.h"

START_TEST(test1) {
  matrix_t A;
  matrix_t res, expect;
  double a[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double exp[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  s21_create_matrix(3, 3, &expect);
  int errorA = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(errorA, kOk);
  enter_matrix_double(&A, a);
  enter_matrix_double(&expect, exp);
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), kOk);
  ck_assert_int_eq(s21_eq_matrix(&expect, &res), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expect);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  matrix_t res, expect;
  s21_create_matrix(1, 1, &expect);
  expect.matrix[0][0] = 0.71428571;
  int errorA = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(errorA, kOk);
  A.matrix[0][0] = 1.4;
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), kOk);
  ck_assert_int_eq(s21_eq_matrix(&res, &expect), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expect);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  matrix_t res;
  double mat[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int errorA = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(errorA, kOk);
  enter_matrix_double(&A, mat);
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), kMatrCacl);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test4) {
  matrix_t A;
  matrix_t res;
  int errorA = s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), kMatrCacl);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test5) {
  matrix_t res;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &res), kMatrIncorrect);
}
END_TEST

START_TEST(test6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), kMatrIncorrect);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test7) {
  matrix_t A;
  matrix_t res, expect;
  double mat[] = {1, 2,      3, 4,  5,        6,      7,   8,
                  9, 0.2321, 0, 31, -0.02342, 0.3223, -21, -0.000234453};
  double exp[] = {-0.94821360, 0.31611024,  0.04077308,  -0.03008901,
                  0.41858107,  0.02581231,  -0.06067119, 0.06840140,
                  0.00747867,  0.00004465,  -0.00097686, -0.04653578,
                  0.27215386,  -0.09196720, 0.02087497,  0.00822339};
  int errorA = s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &expect);
  ck_assert_int_eq(errorA, kOk);
  enter_matrix_double(&A, mat);
  enter_matrix_double(&expect, exp);
  ck_assert_int_eq(s21_inverse_matrix(&A, &res), kOk);
  ck_assert_int_eq(s21_eq_matrix(&expect, &res), kEq);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expect);
}
END_TEST

Suite *suite_inverse(void) {
  Suite *s = suite_create("suite_inverse");
  TCase *tc = tcase_create("inverse_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  suite_add_tcase(s, tc);

  return s;
}