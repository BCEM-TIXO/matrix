#include "s21_tests.h"

START_TEST(test1) {
  matrix_t A;
  matrix_t exept;
  matrix_t res;
  int errorA = s21_create_matrix(1, 1, &A);
  int errorB = s21_create_matrix(1, 1, &exept);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  A.matrix[0][0] = 1.4;
  exept.matrix[0][0] = 1.4;
  ck_assert_int_eq(s21_transpose(&A, &res), kOk);
  ck_assert_int_eq(s21_eq_matrix(&res, &exept), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&exept);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  matrix_t exept;
  matrix_t res;
  int errorA = s21_create_matrix(1, 2, &A);
  int errorB = s21_create_matrix(2, 1, &exept);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  A.matrix[0][0] = 1.4;
  A.matrix[0][1] = 3;
  exept.matrix[0][0] = 1.4;
  exept.matrix[1][0] = 3;
  ck_assert_int_eq(s21_transpose(&A, &res), kOk);
  ck_assert_int_eq(s21_eq_matrix(&res, &exept), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&exept);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  A.columns = -1;
  ck_assert_int_eq(s21_transpose(&A, &C), kMatrIncorrect);
  A.columns = 1;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test4) {
  matrix_t A;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_transpose(NULL, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_transpose(NULL, NULL), kMatrIncorrect);
  ck_assert_int_eq(s21_transpose(&A, NULL), kMatrIncorrect);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_transpose(void) {
  Suite *s = suite_create("suite_transpose");
  TCase *tc = tcase_create("transpose_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  suite_add_tcase(s, tc);

  return s;
}