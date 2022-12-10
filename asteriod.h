//
//  asteriod.h
//  Lab07
//
//  Created by Michael LeFevre on 12/3/22.
//

#pragma once
#include "wreckage.h"

/******************************************************************************
 *
 ******************************************************************************/
class Asteroid: public Wreckage
{
public:
   Asteroid(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      radius = 0;
   }
   
   /******************************************************************************
    *
    ******************************************************************************/
   void draw()
   {
      drawSmallAsteroid(position, rotationAngle.getRadians());
   }
   
   /******************************************************************************
    *
    ******************************************************************************/
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
   }
   
};
