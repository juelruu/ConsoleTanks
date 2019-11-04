#include "Actor.h"

Actor::Actor()
{
    VerticalSprite.push_back("0|");    // Up
    VerticalSprite.push_back("o|");    // Down
    HorizontalSprite.push_back("o-");   // Right
    HorizontalSprite.push_back("-o");   // Left
}

Actor::~Actor()
{

}

void Actor::SetActorLocation(PVector newLocation)
{
    LastLocation = Location;
    Location = newLocation;
}

void Actor::SetActorRotation(PVector newRotation)
{
    Rotaion = newRotation;
}

PVector Actor::GetActorLastLocation()
{
    return LastLocation;
}

PVector Actor::GetActorLocation()
{
    return Location;
}

PVector Actor::GetActorRotation()
{
    return Rotaion;
}

std::string Actor::GetSprite()
{
    if(Rotaion.X != 0)
        if(Rotaion.X > 0)
            return HorizontalSprite[0];
        else
            return HorizontalSprite[1];
    else
        if(Rotaion.Y > 0)
            return VerticalSprite[0];
        else
            return VerticalSprite[1];
}
