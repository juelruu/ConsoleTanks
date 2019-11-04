#ifndef GAMEMODE_H
#include "CustomStructures.h"
#define GAMEMODE_H

class ActorController;

class GameMode
{
    public:
        GameMode(int EnemiesCount);
        virtual ~GameMode();

        void Play();
        bool GetGameStatus();
        void SetPlayerInput();
        bool MovementPossibility(PVector PossibleLocation);

    private:
        void UpdateActor(ActorController* Controller);

        ActorController* PlayerController  = nullptr;
        class Map* MapClass = nullptr;

        std::vector<std::string> GameMap;

        bool GameStatus = true;

        std::vector<ActorController*> Actors;
        char* InputBuffer = new char[1];
};

#endif // GAMEMODE_H
