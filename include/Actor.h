#ifndef ACTOR_H
#include "ActorController.h"
#define ACTOR_H

/*
    Parent class of all tanks
*/
class Actor
{
    public:
        Actor();
        virtual ~Actor();

        void SetActorLocation(PVector newLocation);
        void SetActorRotation(PVector newRotation);

        PVector GetActorLocation();
        PVector GetActorLastLocation();
        PVector GetActorRotation();
        std::string GetSprite();

    private:
        // ========Sprite========
        std::vector<std::string> VerticalSprite;
        std::vector<std::string> HorizontalSprite;
        // ======================

        // ========Position========
        PVector Location;
        PVector LastLocation;
        PVector Rotaion;
        // ======================




        bool MovementPossibility(PVector MovementVector);

};

#endif // ACTOR_H
