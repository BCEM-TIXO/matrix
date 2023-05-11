#include "s21_tests.h"

START_TEST(test1) {
  matrix_t A;
  matrix_t B;
  double mat[] = {1.4, 2, 3, -4, 5, 6};
  int errorA = s21_create_matrix(3, 2, &A);
  int errorB = s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  enter_matrix_double(&A, mat);
  enter_matrix_double(&B, mat);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  matrix_t B;
  int errorA = s21_create_matrix(3, 3, &A);
  int errorB = s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  matrix_t B;
  double matA[] = {1.4, 2, 3, -4, 5, 6};
  double matB[] = {1.4, 2, 3, -4, -15, 6};
  int errorA = s21_create_matrix(3, 2, &A);
  int errorB = s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  enter_matrix_double(&A, matA);
  enter_matrix_double(&B, matB);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  double matA[] = {1.4, 2, 3, -4, 5, 6};
  double matB[] = {1.4, 2, 3, -4, -15, 6};
  int errorA = s21_create_matrix(3, 2, &A);
  int errorB = s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  enter_matrix_double(&A, matA);
  enter_matrix_double(&B, matB);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_eq_matrix(NULL, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(NULL, NULL), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_eq(void) {
  Suite *s = suite_create("suite_eq");
  TCase *tc = tcase_create("eq_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  suite_add_tcase(s, tc);

  return s;
}