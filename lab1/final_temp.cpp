//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//float** inner_matrix_initialization(int rows, int cols)
//{
//    float** matrix = new float*[rows];
//
//    for (int i = 0; i < rows; i++)
//    {
//        matrix[i] = new float[cols];
//    }
//
//    return matrix;
//}
//
//void fill_inner_matrix_with_random_numbers(float** matrix, int rows, int cols) {
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            *(*(matrix + i) + j) = ((float)rand() / (float)(RAND_MAX)) * 10;
//        }
//    }
//}
//
//void fill_matrix_with_random_matrix(float**** matrix, int rows, int cols, int inner_rows, int inner_cols)
//{
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            fill_inner_matrix_with_random_numbers(*(*(matrix + i) + j), inner_rows, inner_cols);
//        }
//    }
//}
//
//float**** matrix_initialization(int rows, int cols, int inner_rows, int inner_cols)
//{
//    float**** matrix = new float*** [rows];
//    for (int i = 0; i < rows; i++)
//    {
//        *(matrix + i) = new float** [cols];
//        for (int j = 0; j < cols; j++)
//        {
//            *(*(matrix + i) + j) = inner_matrix_initialization(inner_rows, inner_cols);
//        }
//    }
//
//    return matrix;
//}
//
//void print_inner_matrix(float** matrix, int rows, int cols)
//{
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            cout << *(*(matrix + i) + j) << "\t\t";
//        }
//        cout << endl;
//    }
//}
//
//void print_matrix(float**** matrix, int rows, int cols, int inner_rows, int inner_cols)
//{
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            cout << "Matrix index [" << i << "][" << j << "]" << endl;
//            print_inner_matrix(*(*(matrix + i) + j), inner_rows, inner_cols);
//            cout << endl << endl;
//        }
//    }
//}
//
//void delete_inner_matrix(float** matrix, int rows, int cols)
//{
//    for (int i = 0; i < rows; i++)
//    {
//       delete[] matrix[i];
//    }
//    delete[] matrix;
//}
//
//
//void delete_matrix(float**** matrix, int rows, int cols, int inner_rows, int inner_cols)
//{
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//        {
//            delete_inner_matrix((*(*(matrix + i) + j)), inner_rows, inner_cols);
//        }
//    }
//
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}
//
//float** multiply_inner_matrices(float** matrix_1, int rows_1, int cols_1, float** matrix_2, int rows_2, int cols_2)
//{
//    if (cols_1 != rows_2)
//    {
//        cout << "Cannot mutiply inner matrices!" << endl;
//    }
//
//    float** result_matrix = inner_matrix_initialization(rows_1, cols_2);
//    
//    for (int i = 0; i < rows_1; i++)
//    {
//        for (int j = 0; j < cols_2; j++) 
//        {
//            float result = 0;
//            for (int k = 0; k < cols_1; k++)
//            {
//                result += *(*(matrix_1 + i) + k) * *(*(matrix_2 + k) + j);
//            }
//            *(*(result_matrix + i) + j) = result;
//        }
//    }
//
//    return result_matrix;
//}
//
//float**** multiply_matrices(
//    float**** matrix_1, 
//    int rows_1, 
//    int cols_1, 
//    float ****matrix_2, 
//    int rows_2, 
//    int cols_2, 
//    int inner_rows_1, 
//    int inner_cols_1, 
//    int inner_rows_2, 
//    int inner_cols_2
//) 
//{
//    if (cols_1 != rows_2)
//    {
//        cout << "Cannot mutiply matrices!" << endl;
//    }
//
//    float**** result_matrix = matrix_initialization(rows_1, cols_2, inner_rows_1, inner_cols_2);
//
//    
//}
//
//int main()
//{
//    int matrix_1_rows = 1, matrix_1_cols = 3;
//    int matrix_2_rows = 3, matrix_2_cols = 1;
//
//    int inner_matrix_1_rows = 2, inner_matrix_1_cols = 3;
//    int inner_matrix_2_rows = 3, inner_matrix_2_cols = 2;
//
//    srand((unsigned int)(time(nullptr)));
//
//    float**** matrix_2 = matrix_initialization(matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
//    float**** matrix_1 = matrix_initialization(matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
//
//    //fill_matrix_with_random_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
//    //fill_matrix_with_random_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
//
//    float** matrix_test_1 = inner_matrix_initialization(inner_matrix_1_rows, inner_matrix_1_cols);
//    float** matrix_test_2 = inner_matrix_initialization(inner_matrix_2_rows, inner_matrix_2_cols);
//
//    fill_inner_matrix_with_random_numbers(matrix_test_1, inner_matrix_1_rows, inner_matrix_1_cols);
//    fill_inner_matrix_with_random_numbers(matrix_test_2, inner_matrix_2_rows, inner_matrix_2_cols);
//
//    cout << "matrix1:" << endl;
//    print_inner_matrix(matrix_test_1, inner_matrix_1_rows, inner_matrix_1_cols);
//    cout << endl;
//    cout << "matrix2:" << endl;
//    print_inner_matrix(matrix_test_2, inner_matrix_2_rows, inner_matrix_2_cols);
//    cout << endl;
//
//    float** result = multiply_inner_matrices(matrix_test_1, 
//                                                inner_matrix_1_rows, 
//                                                inner_matrix_1_cols, 
//                                                matrix_test_2, 
//                                                inner_matrix_2_rows, 
//                                                inner_matrix_2_cols);
//
//
//    cout << "result:" << endl;
//    print_inner_matrix(result, inner_matrix_1_rows, inner_matrix_2_cols);
//
//    //print_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
//    
//    //delete_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
//    //delete_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
//}
//
//


#include <iostream>
#include <cstdlib>
#include <ctime>
// #include <x86intrin.h>
#include <intrin.h>

using namespace std;

float** inner_matrix_initialization(int rows, int cols)
{
    if (rows < 0 || cols < 0)
    {
        cout << "Cannot initialize inner matrix!" << endl;
        exit(0);
    }

    float** matrix = new float* [rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new float[cols];
    }

    return matrix;
}

void fill_inner_matrix_with_random_numbers(float** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix + i) + j) = ((float)rand() / (float)(RAND_MAX)) * 10;
        }
    }
}

void fill_matrix_with_random_matrix(float**** matrix, int rows, int cols, int inner_rows, int inner_cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fill_inner_matrix_with_random_numbers(*(*(matrix + i) + j), inner_rows, inner_cols);
        }
    }
}

void fill_inner_matrix_with_number(float** matrix, int rows, int cols, float number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix + i) + j) = number;
        }
    }
}

float**** matrix_initialization(int rows, int cols, int inner_rows, int inner_cols)
{
    if (rows < 0 || cols < 0)
    {
        cout << "Cannot initialize matrix!" << endl;
        exit(0);
    }

    float**** matrix = new float*** [rows];
    for (int i = 0; i < rows; i++)
    {
        *(matrix + i) = new float** [cols];
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
            cout << endl;
        }
    }
}

void delete_inner_matrix(float** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void delete_matrix(float**** matrix, int rows, int cols, int inner_rows, int inner_cols)
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

float** sum_inner_matrix(float** matrix_1, float** matrix_2, int rows, int cols)
{
    float** result = inner_matrix_initialization(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(result + i) + j) = *(*(matrix_1 + i) + j) + *(*(matrix_2 + i) + j);
        }
    }
    return result;
}

float** multiply_inner_matrices(float** matrix_1, int rows_1, int cols_1, float** matrix_2, int rows_2, int cols_2)
{
    if (cols_1 != rows_2)
    {
        cout << "Cannot mutiply inner matrices!" << endl;
        exit(0);
    }

    float** result_matrix = inner_matrix_initialization(rows_1, cols_2);

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

float**** multiply_matrices(
    float**** matrix_1,
    int rows_1,
    int cols_1,
    float**** matrix_2,
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
        exit(0);
    }

    float**** result_matrix = matrix_initialization(rows_1, cols_2, inner_rows_1, inner_cols_2);

    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_2; j++)
        {
            float** result = inner_matrix_initialization(inner_rows_1, inner_cols_2);
            fill_inner_matrix_with_number(result, inner_rows_1, inner_cols_2, 0);
            for (int k = 0; k < cols_1; k++)
            {
                float** mul_result = multiply_inner_matrices(*(*(matrix_1 + i) + k), inner_rows_1, inner_cols_1, *(*(matrix_2 + k) + j), inner_rows_2, inner_cols_2);
                float** temp_result = result;
                result = sum_inner_matrix(result, mul_result, inner_rows_1, inner_cols_2);
                delete_inner_matrix(temp_result, inner_rows_1, inner_cols_2);
                delete_inner_matrix(mul_result, inner_rows_1, inner_cols_2);
            }
            delete_inner_matrix(*(*(result_matrix + i) + j), inner_rows_1, inner_cols_2);
            *(*(result_matrix + i) + j) = result;
        }
    }

    return result_matrix;
}

bool compare_inner_matrices(float** matrix_1, int rows_1, int cols_1, float** matrix_2, int rows_2, int cols_2)
{
    if (rows_1 != rows_2 || cols_1 != cols_2)
    {
        return false;
    }
    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++)
        {
            if (*(*(matrix_1 + i) + j) != *(*(matrix_2 + i) + j))
                return false;
        }
    }
    return true;
}



bool compare_matrices(
    float**** matrix_1,
    int rows_1,
    int cols_1,
    float**** matrix_2,
    int rows_2,
    int cols_2,
    int inner_rows_1,
    int inner_cols_1,
    int inner_rows_2,
    int inner_cols_2)
{
    if (rows_1 != rows_2 || cols_1 != cols_2)
    {
        return false;
    }

    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++)
        {
            if (!compare_inner_matrices(*(*(matrix_1 + i) + j), inner_rows_1, inner_cols_1, *(*(matrix_2 + i) + j), inner_rows_2, inner_cols_2))
                return false;
        }
    }
    return true;
}


float** sum_inner_matrices_intrinsics(float** matrix_1, float** matrix_2, int rows, int cols) {
    float** result = inner_matrix_initialization(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j += 8) {
            _mm256_storeu_ps(result[i] + j, _mm256_add_ps(_mm256_loadu_ps(matrix_1[i] + j), _mm256_loadu_ps(matrix_2[i] + j)));
        }
    }
    return result;
}

float** multiply_inner_matrices_intrinsics(float** matrix_1, int rows_1, int cols_1, float** matrix_2, int rows_2, int cols_2)
{
    if (cols_1 != rows_2)
    {
        cout << "Cannot multiply inner matrices" << endl;
        exit(0);
    }

    float** result_matrix = inner_matrix_initialization(rows_1, cols_2);

    for (int i = 0; i < rows_1; i++)
    {
        for (int k = 0; k < cols_1; k++)
        {
            for (int j = 0; j < cols_2; j += 8)
            {
                _mm256_storeu_ps(result_matrix[i] + j, _mm256_add_ps(_mm256_loadu_ps(result_matrix[i] + j),
                    _mm256_mul_ps(_mm256_set1_ps(matrix_1[i][k]), _mm256_loadu_ps(matrix_2[k] + j))));
            }
        }
    }

    return result_matrix;
}


float**** multiply_matrices_intrinsics(float**** matrix_1, int rows_1, int cols_1, float**** matrix_2, int rows_2,
    int cols_2, int inner_rows_1, int inner_cols_1, int inner_rows_2, int inner_cols_2)
{
    if (cols_1 != rows_2)
    {
        cout << "Cannot mutiply matrices!" << endl;
        exit(0);
    }

    float**** result_matrix = matrix_initialization(rows_1, cols_2, inner_rows_1, inner_cols_2);

    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_2; j++)
        {
            float** result = inner_matrix_initialization(inner_rows_1, inner_cols_2);
            fill_inner_matrix_with_number(result, inner_rows_1, inner_cols_2, 0);
            for (int k = 0; k < cols_1; k++)
            {
                float** mul_result = multiply_inner_matrices_intrinsics(*(*(matrix_1 + i) + k), inner_rows_1, inner_cols_1, *(*(matrix_2 + k) + j), inner_rows_2, inner_cols_2);
                float** temp_result = result;
                result = sum_inner_matrices_intrinsics(result, mul_result, inner_rows_1, inner_cols_2);
                delete_inner_matrix(temp_result, inner_rows_1, inner_cols_2);
                delete_inner_matrix(mul_result, inner_rows_1, inner_cols_2);
            }
            delete_inner_matrix(*(*(result_matrix + i) + j), inner_rows_1, inner_cols_2);
            *(*(result_matrix + i) + j) = result;
        }
    }

    return result_matrix;
}

int main()
{
    int matrix_1_rows = 1, matrix_1_cols = 3;
    int matrix_2_rows = 3, matrix_2_cols = 1;

    int inner_matrix_1_rows = 8, inner_matrix_1_cols = 1;
    int inner_matrix_2_rows = 1, inner_matrix_2_cols = 128;

    srand((unsigned int)(time(nullptr)));

    // float ****matrix_2 = matrix_initialization(matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    // fill_matrix_with_random_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    // float ****matrix_1 = matrix_initialization(matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    // fill_matrix_with_random_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);

    // cout << "Matrix 1:" << endl;
    // print_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    // cout << '\n'
    //      << endl;

    // cout << "Matrix 2:" << endl;
    // print_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    // cout << '\n'
    //      << endl;

    // float ****result = multiply_matrices(matrix_1,
    //                                      matrix_1_rows,
    //                                      matrix_1_cols,
    //                                      matrix_2,
    //                                      matrix_2_rows,
    //                                      matrix_2_cols,
    //                                      inner_matrix_1_rows,
    //                                      inner_matrix_1_cols,
    //                                      inner_matrix_2_rows,
    //                                      inner_matrix_2_cols);

    float**** m1 = matrix_initialization(matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    cout << "Initialized m1" << endl;
    float**** m2 = matrix_initialization(matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    cout << "Initialized m2" << endl;

    float**** result = multiply_matrices(m1, matrix_1_rows, matrix_1_cols, m2, matrix_2_rows, matrix_2_cols, inner_matrix_1_rows,
        inner_matrix_1_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    cout << "Multiplied" << endl;
    float**** i_result = multiply_matrices_intrinsics(m1, matrix_1_rows, matrix_1_cols, m2, matrix_2_rows, matrix_2_cols, inner_matrix_1_rows,
        inner_matrix_1_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    cout << "Multiplied with intrinsics" << endl;

    if (compare_matrices(result, matrix_1_rows, matrix_2_cols, i_result, matrix_1_rows, matrix_2_cols, inner_matrix_1_rows, inner_matrix_2_cols,
        inner_matrix_1_rows, inner_matrix_2_cols))
    {
        cout << "They are equal" << endl;
    }
    else
    {
        cout << "They are not equal" << endl;
    }



    //delete_inner_matrix(m1, inner_matrix_1_rows, inner_matrix_1_cols);
    //delete_inner_matrix(m2, inner_matrix_2_rows, inner_matrix_2_cols);



    // cout << "Result:" << endl;
    // print_matrix(result, matrix_1_rows, matrix_2_cols, inner_matrix_1_rows, inner_matrix_2_cols);
    // cout << '\n'
    //      << endl;

    // delete_matrix(matrix_1, matrix_1_rows, matrix_1_cols, inner_matrix_1_rows, inner_matrix_1_cols);
    // delete_matrix(matrix_2, matrix_2_rows, matrix_2_cols, inner_matrix_2_rows, inner_matrix_2_cols);
    // delete_matrix(result, matrix_1_rows, matrix_2_cols, inner_matrix_1_rows, inner_matrix_2_cols);
}