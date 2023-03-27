#pragma once
#include "GameEngine/AF_EngineBehaviour.h"
#include <iostream>
#include <memory>
#include "Application/AppData.h"

class Game : public AF_EngineBehaviour
{
    public :
        Game(std::shared_ptr<AppData> appData) ;
        ~Game();
        void awake() override;
        void start() override;
        void update() override;
        void shutdown() override;
    private:
        std::shared_ptr<AppData> m_appDataPtr = nullptr;
        
};