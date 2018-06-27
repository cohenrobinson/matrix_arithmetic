// finds the product of two square matrices
// author: Cohen Robinson
// date: 25/06/18

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void m_prod(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
void mv_prod(int dimension, double vector[dimension], double matrix[dimension][dimension]);
void m_add(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
void m_subtr(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
void m_transpose(int dimension, double matrix[dimension][dimension]);
double m_trace(int dimension, double matrix[dimension][dimension]);
void m_rotate(double matrix[3][3], double angle_a, double angle_b, double angle_c);

void m_display(int dimension, double matrix[dimension][dimension]);
void v_display(int length, double vector[length]);

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
  m_display(2, matrix_a);
  printf("matrix_b is :");
  m_display(2, matrix_b);

  // firsly we add matrix_b to matrix_a
  printf("Adding matrix_a to matrix_b gives :");
  m_add(2, matrix_a, matrix_b);
  m_display(2, matrix_a);

  // now we subtract matrix_b from matrix_a
  printf("Subtracting matrix_b from this result gives :");
  m_subtr(2, matrix_a, matrix_b);
  m_display(2, matrix_a);

  // find the matrix product of matrix_a and matrix_b
  printf("The matrix product of matrix_a with matrix_b gives :");
  m_prod(2, matrix_a, matrix_b);
  m_display(2, matrix_a);

  // the transpose of matrix_b is
  printf("The transpose of matrix_b is :");
  m_transpose(2, matrix_b);
  m_display(2, matrix_b);
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
  m_display(3, matrix_c);
  printf("rotating matrix_c by angles a = %.2f, b = %.2f, c = %.2f gives :", angle_a, angle_b, angle_c);
  m_rotate(matrix_c, angle_a, angle_b, angle_c);
  m_display(3, matrix_c);


  return 0;
}

// calculates the product of two square matrices of the same size
void m_prod(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension])
{
  // creates a zero matrix to store multiplication in
  double new_matrix[dimension][dimension];
  int l, r;
  for ( l = 0; l < dimension; l++){
    for ( r = 0; r < dimension; r++){
      new_matrix[l][r] = matrix_a[l][r];
      matrix_a[l][r] = 0;
    }
  }
  // multiplies both matrices together
  int i, k, j;
  for ( i = 0; i < dimension; i++){
    for ( k = 0; k < dimension; k++){
      for ( j = 0; j < dimension; j++){
        matrix_a[i][k] += new_matrix[i][k] * matrix_b[k][j];
      }
    }
  }
}

// calculates the product of a vector and a matrix (in that order)
void mv_prod(int dimension, double vector[dimension], double matrix[dimension][dimension])
{
  double new_vector[dimension];
  int l;
  for ( l = 0; l < dimension; l++){
    new_vector[l] = vector[l];
    vector[l] = 0;
  }

  int i, k;
  for ( i = 0; i < dimension; i++){
    for ( k = 0; k < dimension; k++){
      vector[i] += matrix[i][k] * new_vector[k];
    }
  }
}

// adds two matrices from one another and returns a new matrix
void m_add(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension])
{
  // add each element to one another
  int i, j;
  for ( i = 0; i < dimension; i++){
    for ( j = 0; j < dimension; j++){
      matrix_a[i][j] += matrix_b[i][j];
    }
  }
}

// subtracts two matrices from one another and returns a new matrix
void m_subtr(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension])
{
  double new_matrix[dimension][dimension];
  // subtract each element to one another
  int i, j;
  for ( i = 0; i < dimension; i++){
    for ( j = 0; j < dimension; j++){
      matrix_a[i][j] -= matrix_b[i][j];
    }
  }
}

// calculates the transpose of a square matrix
void m_transpose(int dimension, double matrix[dimension][dimension])
{
  int k, l;
  double temp_matrix[dimension][dimension];
  for ( k = 0; k < dimension; k++){
    for ( l = 0; l < dimension; l++){
      temp_matrix[k][l] = matrix[k][l];
    }
  }
  // swap rows with columns
  int i, j;
  for ( i = 0; i < dimension; i++){
    for ( j = 0; j < dimension; j++){
      matrix[i][j] = temp_matrix[j][i];
    }
  }
}

// calculates the trace of a matrix
double m_trace(int dimension, double matrix[dimension][dimension])
{
  double trace = 0;
  // sum diagonal elements
  for ( int i = 0; i < dimension; i++){
    trace += matrix[i][i];
  }
  return trace;
}

// displays a given matrix to the terminal
void m_display(int dimension, double matrix[dimension][dimension])
{
  printf("\nMatrix of dimension %d is : \n", dimension);
  // print each element by looping over each element
  int i, j;
  for ( i = 0; i < dimension; i++){
    for ( j = 0; j < dimension; j++){
      printf("%.2f ", matrix[i][j]);   // prints element
    }
    printf("\n"); // new row
  }
  printf("\n");   // new line after matrix
}

// displays a given vector to the terminal
void v_display(int length, double vector[length])
{
  printf("\nVector of length %d is : \n", length);
  // print each element by looping over each element
  int i;
  for ( i = 0; i < length; i++){
    printf("%.2f ", vector[i]);    // prints element
  }
  printf("\n");        // new line after vector
}

// performs various rotations on a given matrix
void m_rotate(double matrix[3][3], double angle_a, double angle_b, double angle_c)
{
  double rotate_a[3][3] = {
                          {1, 0, 0},
                          {0, cos(angle_a), -sin(angle_a)},
                          {0, sin(angle_a), cos(angle_a)}
                          };
  double rotate_b[3][3] = {
                          {cos(angle_b), 0, sin(angle_b)},
                          {0, 1, 0},
                          {-sin(angle_b), 0, cos(angle_b)}
                          };
  double rotate_c[3][3] = {
                          {cos(angle_c), -sin(angle_c), 0},
                          {sin(angle_c), cos(angle_c), 0},
                          {0, 0, 1}
                          };
  m_prod(3, rotate_a, rotate_b);
  m_prod(3, rotate_a, rotate_c);
  m_prod(3, rotate_a, matrix);
}
