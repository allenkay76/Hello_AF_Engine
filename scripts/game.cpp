#include "Game.h"
#include "Rendering/imageData.h"
#include "GameEngine/GameEngine.h"
#include "GameEngine/IInput.h"

#include "SDL/SDLGameInput.h"

const char* imagePath = "assets\\textures\\atom_forge_art.png";
const char* fontPath = "assets\\fonts\\arial.ttf";
//TODO: get font

std::unique_ptr<ImageData> loadedImage = nullptr;

float playerXPos = 0.0f;
float playerYPos = 0.0f;

std::string scoreText = "Score: 0";
std::shared_ptr<GameEngine> thisGameEngine = nullptr;

//TODO: create a text render Object

//TODO: create a player render Object

//Create shader for player
//player color
//TODO create a color struct
const char* vertexShaderSource = "assets\\shaders\\unlitVertexShader.vs";
const char* fragmentShaderSource = "assets\\shaders\\unlitFragmentShader.fs";

IInput* inputService = nullptr;

void Game::awake(){            
    std::cout << "Hello_AF_Engine Game awake" << std::endl;

    //gameEngine
    thisGameEngine = GameEngine::GetInstance();

    if(thisGameEngine == nullptr){
     std::cout << "Game::awake() m_appData->gameEnginePtr is null" << std::endl;
    }



    
    std::cout << "thisGameEngine = " << thisGameEngine << std::endl;
    /*
    if(thisGameEngine->getRenderer() == nullptr){
        std::cout << "Game::awake() m_appData->gameEnginePtr->getRenderer() is null" << std::endl;
    }*/
    /**/
    //loadedImage = thisGameEngine->getRenderer()->loadImage(imagePath);

    inputService = IInputLocator::getInput();
}

void Game::start() {
    std::cout << "Hello_AF_Engine Game start" << std::endl;

    // Create a shader
    // Create a shape
    // Create the font
    // Create the text
    // Create the player


}

void Game::update() {
    //std::cout << "Hello_AF_Engine Game update" << std::endl;

    //If a key is pressed, update the player position
    if (inputService->getKeyPressed()){//IInput::getKeyPressed()){
        //Key is pressed
        std::cout << "\n Key is pressed \n" << std::endl;
    }else{
        //Key is not pressed
    }

    //date score text
}

void Game::shutdown() {
    std::cout << "Hello_AF_Engine Game shutdown" << std::endl;
}





Game::Game(const std::shared_ptr<AppSubSystems> thisSubSystem){
    std::cout << "Hello_AF_Engine Game constructor" << std::endl;

    thisSubSystem->engineBehaviourPtr = std::shared_ptr<Game>(this);
    //std::shared_ptr<GameEngine> thisGameEngine = GameEngine::GetInstance();
    //thisGameEngine->appSubSystems->gameBehaviourPtr = this;
    //m_appDataPtr->afEngineBehaviourPtr = this;
}

Game::~Game(){
    std::cout << "Hello_AF_Engine Game destructor" << std::endl;    
}