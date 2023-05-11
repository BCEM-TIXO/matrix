#include "s21_tests.h"

START_TEST(test1) {
  matrix_t A;
  int error = s21_create_matrix(5, 4, &A);
  ck_assert_int_eq(error, kOk);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test2) {
  matrix_t A;
  int error = s21_create_matrix(-5, 4, &A);
  ck_assert_int_eq(error, kMatrIncorrect);
}
END_TEST

START_TEST(test3) {
  matrix_t A;
  int error = s21_create_matrix(5, -4, &A);
  ck_assert_int_eq(error, kMatrIncorrect);
}
END_TEST

START_TEST(test4) {
  matrix_t A;
  int error = s21_create_matrix(-5, -4, &A);
  ck_assert_int_eq(error, kMatrIncorrect);
}
END_TEST

START_TEST(test5) {
  matrix_t A;
  int error = s21_create_matrix(5, 4, &A);
  ck_assert_int_eq(error, kOk);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test6) {
  int error = s21_create_matrix(5, 4, NULL);
  ck_assert_int_eq(error, kMatrIncorrect);
}
END_TEST

Suite *suite_manage(void) {
  Suite *s = suite_create("suite_manage");
  TCase *tc = tcase_create("manage_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  suite_add_tcase(s, tc);

  return s;
}