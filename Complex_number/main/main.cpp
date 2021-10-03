#include <iostream>
#include <cmath>
#include "../include/complex.hpp"

/**
 * If you want to test Complex_program, uncomment #define TEST!  
 */
//#define TEST

extern void UnitTest();

int main()
{
    #ifdef TEST
        /**
         * Test greetings
         */
        std::cout << "Hello, This is the TEST verification!\n";
        std::cout << "Do you want to continue(Y/N): \n";

        char flag = 0;
        std::cin >> flag;

        if (std::toupper(flag) == 'Y')
            UnitTest();
        else
        {    
            std::cout << "Exit TEST verification\n";  
            return 0;
        }

    #else
        /**
         * Do what you want ...
         * for example let's print some info 
         */
        double real = 0;
        double imagine = 0;

        std::cout << "Input real: ";
        std::cin >> real;
        std::cout << "Input imagine: ";
        std::cin >> imagine;

        Complex obj(real, imagine);
        std::cout << "Complex number = " << obj << std::endl;
        std::cout << "Module = " << obj.Module() << std::endl;
        std::cout << "Argument = " << obj.Argument() << std::endl;
        std::cout << "Pairing = " << obj.Pairing() << std::endl;

    #endif // TEST

    return 0;
}

