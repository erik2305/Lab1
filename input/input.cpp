#include "input.h"
#include <iostream>
#include <sstream>

int int_input()
{
    int ret_integer;
    std::string str_number;

    while(true) {
        std::getline(std::cin, str_number); //get string input
        std::stringstream convert(str_number); //turns the string into a stream
        //checks for complete conversion to integer and checks for minimum value
        if(convert >> ret_integer && !(convert >> str_number))
            return ret_integer;
        std::cin.clear(); //just in case an error occurs with cin (eof(), etc)
        std::cout<<"invalid input. try again: ";
    }
}
