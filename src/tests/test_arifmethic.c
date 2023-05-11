#include "s21_tests.h"

START_TEST(test1) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t exept;
  double mat[] = {1.4, 2, 3, -4, 5, 6};
  double exp[] = {2 * 1.4, 2 * 2, 2 * 3, 2 * -4, 2 * 5, 2 * 6};
  double exp2[] = {0, 0, 0, 0, 0, 0};
  int errorA = s21_create_matrix(3, 2, &A);
  int errorB = s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 2, &exept);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  enter_matrix_double(&A, mat);
  enter_matrix_double(&B, mat);
  enter_matrix_double(&exept, exp);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), kOk);
  ck_assert_int_eq(s21_eq_matrix(&C, &exept), 1);
  s21_remove_matrix(&C);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), kOk);
  enter_matrix_double(&exept, exp2);
  ck_assert_int_eq(s21_eq_matrix(&C, &exept), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&exept);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  int errorA = s21_create_matrix(3, 3, &A);
  int errorB = s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), kMatrCacl);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), kMatrCacl);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  int errorA = s21_create_matrix(3, 2, &A);
  int errorB = s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), kMatrCacl);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t exept;
  double a[] = {1.4, 2};
  double b[] = {1.5, 2, 3, -4};
  double exp[] = {8.1, -5.2};
  int errorA = s21_create_matrix(1, 2, &A);
  int errorB = s21_create_matrix(2, 2, &B);
  s21_create_matrix(1, 2, &exept);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  enter_matrix_double(&A, a);
  enter_matrix_double(&B, b);
  enter_matrix_double(&exept, exp);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), kOk);
  ck_assert_int_eq(s21_eq_matrix(&exept, &C), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&exept);
}
END_TEST

START_TEST(test5) {
  matrix_t A;
  matrix_t C;
  matrix_t exept;
  double mat[] = {1.4, 2, 3, -4, 5, 6};
  double exp[] = {2.3 * 1.4, 2.3 * 2, 2.3 * 3, 2.3 * -4, 2.3 * 5, 2.3 * 6};
  int errorA = s21_create_matrix(3, 2, &A);
  int errorB = s21_create_matrix(3, 2, &exept);
  ck_assert_int_eq(errorA, kOk);
  ck_assert_int_eq(errorB, kOk);
  enter_matrix_double(&A, mat);
  enter_matrix_double(&exept, exp);
  ck_assert_int_eq(s21_mult_number(&A, 2.3, &C), kOk);
  ck_assert_int_eq(s21_eq_matrix(&exept, &C), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&exept);
}
END_TEST

START_TEST(test6) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), kMatrIncorrect);
  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), kMatrIncorrect);
  ck_assert_int_eq(s21_mult_matrix(NULL, &B, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), kMatrIncorrect);
  ck_assert_int_eq(s21_mult_number(NULL, 2, &C), kMatrIncorrect);
  ck_assert_int_eq(s21_mult_number(&A, 2, NULL), kMatrIncorrect);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_arifmethic(void) {
  Suite *s = suite_create("suite_arifmethic");
  TCase *tc = tcase_create("arifmethic_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  suite_add_tcase(s, tc);

  return s;
}