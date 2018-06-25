// finds the product of two square matrices
// author: Cohen Robinson
// date: 25/06/18

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double m_prod(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
double mv_prod(int dimension, double vector[dimension], double matrix[dimension][dimension]);
double m_add(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
double m_subtr(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension]);
double m_transpose(int dimension, double matrix[dimension][dimension]);
double m_trace(int dimension, double matrix[dimension][dimension]);

void m_display(int dimension, double matrix[dimension][dimension]);
void v_display(int length, double vector[length]);

int main()
{

}

// calculates the product of two square matrices of the same size
double m_prod(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension])
{
  // creates a zero matrix to store multiplication in
  double new_matrix[dimension][dimension];
  int l, r;
  for ( l = 0; l < dimension; l++){
    for ( r = 0; r < dimension; r++){
      new_matrix[l][r] = 0;
    }
  }
  // multiplies both matrices together
  int i, k, j;
  for ( i = 0; i < dimension; i++){
    for ( k = 0; k < dimension; k++){
      for ( j = 0; j < dimension; j++){
        new_matrix[i][k] += matrix_a[i][k] * matrix[k][j]
      }
    }
  }
  return new_matrix
}

// calculates the product of a vector and a matrix (in that order)
double mv_prod(int dimension, double vector[dimension], double matrix[dimension][dimension])
{
  double new_vector[dimension];
  int l;
  for ( l = 0; l < dimension; l++){
    new_vector[l] = 0;
  }

  int i, k;
  for ( i = 0; i < dimension; i++){
    for ( k = 0; k < dimension; k++){
      new_vector[i] += matrix[i][k] * vector[k];
    }
  }
  return new_vector;
}

// adds two matrices from one another and returns a new matrix
double m_add(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension])
{
  double new_matrix[dimension][dimension];
  // add each element to one another
  int i, j;
  for ( i = 0; i < dimension; i++){
    for ( j = 0; j < dimension; j++){
      new_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
    }
  }
  return new_matrix;
}

// subtracts two matrices from one another and returns a new matrix
double m_subtr(int dimension, double matrix_a[dimension][dimension], double matrix_b[dimension][dimension])
{
  double new_matrix[dimension][dimension];
  // subtract each element to one another
  int i, j;
  for ( i = 0; i < dimension; i++){
    for ( j = 0; j < dimension; j++){
      new_matrix[i][j] = matrix_a[i][j] - matrix_b[i][j];
    }
  }
  return new_matrix;
}

// calculates the transpose of a square matrix
double m_transpose(int dimension, double matrix[dimension][dimension])
{
  double new_matrix[dimension][dimension];
  // swap rows with columns
  int i, j;
  for ( i = 0; i < dimension; i++){
    for ( j = 0; j < dimension; j++){
      new_matrix[i][j] = matrix[j][i];
    }
  }
  return new_matrix;
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
      printf("%f", matrix[i][j]);   // prints element
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
    printf("%f", vector[i]);    // prints element
  }
  printf("\n");        // new line after vector
}
