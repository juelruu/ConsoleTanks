#include "GameMode.h"
#include "Map.h"
#include "ActorController.h"
#include <windows.h>

GameMode::GameMode(int EnemiesCount)
{
    MapClass = new Map;
    PlayerController = new ActorController;

    PlayerController->SetActorLocation(PVector(1, 1));
    PlayerController->SetGamemodePtr(this);
    PlayerController->SetActorRotation(PVector(0, 1));

    Actors.push_back(PlayerController);
    for(int i = 0; i < EnemiesCount; i++)
        {
            ActorController* EnemyController = new ActorController;
            EnemyController->SetActorLocation(PVector(1, 4));
            EnemyController->SetActorRotation(PVector(0, 1));
            Actors.push_back(EnemyController);
        }

    GameMap = MapClass->GetMap();
}

GameMode::~GameMode()
{
    delete[] MapClass;
    delete[] PlayerController;
    //delete[] Actors;
}

void GameMode::Play()
{
    system("cls");
    PlayerController->SetupInput(InputBuffer);
    InputBuffer[0] = 'x';
    for(unsigned int i = 0; i < Actors.size(); i++)
        UpdateActor(Actors[i]);

    for(unsigned int i = 0; i < GameMap.size(); i++)
    {
        std::cout << GameMap[i] << std::endl;
    }
    Sleep(1000);
}

void GameMode::UpdateActor(ActorController* Controller)
{
    PVector tmpLocation = Controller->GetControlledActorLocation();
    PVector tmpLastLocation = Controller->GetControlledActorLastLocation();
    std::string tmpSprite = Controller->GetSprite();

    GameMap[tmpLastLocation.Y][tmpLastLocation.X] = ' ';
    GameMap[tmpLastLocation.Y][tmpLastLocation.X + 1] = ' ';

    GameMap[tmpLocation.Y][tmpLocation.X] = tmpSprite[0];
    GameMap[tmpLocation.Y][tmpLocation.X + 1] = tmpSprite[1];
}

bool GameMode::GetGameStatus()
{
    return GameStatus;
}

void GameMode::SetPlayerInput()
{
    while(GameStatus)
    {
        std::cin >> InputBuffer;
        std::cout << "INPUT " << InputBuffer << std::endl;
    }
}

bool GameMode::MovementPossibility(PVector PossibleLocation)
{
    std::string str = GameMap[PossibleLocation.X];

    if(str.compare(PossibleLocation.Y, 1, " ") == 0)
    {
        std::cout << "HELLOOO" << std::endl;
        return true;
    }
    else
    {
        std::cout << str[PossibleLocation.Y] << std::endl;
        return false;
    }


}
