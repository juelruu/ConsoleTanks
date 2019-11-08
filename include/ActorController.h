#ifndef ACTORCONTROLLER_H
#include "GameMode.h"
#define ACTORCONTROLLER_H

class Actor;

class ActorController
{
    public:
        ActorController(Actor*);
        virtual ~ActorController();

        PVector GetControlledActorLocation();
        PVector GetControlledActorRotation();
        std::string GetSprite();

        void Tick();
        void SetAutoMovement(bool);
        void SetActorLocation(PVector Location);
        void SetActorRotation(PVector Rotation);
        void SetGamemodePtr(GameMode* newGamemodePtr);
        void SetupInput(int PlayerInput);
        void Die();

    protected:
        void AutoMovement();
        bool MovementPossibility(PVector PossibleLocation);
        Actor* Controller = nullptr;
        GameMode* GamemodePtr = nullptr;
        bool AutoMovement_b = false;
};

#endif // ACTORCONTROLLER_H
