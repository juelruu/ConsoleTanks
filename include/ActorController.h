#ifndef ACTORCONTROLLER_H
#include "GameMode.h"
#define ACTORCONTROLLER_H


class ActorController
{
    public:
        ActorController();
        virtual ~ActorController();

        PVector GetControlledActorLocation();
        PVector GetControlledActorLastLocation();
        PVector GetControlledActorRotation();
        std::string GetSprite();

        void SetActorLocation(PVector Location);
        void SetActorRotation(PVector Rotation);
        void SetGamemodePtr(GameMode* newGamemodePtr);
        void SetupInput(const char* PlayerInput);

    private:
        bool MovementPossibility(PVector PossibleLocation);
        class Actor* Tank = nullptr;
        GameMode* GamemodePtr = nullptr;
};

#endif // ACTORCONTROLLER_H
