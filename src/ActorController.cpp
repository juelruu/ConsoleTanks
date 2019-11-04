#include "ActorController.h"
#include "Actor.h"

ActorController::ActorController()
{
    Tank = new Actor;
}

ActorController::~ActorController()
{
    delete[] Tank;
}

void ActorController::SetupInput(const char* PlayerInput)
{
    PVector tmpLocation;
    PVector tmpRotation;
    if(strcmp(PlayerInput, "w"))
    {
        tmpLocation = Tank->GetActorLocation();
        tmpRotation = PVector(0, 1);

        Tank->SetActorRotation(tmpRotation);

        tmpLocation += tmpRotation;
    }
    else if(strcmp(PlayerInput, "s"))
    {
        tmpLocation = Tank->GetActorLocation();
        tmpRotation = PVector(0, -1);

        Tank->SetActorRotation(tmpRotation);

        tmpLocation += tmpRotation;
    }
    else if(strcmp(PlayerInput, "a"))
    {
        tmpLocation = Tank->GetActorLocation();
        tmpRotation = PVector(-1, 0);

        Tank->SetActorRotation(tmpRotation);

        tmpLocation += tmpRotation;
    }

    else if(strcmp(PlayerInput, "d"))
    {
        tmpLocation = Tank->GetActorLocation();
        tmpRotation = PVector(1, 0);

        Tank->SetActorRotation(tmpRotation);

        tmpLocation += tmpRotation;
    }
    else
    {
        std::cout << PlayerInput << std::endl;
    }

    if(MovementPossibility(tmpLocation))
    {
        Tank->SetActorLocation(tmpLocation);
        std::cout << tmpLocation.X << std::endl;
        //system("pause > nul");
    }
}

PVector ActorController::GetControlledActorLastLocation()
{
    return Tank->GetActorLastLocation();
}

bool ActorController::MovementPossibility(PVector PossibleLocation)
{
    return GamemodePtr->MovementPossibility(PossibleLocation);
}

void ActorController::SetGamemodePtr(GameMode* newGamemodePtr)
{
    GamemodePtr = newGamemodePtr;
}

PVector ActorController::GetControlledActorLocation()
{
    return Tank->GetActorLocation();
}

PVector ActorController::GetControlledActorRotation()
{
    return Tank->GetActorRotation();
}

void ActorController::SetActorLocation(PVector Location)
{
    Tank->SetActorLocation(Location);
}

void ActorController::SetActorRotation(PVector Rotation)
{
    Tank->SetActorRotation(Rotation);
}

std::string ActorController::GetSprite()
{
    return Tank->GetSprite();
}
