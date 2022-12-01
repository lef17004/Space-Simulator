//
//  velocity.h
//  Lab07
//
//  Created by Michael LeFevre on 10/24/22.
//

#pragma once
#include "acceleration.h"
#include "constants.h"
#include "position.h"

class Velocity
{
private:
   double dx;
   double dy;
   
   
public:
   Velocity(): dx(0), dy(0) {}
   Velocity(double dx, double dy): dx(dx), dy(dy) {}
   
   void add(Acceleration acceleration)
   {
      dx = dx + acceleration.getX() * TIME;
      dy = dy + acceleration.getY() * TIME;
   }
   
   void add(Acceleration acceleration, double time)
   {
      dx = dx + acceleration.getX() * time;
      dy = dy + acceleration.getY() * time;
   }
   
   double getX() const { return dx; }
   double getY() const { return dy; }
   void setX(double x) { dx = x; }
   void setY(double y) { dy = y; }
   
   Velocity & operator == (Velocity & rhs)
   {
      dx = rhs.dx;
      dy = rhs.dy;
      return *this;
   }
};
