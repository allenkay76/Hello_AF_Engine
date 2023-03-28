#include "Game.h"
#include "Rendering/imageData.h"
#include "GameEngine/GameEngine.h"

const char* imagePath = "..\\assets\\textures\\atom_forge_art.png";
std::unique_ptr<ImageData> loadedImage = nullptr;

void Game::awake(){            
    std::cout << "Hello_AF_Engine Game awake" << std::endl;
    //loadedImage = std::make_unique<ImageData>();
    //gameEngine


    //if(m_appDataPtr->gameEnginePtr == nullptr){
     //   std::cout << "Game::awake() m_appData->gameEnginePtr is null" << std::endl;
    //}

    
    GameEngine::testEngineFunction();
    std::cout << "testEngineFunction()" << std::endl;

    int returnValue =  GameEngine::returnTextEngineFunction();
    std::cout << "returnTextEngineFunction() = " << returnValue << std::endl;

    int returnMultValue = GameEngine::multTextEngineFunction(400,69);
    std::cout << "returnTextEngineFunction() = " << returnMultValue << std::endl;


    std::shared_ptr<GameEngine> thisGameEngine = GameEngine::GetInstance();
    std::cout << "thisGameEngine = " << thisGameEngine << std::endl;
    /*
    if(m_appData->gameEnginePtr->getRenderer() == nullptr){
        std::cout << "Game::awake() m_appData->gameEnginePtr->getRenderer() is null" << std::endl;
    }*/
    //loadedImage = thisGameEngine->getRenderer()->loadImage(imagePath);
    //engineRenderer->loadImage(imagePath, loadedImage);
}

void Game::start() {
    std::cout << "Hello_AF_Engine Game start" << std::endl;
}

void Game::update() {
    //std::cout << "Hello_AF_Engine Game update" << std::endl;
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