/***********************************************************************
 * Source File:
 *    Earth: Home sweet home
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    The earth Object, home sweet home and all. It rotates, isn't that
 *    fun?
 ************************************************************************/

#include "earth.h"



/******************************************************************************
 * EARTH
 * This class draws Earth and rotates it on screen.
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
 * HIT
 * Detects when Objects hit the Earth, keeps track of Earth lifespan
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