//
//  Velocity.cpp
//  Lab07
//
//  Created by Collette Stapley on 11/10/22.
//

#include "velocity.h"

/******************************************************************************
 * VELOCITY::ADD
 * Uses time of the simulation to calculate the velocity.
 ******************************************************************************/
void Velocity::add(Acceleration acceleration)
{
   dx = dx + acceleration.getX() * TIME;
   dy = dy + acceleration.getY() * TIME;
}

/******************************************************************************
 * VELOCITY::ADD
 * Uses designated time by the user to calculate the velocity.
 ******************************************************************************/
void Velocity::add(Acceleration acceleration, double time)
{
   dx = dx + acceleration.getX() * time;
   dy = dy + acceleration.getY() * time;
}

/******************************************************************************
 * VELOCITY::ADD
 * Total increase of velocity, divides it along x and y axis based off of angle to
 * get the total.
 ******************************************************************************/
void Velocity::add(double total, Angle angle)
{
   dx += total * sin(angle.getRadians());
   dy += total * cos(angle.getRadians());
}
