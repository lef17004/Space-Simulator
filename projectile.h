/***********************************************************************
 * Header File:
 *    Projectile: Space bullets
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class holds all necessary information about the projectiles,
 *    aka bullets that the Dreamchaser uses.
 ************************************************************************/

#pragma once
#include "simulatorObject.h"
#include "uiDraw.h"
#include "lifespan.h"



/******************************************************************************
 * PROJECTILE
 * This class holds the essentials for the projectiles in the game.
 ******************************************************************************/
class Projectile: public SimulatorObject
{
private:
   LifeSpan life;
public:
   Projectile(const Position & position, const Velocity & velocity, const Angle & angle);
   Projectile() {}
   
   void draw()
   {
      drawProjectile(position);
   }
   void advance(const SimulatorObject & gravitySource);
};
