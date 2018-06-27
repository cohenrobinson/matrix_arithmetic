// finds the product of two square matrices
// author: Cohen Robinson
// date: 25/06/18

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// declaration of functions
void m_prod(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
void mv_prod(int dimension, double vector[dimension], double matrix[dimension][dimension]);
void m_add(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
void m_subtr(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
void m_transpose(int dimension, double matrix[dimension][dimension]);
double m_trace(int dimension, double matrix[dimension][dimension]);
void m_rotate(double matrix[3][3], double angle_a, double angle_b, double angle_c);

void m_rred(int rows, int columns, double matrix[rows][columns]);
void m_interchange_row(int rows, int columns, double matrix[rows][columns], int row1, int row2);
void m_multiply_row(int rows, int columns, double matrix[rows][columns], int row1, double constant);
void m_replace_row(int rows, int columns, double matrix[rows][columns], int row1, int row2, double constant);

void m_display(int rows, int columns, double matrix[rows][columns]);
void v_display(int length, double vector[length]);

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
void m_display(int rows, int columns, double matrix[rows][columns])
{
  printf("\nMatrix of dimension %d, %d is : \n", rows, columns);
  // print each element by looping over each element
  int i, j;
  for ( i = 0; i < rows; i++){
    for ( j = 0; j < columns; j++){
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

// row reduces a given matrix
void m_rred(int rows, int columns, double matrix[rows][columns])
{
  // step 1: interchange rows that have 0 value for [n][n]
  // ** need to impliment empty column check
  int n, m;
  for ( n = 0; n < rows; n++){
    if (matrix[n][n] == 0){
      for ( m = n + 1; m < rows; m++){
        if (matrix[m][n] != 0){
          m_interchange_row(rows, columns, matrix, n, m);
          continue;
      printf("ERROR: Unable to swap row, no solutions!");
      exit(0);
        }
      }
    }
  }
  // step 2 (a): apply replace to all rows below row n
  double n_val;
  for ( n = 0; n < rows; n++){
    for ( m = n + 1; m < rows; m++){
      n_val = -matrix[m][n] / matrix[n][n];
      m_replace_row(rows, columns, matrix, m, n, n_val);
    }
  }
  // step 2 (b): interchange rows where columns equal to 0
  // ** need to impliment empty column check
  int i;
  for ( n = 0; n < rows; n++){
    for ( i = n + 1; i < rows; i++){
      if (matrix[n][i] == 0){
        m_interchange_row(rows, columns, matrix, i, i+1);
      }
    }
  }
  // step 3: apply replace using row N-n to all rows above row N-n to remove Nth row elements
  // ** need to impliment empty column check
  for ( n = 1; n <= rows; n++){
    for ( m = n + 1; m <= rows; m++){
      n_val = -matrix[rows-m][rows-n] / matrix[rows-n][rows-n];
      m_replace_row(rows, columns, matrix, rows-m, rows-n, n_val);
    }
  }
  // step 4: apply multiply to find solutions
  for ( n = 0; n < rows; n++){
    if (matrix[n][n] != 0){
    n_val = 1 / matrix[n][n];
    m_multiply_row(rows, columns, matrix, n, n_val);
    }
  }
}

// interchanges two rows
void m_interchange_row(int rows, int columns, double matrix[rows][columns], int row1, int row2)
{
  int j;
  double temp_element;
  for ( j = 0; j < columns; j++){
    temp_element = matrix[row1][j];
    matrix[row1][j] = matrix[row2][j];
    matrix[row2][j] = temp_element;
  }
}

// multiplys a row by a non-zero constant
void m_multiply_row(int rows, int columns, double matrix[rows][columns], int row1, double constant)
{
  int j;
  for ( j = 0; j < columns; j++){
    matrix[row1][j] *= constant;
  }
}

// replaces a row by a multiple of another row
void m_replace_row(int rows, int columns, double matrix[rows][columns], int row1, int row2, double constant)
{
  int j;
  for ( j = 0; j < columns; j++){
    matrix[row1][j] += constant * matrix[row2][j];
  }
}
