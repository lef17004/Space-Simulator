//
//  acceleration.cpp
//  Lab07
//
//  Created by Michael LeFevre on 10/24/22.
//

#include "position.h"
#include "angle.h"

Acceleration::Acceleration(double total, double angle, Position position)
{
   ddx = -total * sin(angle);
   ddy = -total * cos(angle);
}


Acceleration::Acceleration(double total, Angle angle)
{
   ddx = total * sin(angle.getRadians());
   ddy = total * cos(angle.getRadians());
}
