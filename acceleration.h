//
//  acceleration.h
//  Lab07
//
//  Created by Michael LeFevre on 10/24/22.
//

#pragma once
#include "position.h"
#include "angle.h"

// Forward Declaration
class Position;

/******************************************************************************
 * ACCELERATION
 * This class calculates the acceleration throughout the game.
 ******************************************************************************/
class Acceleration
{
private:
   double ddx;
   double ddy;
   
public:
   Acceleration(): ddx(0), ddy(0) {}
   Acceleration(double ddx, double ddy): ddx(ddx), ddy(ddy) {}
   Acceleration(double total, const Angle & angle);
   Acceleration(double total, double radians, bool reverse = false);
   
   double getX() const { return ddx; }
   double getY() const { return ddy; }
   void reverse();
};
