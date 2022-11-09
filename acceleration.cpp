//
//  acceleration.cpp
//  Lab07
//
//  Created by Michael LeFevre on 10/24/22.
//

#include "position.h"


Acceleration::Acceleration(double total, double angle, Position position)
{
   ddx = -total * sin(angle);
   ddy = -total * cos(angle);
}
