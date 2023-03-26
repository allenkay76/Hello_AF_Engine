#include "Game.h"

Game::Game(){
    std::cout << "Hello_AF_Engine Game constructor" << std::endl;
}

Game::~Game(){
    std::cout << "Hello_AF_Engine Game destructor" << std::endl;    
}

void Game::awake(){            
    std::cout << "Hello_AF_Engine Game awake" << std::endl;
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