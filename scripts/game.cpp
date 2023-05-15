#include "Game.h"
#include <string>   


#include <iostream>

#include "Rendering/imageData.h"
#include "GameEngine/GameEngine.h"
#include "GameEngine/IInput.h"
#include "GameEngine/ITimer.h"
#include "GameEngine/IRenderer.h"

#include "SDL/SDLGameTimer.h"

#include "SDL/SDLGameInput.h"

//Stuff to make a mesh object
#include "Rendering/IMesh.h"
//#include "Rendering/AF_Mesh.h"
#include "OpenGL/GL_BufferObject.h"
#include "OpenGL/GLMaterial.h"
#include "OpenGL/GLMesh.h"
#include "OpenGL/GL_Shader.h"

#include "Gameplay/GameObject_Shape.h"



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
const std::string vert = "assets/shaders/basicUnlit.vs"; //"./bin/debug_WIN_x64/assets/shaders/basicUnlit.vs";
const std::string frag = "assets/shaders/basicUnlit2.fs"; //"./bin/debug_WIN_x64/assets/shaders/basicUnlit2.fs";
    

IInput* inputService = nullptr;
ITimer* timerService = nullptr;
IRenderer* rendererService = nullptr;

std::unique_ptr<GameObject_Shape> playerGO = nullptr;

AF_Vec4 whiteColor{1.0f, 1.0f, 1.0f, 1.0f};
AF_Vec4 redColor{1.0f, 0.0f, 0.0f, 1.0f};
AF_Vec4 greenColor{0.0f, 1.0f, 0.0f, 1.0f};
AF_Vec4 blueColor{0.0f, 0.0f, 1.0f, 1.0f};

AF_Vec4 currentColor;

//rendering variables
std::unique_ptr<AF_Quad> quadMesh;
std::unique_ptr<GL_BufferObject> testBufferObject;
std::unique_ptr<GLMaterial> testMaterial;
std::unique_ptr<IShader> testShader;
std::shared_ptr<GLMesh> testMesh;

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


    //Make the player game object
    playerGO = std::make_unique<GameObject_Shape>();
    
    currentColor = whiteColor;
}

void Game::start() {
    // Create a shader
    // Create a shape
    // Create the font
    // Create the text
    // Create the player
    CreateTestObject();
    
}

void Game::CreateTestObject(){
    //Create the mesh vector
    //std:: m_meshes = std::make_unique<std::vector<std::unique_ptr<IMesh>>>();
    //Create the mesh
    quadMesh = std::make_unique<AF_Quad>();
    testBufferObject = std::make_unique<GL_BufferObject>();
    testMaterial = std::make_unique<GLMaterial>();


    testShader = std::make_unique<GL_Shader>(std::string(vert), std::string(frag));
    testMaterial->setShader(std::move(testShader));
    // Create the mesh, ensure we transfer ownership of the mesh to the IMesh object
    // need to also pass in the derived openGL buffer object which is derived from IBuffer_Object. This way we can swap from opegl to other standards
    testMesh = std::make_shared<GLMesh>(std::move(quadMesh), std::move(testBufferObject), std::move(testMaterial));
  
    LogManager::Log("\ntestMesh shaderID at game::start is: %i\n", testMesh->getMaterial()->getShader()->getProgramID());
    playerGO->setMesh(testMesh);

}

void Game::update() {
    
    //std::cout << "Hello_AF_Engine Game update" << std::endl;

    timerService->printFrameRate();

    //If a key is pressed, update the player position
    if (inputService->getKeyPressed()){
        //Key is pressed
        //inputService->printAllKeyEvents();
        if(inputService->getKeyCodePressed(27)){
            LogManager::Log("ESC key pressed");
            thisGameEngine->requestGameExit();
        }
   

        if(inputService->getKeyCodePressed(119)){
                //W key pressed
                playerYPos += 0.1f;
                LogManager::Log("\n w key pressed\n");
            }else if(inputService->getKeyCodePressed(115)){
                //S key pressed
                playerYPos -= 0.1f;
               
            }else if(inputService->getKeyCodePressed(97)){
                //A key pressed
                playerXPos -= 0.1f;
                LogManager::Log("\n a key pressed\n");
            }else if(inputService->getKeyCodePressed(100)){
                //D key pressed
                playerXPos += 0.1f;
                LogManager::Log("\n d key pressed\n");
            }


            //red
            if(inputService->getKeyCodePressed(114)){
                //D key pressed
                currentColor = redColor;
                LogManager::Log("\n r key pressed\n");
            } else if(inputService->getKeyCodePressed(103)){
                //g key pressed
                currentColor = greenColor;
                LogManager::Log("\n g key pressed\n");
            } else if(inputService->getKeyCodePressed(98)){
                //D key pressed
                currentColor = blueColor;
                LogManager::Log("\n b key pressed\n");
            }
    }

    //set the color based on player input.
    playerGO->getMesh().getMaterial()->setMaterialColor(currentColor);
    
    //update the player position
    playerGO->getTransform().position.x = playerXPos;
    playerGO->getTransform().position.y = playerYPos;
    playerGO->update();

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