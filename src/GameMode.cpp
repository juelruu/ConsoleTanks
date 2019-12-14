#include "GameMode.h"
#include "Map.h"
#include "ActorController.h"
#include "Projectile.h"
#include <bits/stdc++.h>

GameMode::GameMode(int EnemiesCount)
{
    MapClass = new Map;
    PlayerController = new ActorController(nullptr);

    PlayerController->SetActorLocation(PVector(1, 1));
    PlayerController->SetGamemodePtr(this);
    PlayerController->SetActorRotation(PVector(0, 1));

    std::vector<PVector> Locs = {PVector(6, 1), PVector(11, 1), PVector(20, 1)};

    Actors.push_back(PlayerController);
    for(int i = 0; i < EnemiesCount; i++)
    {
        ActorController* EnemyController = new ActorController(nullptr);
        EnemyController->SetActorLocation(Locs[i]);
        EnemyController->SetActorRotation(PVector(0, 1));
        EnemyController->SetGamemodePtr(this);
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

    for(auto &x: nActor)
    {
        Actors.push_back(new ActorController(x));
        Actors.back()->SetGamemodePtr(this);
    }

    for(auto &i: Actors)
    {
        UpdateActor(i);
    }
    for(unsigned int i = 0; i < GameMap.size(); i++)
    {
        std::cout << GameMap[i] << std::endl;
    }
    nActor.clear();

    std::cout << Actors.size() << std::endl;

}

void GameMode::UpdateActor(ActorController* Controller)
{
    Controller->Tick();

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

void GameMode::AddActor(PVector Loc, PVector Rot)
{
    nActor.push_back(new Projectile(Loc, Rot));
}

bool GameMode::GetGameStatus()
{
    return GameStatus;
}

void GameMode::SetPlayerInput()
{
    InputBuffer = getch();
    PlayerController->SetupInput(InputBuffer);
    InputBuffer = 0;
}

bool GameMode::MovementPossibility(PVector PossibleLocation)
{
    //std::cout << "GNOTHING" << "-" << PossibleLocation.Y << std::endl;
    if(PossibleLocation.Y > -1 and PossibleLocation.Y < this->GameMap.size())
    {
        //std::cout << "IFNOTHING" << std::endl;
        std::string str = GameMap[PossibleLocation.Y];

        if(str.compare(PossibleLocation.X, 1, " ") == 0)
        {
            //std::cout << "ifNOTHING" << std::endl;
            return true;
        }
        else
        {
            //std::cout << "elseNOTHING" << std::endl;
            return false;
        }
    }
    //else
        //std::cout << "End of str" << std::endl;

    return false;
}
void GameMode::DeleteActor(ActorController* DController)
{
    auto i = std::find(Actors.begin(), Actors.end(), DController);
    if(i != Actors.end())
    {
        Actors.erase(i);
    }
}
