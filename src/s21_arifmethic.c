#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = IsCorr(A);
  if (status == kOk && s21_create_matrix(A->rows, A->columns, result) != kOk) {
    status = kMatrIncorrect;
  }
  for (int i = 0; status == kOk && i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;
  return status;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = IsSim(A, B);
  if (status == kOk && s21_create_matrix(A->rows, A->columns, result) != kOk) {
    status = kMatrIncorrect;
  }
  for (int i = 0; status == kOk && i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  return status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = IsSim(A, B);
  if (status == kOk && s21_create_matrix(A->rows, A->columns, result) != kOk) {
    status = kMatrIncorrect;
  }
  for (int i = 0; status == kOk && i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = IsMul(A, B);
  if (status == kOk && s21_create_matrix(A->rows, B->columns, result) != kOk) {
    status = kMatrIncorrect;
  }
  for (int i = 0; status == kOk && i < A->rows; i++)
    for (int j = 0; j < B->columns; j++)
      for (int k = 0; k < B->rows; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  return status;
}