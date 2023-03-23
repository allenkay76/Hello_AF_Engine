#include <stdio.h>
#include <iostream>
#include <string>


#include "AF_Math.h"

int main(int argc, char* args[]) {
    std::cout << "Starting AF_Engine entry point" << std::endl;
    std::cout << "%d" << argc << std::endl;
    std::cout << "%s" << args[1] << std::endl;

    // Call the function
    double result = AF_Math::reciprocal(2.0);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
