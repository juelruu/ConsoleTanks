#include "Projectile.h"

Projectile::Projectile()
{
    Sprite = "*";
}

std::string Projectile::GetSprite()
{
    return Sprite;
}
