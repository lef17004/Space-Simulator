//
//  earth.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "simulatorObject.h"
#include "uiDraw.h"
#include "collisionBody.h"
#pragma once


class Earth : public SimulatorObject
{
public:
   Earth()
   {
      position = Position(0, 0);
      velocity = Velocity(0, 0);
      radius = EARTH_RADIUS;
      rotationAngle = Angle();
   }
   
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
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection)
   {
      
   }
   
   CollisionBody getCollisionBody2()
   {
      return CollisionBody(position.getPixelsX(), position.getPixelsY(), velocity.getX(), velocity.getY(), 50.0);
   }

};
