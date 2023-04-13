#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>

#include "Application/Application.h"
#include "AF_Math.h"
//#include "AF_EngineTest.h"
#include "GameEngine/AF_EngineBehaviour.h"
#include "Game.h"

//#include "GameEngine/GameEngine.h"

//declare these as a higher scope to ensure that they live long enough to not cause a crash
std::shared_ptr<Game> gamePtr = nullptr;
std::shared_ptr<AppSubSystems> appSubSystemsPtr = nullptr;
std::shared_ptr<AppData> appDataPtr = nullptr;
//
int startApplication(int argc, char* args[]);

int startApplication(int argc, char* args[]){
    // Print the starting message and display the command-line arguments
    std::cout << "Starting Hello_AF_Engine entry point." << std::endl;
    std::cout << "Number of arguments: " << argc << std::endl;

    //Check if there is a config file path argument
    if(argc > 1){
        std::cout << "First argument: " << args[1] << std::endl;

        //Create the application
        //AppData appData = Application::InitializeAppData(args[1]);
        appDataPtr = std::make_shared<AppData>();
        appSubSystemsPtr = std::make_shared<AppSubSystems>();

        //Create the game and pass in the structs containing most of the application data and subsystems
        //move gamePtr to a higher scope to ensure that it lives long enough to not cause a crash
        gamePtr = std::make_shared<Game>(appSubSystemsPtr);


        //Set the game pointer in the appData
        //appData.afEngineBehaviourPtr = gamePtr.get();

        // Create the application
        Application application(*appDataPtr.get(), appSubSystemsPtr);
        
        //delete(applicationPtr);
        
    }else{
        std::cout << "Missing Project Config File Path"<< std::endl;
    }

    // Call the function
    //double result = AF_Math::reciprocal(2.0);
    //std::cout << "Linking to AF_Math Success: Test reciprocal method should = 0.5: " << result << std::endl;

    return 1;
}




#ifdef Linux
int main(int argc, char* args[]) {
    startApplication(argc, args);
    // The program exits successfully
    return 0;
}
#endif

#ifdef WIN32
#include <windows.h>
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

    const char* filename_cstr = "config/AF_Engine.json";
    char* filename_ptr = const_cast<char*>(filename_cstr);
    startApplication(2, &filename_ptr);


    // Return success
    return 0;
}
#endif