#include "s21_matrix.h"

int IsCorr(matrix_t *A) {
  if (A != NULL && A->matrix && A->rows > 0 && A->columns > 0)
    return kOk;
  else
    return kMatrIncorrect;
}

int IsQuad(matrix_t *A) {
  int status = IsCorr(A);
  if (status == kOk && A->rows != A->columns) status = kMatrCacl;
  return status;
}

int IsSim(matrix_t *A, matrix_t *B) {
  int status = IsCorr(A) || IsCorr(B);
  if (status == kOk && !(A->rows == B->rows && A->columns == B->columns))
    status = kMatrCacl;
  return status;
}

int IsMul(matrix_t *A, matrix_t *B) {
  int status = IsCorr(A) || IsCorr(B);
  if (status == kOk && A->columns != B->rows) status = kMatrCacl;
  return status;
}

void enter_matrix_double(matrix_t *A, double *mat) {
  for (int i = 0; i < A->rows; i++) {
    memcpy(A->matrix[i], (mat + i * A->columns), A->columns * sizeof(double));
  }
}

#if defined(DEBUG)

void print_matrix(matrix_t *A) {
  if (IsCorr(A) == kOk) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) printf("%.8lf ", A->matrix[i][j]);
      printf("%c", '\n');
    }
    printf("%c", '\n');
  }
}

void enter_matrix_stdin(matrix_t *A) {
  int rows, coloms;
  scanf("%d", &rows);
  scanf("%d", &coloms);
  s21_create_matrix(rows, coloms, A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < coloms; j++) scanf("%lf", &A->matrix[i][j]);
}

#endif  // DEBUG