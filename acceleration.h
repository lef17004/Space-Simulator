//
//  acceleration.h
//  Lab07
//
//  Created by Michael LeFevre on 10/24/22.
//

#pragma once
#include "position.h"
class Position;

class Acceleration
{
private:
   double ddx;
   double ddy;
   
public:
   Acceleration(): ddx(0), ddy(0) {}
   Acceleration(double ddx, double ddy): ddx(ddx), ddy(ddy) {}
   Acceleration(double total, double angle, Position position);
   double getX() { return ddx; }
   double getY() { return ddy; }
};
