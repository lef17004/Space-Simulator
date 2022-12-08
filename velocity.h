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
#include <iostream>

class Velocity
{
private:
   double dx;
   double dy;
   
   
public:
   Velocity(): dx(0), dy(0) {}
   Velocity(double dx, double dy): dx(dx), dy(dy) {}
   
   void add(Acceleration acceleration);
   void add(Acceleration acceleration, double time);
   void add(double total, Angle angle);
   
   double getX() const { return dx; }
   double getY() const { return dy; }
   void setX(double x) { dx = x; }
   void setY(double y) { dy = y; }
   double getTotal() const { return sqrt(dx * dx + dy * dy); }
   
   Velocity & operator == (const Velocity & rhs)
   {
      dx = rhs.dx;
      dy = rhs.dy;
      return *this;
   }
};
