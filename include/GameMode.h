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
        void AddActor(class Actor* newActor);
        void DeleteActor(class ActorController* DController);
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
        int InputBuffer;
};

#endif // GAMEMODE_H
