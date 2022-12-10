//
//  projectile.h
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

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
   
   void draw() const
   {
      drawProjectile(position);
   }
   void advance(const SimulatorObject & gravitySource);
};
