#include "ActorController.h"
#include "Actor.h"
#include "Projectile.h"

ActorController::ActorController(Actor* newActor)
{
    if(newActor != nullptr)
        Controller = newActor;
    else
        Controller = new Actor;

    //std::cout << GamemodePtr << std::endl;
    AutoMovement_b = Controller->GetMoveStatus();
}

ActorController::~ActorController()
{
    delete[] Controller;
}

void ActorController::SetupInput(int PlayerInput)
{
    PVector tmpLocation;
    PVector tmpRotation;

    switch(PlayerInput)
    {
    case 235:
        tmpLocation = GetControlledActorLocation();
        tmpRotation = PVector(0, 1);

        tmpLocation += tmpRotation;
        break;
    case 230:
        tmpLocation = GetControlledActorLocation();
        tmpRotation = PVector(0, -1);

        tmpLocation += tmpRotation;
        break;

    case 228:
        tmpLocation = GetControlledActorLocation();
        tmpRotation = PVector(-1, 0);

        tmpLocation += tmpRotation;
        tmpLocation += tmpRotation;
        break;

    case 162:
        tmpLocation = GetControlledActorLocation();
        tmpRotation = PVector(1, 0);

        tmpLocation += tmpRotation;
        tmpLocation += tmpRotation;
        break;

    case 32:{
        tmpLocation = GetControlledActorLocation();
        tmpRotation = GetControlledActorRotation();

        PVector projetileLocation = tmpLocation;
        projetileLocation += tmpRotation;
        projetileLocation += tmpRotation;

        if(MovementPossibility(projetileLocation))
            GamemodePtr->AddActor(projetileLocation, tmpRotation);
        break;
    }

    default:
        tmpLocation = GetControlledActorLocation();
        tmpRotation = GetControlledActorRotation();
        break;
    }

    if(PlayerInput != 32 and PlayerInput != 0)
    {
        if(MovementPossibility(tmpLocation))
        {
            if(PlayerInput == 162 or PlayerInput == 228)
                tmpLocation -= tmpRotation;
            Controller->SetActorLocation(tmpLocation);
            Controller->SetActorRotation(tmpRotation);
        }
    }

}

bool ActorController::MovementPossibility(PVector PossibleLocation)
{
    //std::cout << this << "----" << "ANOTHING" << std::endl;
    return GamemodePtr->MovementPossibility(PossibleLocation);
}

void ActorController::SetGamemodePtr(GameMode* newGamemodePtr)
{
    GamemodePtr = newGamemodePtr;
}

PVector ActorController::GetControlledActorLocation()
{
    return Controller->GetActorLocation();
}

PVector ActorController::GetControlledActorRotation()
{
    return Controller->GetActorRotation();
}

void ActorController::SetActorLocation(PVector Location)
{
    Controller->SetActorLocation(Location);
}

void ActorController::SetActorRotation(PVector Rotation)
{
    Controller->SetActorRotation(Rotation);
}

std::string ActorController::GetSprite()
{
    return Controller->GetSprite();
}

void ActorController::Tick()
{
    //std::cout << this << "-" << GetAutoMoveStatus() << std::endl;
    if(AutoMovement_b)
        AutoMovement(this);
}

void ActorController::AutoMovement(ActorController* CurrentController)
{
    if(GetAutoMoveStatus())
    {
        //std::cout << CurrentController << "-" << "AutoMove" << CurrentController->GetAutoMoveStatus() << std::endl;

        PVector tmpLocation = CurrentController->GetControlledActorLocation();
        PVector tmpRotation = CurrentController->GetControlledActorRotation();

        tmpLocation += PVector(tmpRotation.X, tmpRotation.Y);

        // TODO Crush!!! is under this line
       // std::cout << "HelloAutoMove" << tmpLocation.X << "-" << tmpLocation.Y << std::endl;
        if(CurrentController->MovementPossibility(tmpLocation))
        {
            //std::cout << "NOTHING" << std::endl;
            CurrentController->SetActorLocation(tmpLocation);
        }
        else
            Die();
    }
}
void ActorController::Die()
{
    GamemodePtr->DeleteActor(this);
}

bool ActorController::GetAutoMoveStatus()
{
    return AutoMovement_b;
}
