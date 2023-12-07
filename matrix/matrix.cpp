#include "matrix.h"
#include <iostream>


//creates matrix
Matrix create_matrix(int size)
{
	Matrix matrix;
	matrix.data = new int* [size];
    try
    {
        for (int i = 0; i < size + 1; i++)
        {
            matrix.data[i] = new int[i];
            matrix.size = i;
        }
    }
    catch (std::bad_alloc & exception)
    {
        std::cerr << "bad_alloc detected: " << exception.what()<< std::endl<<"terminating program";
        delete_matrix(matrix);
        abort();
    }
    return matrix;
}

//fills matrix with numbers
void fill_matrix(Matrix& matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            std::cout << "enter a[" << i + 1 << "][" << j + 1 << "]: ";
            matrix.data[i][j] = int_input();
        }
    }

}

//calculates vector values
int formula_calculations(Matrix& matrix, std::vector<float>& vector)
{
    int cMin, cMax;
    std::vector<int> rowSum(matrix.size);
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++)
        {
            if (j < i + 1) {
                rowSum[i] += matrix.data[i][j];
            } else {
                rowSum[i] += matrix.data[j][i];
            }
        }
    }

    cMin = *min_element(rowSum.begin(),rowSum.end());;

    cMax = *max_element(rowSum.begin(),rowSum.end());

    if (cMin == cMax)
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < matrix.size; i++) {
            vector[i] = ((float) (rowSum[i] - cMin)) / ((cMax - cMin));
        }
            return 1;
    }
}

//If you think jokes are inappropriate in the comments, don't translate this true life story

//Entro a la cocina y pongo la tetera en la estufa. Giro la perilla de la estufa. Miro la estufa y
//la tetera, esperando que el agua hierva en la tetera. Después de unos cinco minutos, un hedor
//salvaje se extiende por toda la cocina. No es de extrañar, porque el hervidor es eléctrico.

//if you translated the story, don't complain.

//prints matrix
void print_matrix(Matrix& matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++) {
            if (j < i + 1) {
                std::cout << matrix.data[i][j] << " ";
            } else {
                std::cout << matrix.data[j][i] << " ";
            }
        }
        std::cout << std::endl;
    }
}

//clears space in RAM
void delete_matrix(Matrix& matrix)
{
    for (int i = 0; i < matrix.size + 1; i++)
    {
        delete[] matrix.data[i];
    }
    delete[] matrix.data;
}