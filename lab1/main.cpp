#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// int inner_matrix_initialization()
// {
//     // size of matrix
//     int matrix_1_rows = 4, matrix_1_cols = 5;
//     int matrix_2_rows = 5, matrix_2_cols = 4;

//     if (matrix_1_cols != matrix_2_rows)
//     {
//         cout << "Matrix sizes are incorrect!" << endl;
//         return;
//     }
    
//     // matrix initialization
//     int** matrix_1[matrix_1_rows][matrix_1_cols];
//     int** matrix_2[matrix_2_rows][matrix_2_cols];
//     int** result_matrix[matrix_1_rows][matrix_2_cols];

//     // size of inner matrix
//     int inner_matrix_1_rows, inner_matrix_1_cols;
//     int inner_matrix_2_rows, inner_matrix_2_cols;

//     if (inner_matrix_1_cols != inner_matrix_2_rows)
//     {
//         cout << "Inner matrix sizes are incorrect!" << endl;
//     }

//     // inner matrix memory allocation
//     inner_matrix_memory_allocation(matrix_1[matrix_1_rows][matrix_1_cols], 
//                                     matrix_1_rows, 
//                                     matrix_1_cols, 
//                                     inner_matrix_1_rows, 
//                                     inner_matrix_1_cols);
//     inner_matrix_memory_allocation(matrix_2[matrix_2_rows][matrix_2_cols], 
//                                     matrix_2_rows, 
//                                     matrix_2_cols, 
//                                     inner_matrix_2_rows, 
//                                     inner_matrix_2_cols);
// }

// void inner_matrix_memory_allocation(int** matrix[][], int rows, int cols, int inner_rows, int inner_cols) {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             for (int inner_i = 0; inner_i < inner_rows; inner_i) 
//             {
//                 matrix[i][j] = new *int[rows];
//             }
//         }
//     }
// }

// int inner_matrix_multiplication() {

// }

float** inner_matrix_initialization(int rows, int cols) 
{
    float** matrix = new float*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new float[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            *(*(matrix + i) + j) = ((float)rand() / (float)(RAND_MAX)) * 10;
        }
    }
    
    return matrix;
}

float**** matrix_initialization(int rows, int cols, int inner_rows, int inner_cols)
{
    float**** matrix = new float***[rows];
    for (int i = 0; i < rows; i++)
    {
        *(matrix + i) = new float**[cols];
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix + i) + j) = inner_matrix_initialization(inner_rows, inner_cols);
        }
    }

    return matrix;
}

void print_inner_matrix(float** matrix, int rows, int cols)
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

void print_matrix(float**** matrix, int rows, int cols, int inner_rows, int inner_cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Matrix index [" << i << "][" << j << "]" << endl;
            print_inner_matrix(*(*(matrix + i) + j), inner_rows, inner_cols);
            cout << endl << endl;
        }
    }
}

void delete_inner_matrix(float** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete [] matrix [i];
    }
    delete [] matrix;
}

int main() 
{
    int matrix_1_rows = 1, matrix_1_cols = 3;
    int matrix_2_rows = 3, matrix_2_cols = 1;

    int inner_matrix_1_rows = 2, inner_matrix_1_cols = 3;
    int inner_matrix_2_rows = 3, inner_matrix_2_cols = 2;

    srand((unsigned int)(time(nullptr)));

    float**** matrix_1 = matrix_initialization(matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    float**** matrix_2 = matrix_initialization(matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);

    print_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    print_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);

    // delete_inner_matrix(matrix_1, matrix_1_rows, matrix_1_cols);
    // float** matrix = inner_matrix_initialization(matrix_1_rows, matrix_1_cols);
}