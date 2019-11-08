#include "GameMode.h"
#include "Map.h"
#include "ActorController.h"

GameMode::GameMode(int EnemiesCount)
{
    MapClass = new Map;
    PlayerController = new ActorController(nullptr);

    PlayerController->SetActorLocation(PVector(1, 1));
    PlayerController->SetGamemodePtr(this);
    PlayerController->SetActorRotation(PVector(0, 1));

    Actors.push_back(PlayerController);
    for(int i = 0; i < EnemiesCount; i++)
        {
            ActorController* EnemyController = new ActorController(nullptr);
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
    GameMap = MapClass->GetMap();
    if(_kbhit())
        SetPlayerInput();

    PlayerController->SetupInput(InputBuffer);
    for(unsigned int i = 0; i < Actors.size(); i++)
    {
        Actors[i]->Tick();
        UpdateActor(Actors[i]);
    }

    for(unsigned int i = 0; i < GameMap.size(); i++)
    {
        std::cout << GameMap[i] << std::endl;
    }
    //Sleep(1000);
}

void GameMode::UpdateActor(ActorController* Controller)
{
    PVector tmpLocation = Controller->GetControlledActorLocation();
    std::string tmpSprite = Controller->GetSprite();

    switch(tmpSprite.size())
    {
    case 2:
        GameMap[tmpLocation.Y][tmpLocation.X] = tmpSprite[0];
        GameMap[tmpLocation.Y][tmpLocation.X + 1] = tmpSprite[1];
        break;

    case 1:
        GameMap[tmpLocation.Y][tmpLocation.X] = tmpSprite[0];
        break;
    }
}

void GameMode::AddActor(Actor* newActor)
{
    ActorController* newController = new ActorController(newActor);
    newController->SetAutoMovement(true);
    Actors.push_back(newController);
}

bool GameMode::GetGameStatus()
{
    return GameStatus;
}

void GameMode::SetPlayerInput()
{
    InputBuffer = getch();
    PlayerController->SetupInput(InputBuffer);
}

bool GameMode::MovementPossibility(PVector PossibleLocation)
{
    std::string str = GameMap[PossibleLocation.Y];

    if(str.compare(PossibleLocation.X, 1, " ") == 0)
        return true;
    else
        return false;


}
void GameMode::DeleteActor(ActorController* DController)
{
    for(auto &i: Actors)
    {
        if(i == DController)
            delete i;
    }
}
