#include "ActorController.h"
#include "Actor.h"
#include "Projectile.h"

ActorController::ActorController(Actor* newActor = nullptr)
{
    if(newActor != nullptr)
        Controller = newActor;
    else
        Controller = new Actor;
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
        tmpLocation = Controller->GetActorLocation();
        tmpRotation = PVector(0, 1);

        tmpLocation += tmpRotation;
        break;
    case 230:
        tmpLocation = Controller->GetActorLocation();
        tmpRotation = PVector(0, -1);

        tmpLocation += tmpRotation;
        break;

    case 228:
        tmpLocation = Controller->GetActorLocation();
        tmpRotation = PVector(-1, 0);

        tmpLocation += tmpRotation;
        tmpLocation += tmpRotation;
        break;

    case 162:
        tmpLocation = Controller->GetActorLocation();
        tmpRotation = PVector(1, 0);

        tmpLocation += tmpRotation;
        tmpLocation += tmpRotation;
        break;

    case 32:{
        tmpLocation = Controller->GetActorLocation();
        tmpRotation = Controller->GetActorRotation();

        Projectile* proj = new Projectile;
        PVector projetileLocation = tmpLocation;
        projetileLocation += tmpRotation;
        projetileLocation += tmpRotation;

        proj->SetActorLocation(projetileLocation);
        proj->SetActorRotation(tmpRotation);

        if(MovementPossibility(projetileLocation))
            GamemodePtr->AddActor(proj);
        break;
    }

    default:
        tmpLocation = Controller->GetActorLocation();
        tmpRotation = Controller->GetActorRotation();
        break;
    }

    if(MovementPossibility(tmpLocation))
    {
        if(PlayerInput == 162 or PlayerInput == 228)
            tmpLocation -= tmpRotation;
        Controller->SetActorLocation(tmpLocation);
        Controller->SetActorRotation(tmpRotation);
    }
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

void ActorController::SetAutoMovement(bool var)
{
    AutoMovement_b = var;
}

void ActorController::Tick()
{
    if(AutoMovement_b)
        AutoMovement();
}

void ActorController::AutoMovement()
{
    PVector tmpLocation = GetControlledActorLocation();
    tmpLocation += GetControlledActorRotation();
    tmpLocation += GetControlledActorRotation();
    if(MovementPossibility(tmpLocation))
        SetActorLocation(tmpLocation);
    else
        Die();
}
void ActorController::Die()
{
    GamemodePtr->DeleteActor(this);
}
