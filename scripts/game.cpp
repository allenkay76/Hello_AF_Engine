#include "Game.h"
#include "Rendering/imageData.h"
#include "GameEngine/GameEngine.h"
#include "GameEngine/IInput.h"
#include "GameEngine/ITimer.h"
#include "GameEngine/IRenderer.h"

#include "SDL/SDLGameTimer.h"

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
ITimer* timerService = nullptr;
IRenderer* rendererService = nullptr;

void Game::awake(){            

    //gameEngine
    thisGameEngine = GameEngine::GetInstance();

    if(thisGameEngine == nullptr){
        LogManager::Log("Game::awake() m_appData->gameEnginePtr is null");
    }

    
    /**/
    /**/
    //loadedImage = thisGameEngine->getRenderer()->loadImage(imagePath);

    inputService = IInputLocator::getInput();
    timerService = ITimerLocator::getTimer();
    rendererService = IRendererLocator::getRenderer();
}

void Game::start() {
    // Create a shader
    // Create a shape
    // Create the font
    // Create the text
    // Create the player
    //std::cout << "Game FrameRate: " << timerService->getAvgFrameRate() << std::endl;
    //LogManager::Log("Testing Log Manager from game", timerService->getAvgFrameRate());

}

void Game::update() {
    //std::cout << "Hello_AF_Engine Game update" << std::endl;

    timerService->printFrameRate();

    //If a key is pressed, update the player position
    if (inputService->getKeyPressed()){
        //Key is pressed
        //LogManager::Log("\nKey is pressed \n");
    }else{
        //Key is not pressed
    }

    //date score text
}

void Game::shutdown() {
}





Game::Game(const std::shared_ptr<AppSubSystems> thisSubSystem){
    thisSubSystem->engineBehaviourPtr = std::shared_ptr<Game>(this);
    //std::shared_ptr<GameEngine> thisGameEngine = GameEngine::GetInstance();
    //thisGameEngine->appSubSystems->gameBehaviourPtr = this;
    //m_appDataPtr->afEngineBehaviourPtr = this;
}

Game::~Game(){
}