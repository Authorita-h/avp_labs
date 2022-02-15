#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float **inner_matrix_initialization(int rows, int cols)
{
    float **matrix = new float *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new float[cols];
    }

    return matrix;
}

void fill_inner_matrix_with_random_numbers(float **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix + i) + j) = ((float)rand() / (float)(RAND_MAX)) * 10;
        }
    }
}

void fill_matrix_with_random_matrix(float ****matrix, int rows, int cols, int inner_rows, int inner_cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fill_inner_matrix_with_random_numbers(*(*(matrix + i) + j), inner_rows, inner_cols);
        }
    }
}

void fill_inner_matrix_with_number(float **matrix, int rows, int cols, float number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix + i) + j) = number;
        }
    }
}

float ****matrix_initialization(int rows, int cols, int inner_rows, int inner_cols)
{
    float ****matrix = new float ***[rows];
    for (int i = 0; i < rows; i++)
    {
        *(matrix + i) = new float **[cols];
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix + i) + j) = inner_matrix_initialization(inner_rows, inner_cols);
        }
    }

    return matrix;
}

void print_inner_matrix(float **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << *(*(matrix + i) + j) << "\t\t";
        }
        cout << endl;
    }
}

void print_matrix(float ****matrix, int rows, int cols, int inner_rows, int inner_cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Matrix index [" << i << "][" << j << "]" << endl;
            print_inner_matrix(*(*(matrix + i) + j), inner_rows, inner_cols);
            cout << endl;
        }
    }
}

void delete_inner_matrix(float **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void delete_matrix(float ****matrix, int rows, int cols, int inner_rows, int inner_cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            delete_inner_matrix((*(*(matrix + i) + j)), inner_rows, inner_cols);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

float **sum_inner_matrix(float **matrix_1, float **matrix_2, int rows, int cols)
{
    float **result = inner_matrix_initialization(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(result + i) + j) = *(*(matrix_1 + i) + j) + *(*(matrix_2 + i) + j);
        }
    }
    return result;
}

float **multiply_inner_matrices(float **matrix_1, int rows_1, int cols_1, float **matrix_2, int rows_2, int cols_2)
{
    if (cols_1 != rows_2)
    {
        cout << "Cannot mutiply inner matrices!" << endl;
    }

    float **result_matrix = inner_matrix_initialization(rows_1, cols_2);

    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_2; j++)
        {
            float result = 0;
            for (int k = 0; k < cols_1; k++)
            {
                result += *(*(matrix_1 + i) + k) * *(*(matrix_2 + k) + j);
            }
            *(*(result_matrix + i) + j) = result;
        }
    }

    return result_matrix;
}

float ****multiply_matrices(
    float ****matrix_1,
    int rows_1,
    int cols_1,
    float ****matrix_2,
    int rows_2,
    int cols_2,
    int inner_rows_1,
    int inner_cols_1,
    int inner_rows_2,
    int inner_cols_2)
{
    if (cols_1 != rows_2)
    {
        cout << "Cannot mutiply matrices!" << endl;
    }

    float ****result_matrix = matrix_initialization(rows_1, cols_2, inner_rows_1, inner_cols_2);

    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_2; j++)
        {
            float **result = inner_matrix_initialization(inner_rows_1, inner_cols_2);
            fill_inner_matrix_with_number(result, inner_rows_1, inner_cols_2, 0);
            for (int k = 0; k < cols_1; k++)
            {
                float **mul_result = multiply_inner_matrices(*(*(matrix_1 + i) + j), inner_rows_1, inner_cols_1, *(*(matrix_2 + k) + j), inner_rows_2, inner_cols_2);
                result = sum_inner_matrix(result, mul_result, inner_rows_1, inner_cols_2);
                delete_inner_matrix(mul_result, inner_rows_1, inner_cols_1);
            }
            *(*(result_matrix + i) + j) = result;
        }
    }

    return result_matrix;
}

int main()
{
    int matrix_1_rows = 1, matrix_1_cols = 3;
    int matrix_2_rows = 3, matrix_2_cols = 1;

    int inner_matrix_1_rows = 2, inner_matrix_1_cols = 3;
    int inner_matrix_2_rows = 3, inner_matrix_2_cols = 2;

    srand((unsigned int)(time(nullptr)));

    float ****matrix_2 = matrix_initialization(matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    fill_matrix_with_random_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    float ****matrix_1 = matrix_initialization(matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    fill_matrix_with_random_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);

    cout << "Matrix 1:" << endl;
    print_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    cout << '\n'
         << endl;

    cout << "Matrix 2:" << endl;
    print_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    cout << '\n'
         << endl;

    float ****result = multiply_matrices(matrix_1,
                                         matrix_1_rows,
                                         matrix_1_cols,
                                         matrix_2,
                                         matrix_2_rows,
                                         matrix_2_cols,
                                         inner_matrix_1_rows,
                                         inner_matrix_1_cols,
                                         inner_matrix_2_rows,
                                         inner_matrix_2_cols);

    cout << "Result:" << endl;
    print_matrix(result, matrix_1_rows, matrix_2_cols, inner_matrix_1_rows, inner_matrix_2_cols);
    cout << '\n'
         << endl;
}