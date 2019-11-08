#ifndef PROJECTILE_H
#include "Actor.h"
#define PROJECTILE_H


class Projectile : public Actor
{
    public:
        Projectile();
        std::string GetSprite();

    protected:
        std::string Sprite;
};

#endif // PROJECTILE_H
