#ifndef SRC_EXTRA_H_
#define SRC_EXTRA_H_

#include "s21_matrix.h"

int IsCorr(matrix_t *A);

int IsQuad(matrix_t *A);

int IsSim(matrix_t *A, matrix_t *B);

int IsMul(matrix_t *A, matrix_t *B);

void enter_matrix_double(matrix_t *A, double *mat);

void matrix_copy(matrix_t *A, matrix_t *result);

void mat_treangle(matrix_t *A, matrix_t *result);

void create_minor(matrix_t *A, matrix_t *result, int row, int column);

double calc_det(matrix_t *A);

#ifdef DEBUG

#include <stdio.h>

void enter_matrix_stdin(matrix_t *A);

void print_matrix(matrix_t *A);

#endif  // DEBUG

#endif  // SRC_EXTRA_H_