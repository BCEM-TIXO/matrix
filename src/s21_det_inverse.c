#include "s21_matrix.h"

double calc_det(matrix_t *A) {
  double det = 0;
  matrix_t tmp_minor = {0};
  int sign = 1;
  if (A->columns == 1) {
    det = A->matrix[0][0];
  } else if (A->columns == 2) {
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    s21_create_matrix(A->rows - 1, A->rows - 1, &tmp_minor);
    for (int i = 0; i < A->rows; i++) {
      create_minor(A, &tmp_minor, i, 0);
      det += sign * A->matrix[i][0] * calc_det(&tmp_minor);
      sign = -sign;
    }
    s21_remove_matrix(&tmp_minor);
  }
  return det;
}

// mem for res allocated
void create_minor(matrix_t *A, matrix_t *result, int row, int column) {
  for (int i = 0, k = 0; i < A->rows; i++, k++) {
    if (i == row) i++;
    if (i == A->rows) break;
    for (int j = 0, q = 0; j < A->columns; j++, q++) {
      if (j == column) j++;
      if (j == A->columns) break;
      result->matrix[k][q] = A->matrix[i][j];
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int status = IsQuad(A);

  if (status != kOk) {
    return status;
  }

  *result = calc_det(A);
  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = IsQuad(A);
  matrix_t tmp;
  double det = 0;
  if (status == kOk) {
    status = s21_create_matrix(A->rows, A->rows, result);
  }
  if (status == kOk) {
    if (s21_create_matrix(A->rows - 1, A->rows - 1, &tmp)) {
      result->matrix[0][0] = 1;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          create_minor(A, &tmp, i, j);
          s21_determinant(&tmp, &det);
          result->matrix[i][j] = ((i + j) % 2 ? -1 : 1) * det;
        }
      }
      s21_remove_matrix(&tmp);
    }
  }
  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  matrix_t tmp;
  int status = IsQuad(A);
  if (status != kOk) {
    return status;
  }
  if (!result) {
    return kMatrIncorrect;
  }
  status = s21_determinant(A, &det);
  if (status != kOk || fabs(det) < 1e-6) {
    return kMatrCacl;
  }
  status = s21_calc_complements(A, result);
  if (status == kOk) {
    s21_transpose(result, &tmp);
    s21_remove_matrix(result);
    s21_mult_number(&tmp, 1 / det, result);
    s21_remove_matrix(&tmp);
  }
  return status;
}