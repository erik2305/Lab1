#include <iostream>
#include <limits>
#include <vector>

#include "matrix/matrix.h"
#include "input/input.h"

int main()
{
	int size;

    std::cout << "enter number of rows/columns: ";
    size = int_input();

    //vector usage is demanded by task terms
    std::vector<float> vector(size);
    Matrix matrix;

    try
    {
	    matrix = create_matrix(size);
    }
    catch(std::bad_alloc & exception){
        std::cerr << "bad_alloc detected: " << exception.what()<< std::endl<<"terminating program";
        delete_matrix(matrix);
        return -1;
    }

	fill_matrix(matrix);

    print_matrix(matrix);

    try {
        formula_calculations(matrix, vector);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        delete_matrix(matrix);
        return -1;
    }
    std::cout<<"Vector: ";
    for (int i = 0; i < matrix.size; i++) {
        std::cout<<vector[i] << " ";
    }

	delete_matrix(matrix);
    std::cout<<std::endl<<"press enter to close program";
	std::cin.ignore((std::numeric_limits< std::streamsize >::max)(), '\n');
	return 0;
}