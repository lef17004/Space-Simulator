//
//  earth.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "earth.h"

/******************************************************************************
 *
 ******************************************************************************/
Earth::Earth()
{
   position = Position(0, 0);
   velocity = Velocity(0, 0);
   radius = EARTH_RADIUS;
   rotationAngle = Angle();
   life = 10;
}

/******************************************************************************
 *
 ******************************************************************************/
void Earth::hit(std::list<SimulatorObject*> & simulatorCollection)
{
   if (life == 0)
   {
      kill();
      radius = 0;
      return;
   }
   
   life--;
   if (life == 0)
   {
      for (int i = 0; i < 60; i++)
         simulatorCollection.push_back(new Asteroid(position, velocity));
   }
   
   }
