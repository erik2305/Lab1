#include "input.h"
#include <iostream>
#include <sstream>

//int int_input()
//{
//    std::string input;
//    std::cin >> input;
//        bool isInteger = true;
//        for (char c: input) {
//            if (!isdigit(c)) {
//                isInteger = false;
//                break;
//            }
//        }
//        if (isInteger) {
//            return stoi(input);
//        }
//        else {
//            std::cout << "Input integer: ";
//            int_input();
//        }
//}

//int int_input()
//{
//    std::string number;
//    int number_validated;
//    while (std::getline(std::cin, number) && number.end() !=
//    std::find_if_not(number.begin(), number.end(), &isdigit))
//    {
//        std::cout << "input positive integer \n";
//    }
//    return number_validated = stoi(number);
//}
//int int_input()
//{
//    double input;
//    bool valid= false;
//    do
//    {
//        std::cin >> input;
//        if (std::cin.good() && (int)input == input)
//        {
//            valid = true;
//        }
//        else
//        {
//            std::cin.clear();
//            std::cin.ignore( std::numeric_limits< std::streamsize>::max(),'\n');
//            std::cout << "Invalid input; please re-enter." << std::endl;
//        }
//    } while (!valid);
//
//    return (input);
//}

//validates input
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
