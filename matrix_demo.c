// demo of matrix arithmetic
// Cohen Robinson
// 27/06/18

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "matrix.h"

int main()
{
  double matrix_a[2][2] = {{1, 2},
                            {3, 4}
                          };
  double matrix_b[2][2] = {{4, 5},
                            {6, 7}
                          };

  // display matrix_a and matrix_b
  printf("matrix_a is :");
  m_display(2, 2, matrix_a);
  printf("matrix_b is :");
  m_display(2, 2, matrix_b);

  // firsly we add matrix_b to matrix_a
  printf("Adding matrix_a to matrix_b gives :");
  m_add(2, matrix_a, matrix_b);
  m_display(2, 2, matrix_a);

  // now we subtract matrix_b from matrix_a
  printf("Subtracting matrix_b from this result gives :");
  m_subtr(2, matrix_a, matrix_b);
  m_display(2, 2, matrix_a);

  // find the matrix product of matrix_a and matrix_b
  printf("The matrix product of matrix_a with matrix_b gives :");
  m_prod(2, matrix_a, matrix_b);
  m_display(2, 2, matrix_a);

  // the transpose of matrix_b is
  printf("The transpose of matrix_b is :");
  m_transpose(2, matrix_b);
  m_display(2, 2, matrix_b);
  m_transpose(2, matrix_b);   // to reorient the matrix

  // the trace of matrix_b is
  printf("The trace of matrix_b is : %.2f\n", m_trace(2, matrix_b));

  // define vector_a
  double vector_a[2] = {1, 2};
  printf("\nvector_a is defined by :\n");
  v_display(2, vector_a);

  // the vector-matrix product of vector_a and matrix_b
  printf("\nThe vector-matrix product of vector_a and matrix_b is :\n");
  mv_prod(2, vector_a, matrix_b);
  v_display(2, vector_a);

  // rotating matrix_c by angles a, b and c
  double angle_a = 65;
  double angle_b = 32;
  double angle_c = 0;
  double matrix_c[3][3] = {
                          {1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}
                          };
  printf("\nmatrix_c is : \n");
  m_display(3, 3, matrix_c);
  printf("rotating matrix_c by angles a = %.2f, b = %.2f, c = %.2f gives :", angle_a, angle_b, angle_c);
  m_rotate(matrix_c, angle_a, angle_b, angle_c);
  m_display(3, 3, matrix_c);

  double matrix_d[3][4] = {
                          {1, 1, 1, 5},
                          {2, 3, 5, 8},
                          {4, 0, 5, 2}
                        };
  printf("\n matrix_d is given by :");
  m_display(3, 4, matrix_d);

  printf("\nrow reducing matrix_d gives : ");
  m_rred(3, 4, matrix_d);
  m_display(3, 4, matrix_d);

  return 0;
}
