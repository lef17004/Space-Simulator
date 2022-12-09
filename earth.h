//
//  earth.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "simulatorObject.h"
#include "uiDraw.h"
#include "collisionBody.h"
#include "asteriod.h"
#pragma once

/******************************************************************************
 * EARTH
 * This class draws Earth and rotates it on screen.
 ******************************************************************************/
class Earth : public SimulatorObject
{
private:
   int life;
public:
   Earth();
   
   virtual void rotate()
   {
      rotationAngle.add(-(2.0 * M_PI / 30.0 ) * (1440 / 86400.0));
   }
   
   virtual void draw()
   {
      drawEarth(position, rotationAngle.getRadians());
   }
   
   virtual void advance(const SimulatorObject & earth)
   {
      rotate();
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
   
   CollisionBody getCollisionBody2()
   {
      return CollisionBody(position.getPixelsX(), position.getPixelsY(), velocity.getX(), velocity.getY(), 50.0);
   }

};
