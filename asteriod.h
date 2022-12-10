/***********************************************************************
 * Header File:
 *    Asteroid: Space Rock
 * Author:
 *    Michael LeFevre on 12/3/22.
 * Summary:
 *    The Asteroid object, specifically created upon the destruction of
 *    earth
 ************************************************************************/

#pragma once
#include "wreckage.h"



/******************************************************************************
 * ASTEROID
 * This class represents the asteroid object
 ******************************************************************************/
class Asteroid: public Wreckage
{
public:
   Asteroid(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      radius = 0;
   }
   void draw()
   {
      drawSmallAsteroid(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
   }
};