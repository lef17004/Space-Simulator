/***********************************************************************
 * Source File:
 *    Projectile: Space bullets
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class holds all necessary information about the projectiles,
 *    aka bullets that the Dreamchaser uses.
 ************************************************************************/

#include "projectile.h"



/******************************************************************************
 * Constructor for the projectile class.
 * Gives a boost of 9000 m/s to the projectile's velocity.
 ******************************************************************************/
Projectile::Projectile(const Position & position, const Velocity & velocity, const Angle & angle)
{
   this->position = rotate2(position, 0.0, 19.0, angle.getRadians());
   this->velocity = velocity;
   this->velocity.add(9000.0, angle);
   radius = 1;
}

/******************************************************************************
 * Adances the projectile forward 1 frame.
 ******************************************************************************/
void Projectile::advance(const SimulatorObject & gravitySource)
{
   SimulatorObject::advance(gravitySource);
   life.advance();
   
   if (!life.isAlive())
      kill();
}