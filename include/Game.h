#pragma once
#include "GameEngine/AF_EngineBehaviour.h"
#include <iostream>

class Game : public AF_EngineBehaviour
{
    public :
        Game() ;
        ~Game();
        void awake() override;
        void start() override;
        void update() override;
        void shutdown() override;

        
};