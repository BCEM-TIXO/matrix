#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = kOk;
  if (result == NULL || rows <= 0 || columns <= 0) {
    return kMatrIncorrect;
  }

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) {
    status = kMatrIncorrect;
  }

  for (int i = 0; result->matrix && i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double *));
    if (result->matrix[i] == NULL) {
      s21_remove_matrix(result);
      status = kMatrIncorrect;
      break;
    }
  }

  if (status == kOk) {
    result->rows = rows;
    result->columns = columns;
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (IsCorr(A) == kOk) {
    for (int i = 0; i < A->rows && A->matrix != NULL; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
    A->matrix = NULL;
  }
}