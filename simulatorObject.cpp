/***********************************************************************
 * Source File:
 *    Simuator Object: Base Class for All objects
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class holds all the necessary information that All objects
 *    use
 ************************************************************************/

#include "simulatorObject.h"
#include <vector>
#include "uiDraw.h"



/******************************************************************************
 * ADVANCE
 * Moves the object, using all the necessary physics
 ******************************************************************************/
void SimulatorObject::advance(const SimulatorObject & gravitySource)
{
   double angle = atan2(gravitySource.getX() - position.getMetersX(), gravitySource.getY() - position.getMetersY());
   double heightAboveEarth = position.getTotalMeters() - gravitySource.getRadius();
   double innerEquation = gravitySource.getRadius() / (gravitySource.getRadius() + heightAboveEarth);
   double gravity = GRAVITY_SEA_LEVEL * innerEquation * innerEquation;
   
   Acceleration accel(gravity, angle, true);
   velocity.add(accel);
   position.add(velocity);
   rotate();
}

/******************************************************************************
 * DRAW
 * Draws the simulator object on the screen.
 ******************************************************************************/
void SimulatorObject::draw()
{
   drawGPS(getPosition(), rotationAngle.getRadians());
}

/******************************************************************************
  * HIT
  * Kills the object when hit.
  ******************************************************************************/
void SimulatorObject::hit(list<SimulatorObject*> & simulatorCollection)
{
   kill();
}

/******************************************************************************
 * ROTATE
 * Rotates the object based on the rotation angle and rotation amount.
 ******************************************************************************/
void SimulatorObject::rotate()
{
   this->rotationAngle.add(rotationAmount);
}

/******************************************************************************
 * GETCOLLISIONBODY
 * Gets the collision body and returns it.
 ******************************************************************************/
CollisionBody SimulatorObject::getCollisionBody()
{
   return CollisionBody(position, velocity, radius);
}

/******************************************************************************
 * GETCOLLISIONBODY2
 * Gets the second collision body and returns it.
 ******************************************************************************/
CollisionBody SimulatorObject::getCollisionBody2()
{
   return CollisionBody(position.getPixelsX(), position.getPixelsY(), velocity.getX(), velocity.getY(), radius);
}