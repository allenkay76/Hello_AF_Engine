#include <stdio.h>
#include <iostream>
#include <string>

#include "Application/Application.h"
#include "AF_Math.h"
#include <windows.h>
/*
int main(int argc, char* args[]) {
    std::cout << "Starting AF_Engine entry point" << std::endl;
    std::cout << "%d" << argc << std::endl;
    std::cout << "%s" << args[1] << std::endl;

    // Call the function
    double result = AF_Math::reciprocal(2.0);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

*/
/*
int main(int argc, char* args[]) {
    // Print the starting message and display the command-line arguments
    std::cout << "Starting Hello_AF_Engine entry point" << std::endl;
    std::cout << "Number of arguments: " << argc << std::endl;

    


    //Check if there is a config file path argument
    if(argc > 1){
        std::cout << "First argument: " << args[1] << std::endl;
        // Initialize the application data structure with the desired settings, use the first argument as the config file path
        AppData appData = Application::InitializeAppData(args[1]);
        // Create an Application instance with the specified application data
        Application application(appData);
    }else{
        std::cout << "Missing Project Config File Path"<< std::endl;
    }

    // Call the function
    double result = AF_Math::reciprocal(2.0);
    std::cout << "Linking to AF_Math Success: Test reciprocal method should = 0.5: " << result << std::endl;
    
    // The program exits successfully
    return 0;
}
*/
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    // Suppress unused parameter warnings
    (void)hInstance;
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;

    // Print the starting message
    std::cout << "Starting Hello_AF_Engine entry point" << std::endl;

     // Initialize the application data structure with the desired settings, use the first argument as the config file path
        AppData appData = Application::InitializeAppData("config/AF_Engine.json");
        // Create an Application instance with the specified application data
        Application application(appData);

        // Call the function
    double result = AF_Math::reciprocal(2.0);
    std::cout << "Linking to AF_Math Success: Test reciprocal method should = 0.5: " << result << std::endl;

    // Return success
    return 0;
}


