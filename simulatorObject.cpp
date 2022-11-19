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
void SimulatorObject::advance(const SimulatorObject & earth)
{
   // TODO: Make physics formula file 
   double angle = atan2(earth.getX() - position.getMetersX(), earth.getY() - position.getMetersY());
   double heightAboveEarth = position.getTotalMeters() - earth.getRadius();
   double innerEquation = earth.getRadius() / (earth.getRadius() + heightAboveEarth);
   double gravity = GRAVITY_SEA_LEVEL * innerEquation * innerEquation;
   
   Acceleration accel(gravity, angle, position);
   velocity.add(accel);
   position.add(velocity, accel);
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
std::vector<SimulatorObject> SimulatorObject::hit()
{
   kill();
   return std::vector<SimulatorObject>();
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
