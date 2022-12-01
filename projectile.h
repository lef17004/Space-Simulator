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

class Projectile: public SimulatorObject
{
private:
   LifeSpan life;
public:
   Projectile(const Position & position, const Velocity & velocity, const Angle & angle)
   {
      this->position = rotate2(position, 0.0, 19.0, angle.getRadians());
      this->velocity = velocity;
      this->velocity.add(9000.0, angle);
      radius = 1;
   }
   Projectile() {}
   
   void draw()
   {
      drawProjectile(position);
   }
   
   void advance(const SimulatorObject & gravitySource)
   {
      SimulatorObject::advance(gravitySource);
      life.advance();
      
      if (!life.isAlive())
         kill();
   }
};
