#include "Projectile.h"

Projectile::Projectile()
{
    Sprite = "*";
    AutoMove_b = true;
}

std::string Projectile::GetSprite()
{
    return Sprite;
}

Projectile::Projectile(PVector Loc, PVector Rot)
{
    Sprite = "*";

    SetActorLocation(Loc);
    SetActorRotation(Rot);
    AutoMove_b = true;
}
