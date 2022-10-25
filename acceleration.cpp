//
//  acceleration.cpp
//  Lab07
//
//  Created by Michael LeFevre on 10/24/22.
//

#include "position.h"

void Acceleration::setDirection(Position position)
{
   Quadrant quad = position.getQuadrant();
   if (quad == Quad1)
   {
      ddx = -1 * abs(ddx);
      ddy = -1 * abs(ddy);
   }
   else if(quad == Quad2)
   {
      ddx = abs(ddx);
      ddy = -1 * abs(ddy);
   }
   else if (quad == Quad3)
   {
      ddx = abs(ddx);
      ddy = abs(ddy);
   }
   else if (quad == Quad4)
   {
      ddx = -1 * abs(ddx);
      ddy = abs(ddy);
   }
   else
      assert(false);
}


Acceleration::Acceleration(double total, double angle, Position position)
{
   ddx = total * cos(angle);
   ddy = total * sin(angle);
   setDirection(position);
}
