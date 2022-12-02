//
//  simulatorObject.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "simulatorObject.h"
#include <vector>
#include "uiDraw.h"

/******************************************************************************
 *
 ******************************************************************************/
void SimulatorObject::advance(const SimulatorObject & gravitySource)
{
   double angle = atan2(gravitySource.getX() - position.getMetersX(), gravitySource.getY() - position.getMetersY());
   double heightAboveEarth = position.getTotalMeters() - gravitySource.getRadius();
   double innerEquation = gravitySource.getRadius() / (gravitySource.getRadius() + heightAboveEarth);
   double gravity = GRAVITY_SEA_LEVEL * innerEquation * innerEquation;
   
   Acceleration accel(gravity, angle, position);
   velocity.add(accel);
   position.add(velocity);
   rotate();
}

/******************************************************************************
 *
 ******************************************************************************/
void SimulatorObject::draw()
{
   drawGPS(getPosition(), rotationAngle.getRadians());
}

/******************************************************************************
  *
  ******************************************************************************/
void SimulatorObject::hit(list<SimulatorObject*> & simulatorCollection)
{
   kill();
  
}

/******************************************************************************
 *
 ******************************************************************************/
void SimulatorObject::rotate()
{
   this->rotationAngle.add(-0.0040);
}

/******************************************************************************
 *
 ******************************************************************************/
CollisionBody SimulatorObject::getCollisionBody()
{
   return CollisionBody(position, velocity, radius);
}

CollisionBody SimulatorObject::getCollisionBody2()
{
   return CollisionBody(position.getPixelsX(), position.getPixelsY(), velocity.getX(), velocity.getY(), radius);
}
