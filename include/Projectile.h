#ifndef PROJECTILE_H
#include "Actor.h"
#define PROJECTILE_H


class Projectile : public Actor
{
    public:
        Projectile();
        Projectile(PVector Loc, PVector Rot);

        bool GetMoveStatus();
        virtual std::string GetSprite() override;

    protected:
        std::string Sprite;
};

#endif // PROJECTILE_H
