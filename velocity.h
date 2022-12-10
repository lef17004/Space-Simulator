/***********************************************************************
 * Header File:
 *    Velocity: Handles the velocity, aka movement of the Objects
 * Author:
 *    Michael LeFevre on 10/24/22.
 * Summary:
 *    This class handles some of the physics of the game dealing with 
 *    velocity.
 ************************************************************************/

#pragma once
#include "acceleration.h"
#include "constants.h"
#include "position.h"
#include <iostream>



/******************************************************************************
 * VELOCITY
 * This class calculates and returns the velocity of various objects throughout
 * the game.
 ******************************************************************************/
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