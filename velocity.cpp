//
//  Velocity.cpp
//  Lab07
//
//  Created by Collette Stapley on 11/10/22.
//

#include "velocity.h"

/******************************************************************************
 *
 ******************************************************************************/
void Velocity::add(Acceleration acceleration)
{
   dx = dx + acceleration.getX() * TIME;
   dy = dy + acceleration.getY() * TIME;
}

/******************************************************************************
 *
 ******************************************************************************/
void Velocity::add(Acceleration acceleration, double time)
{
   dx = dx + acceleration.getX() * time;
   dy = dy + acceleration.getY() * time;
}

/******************************************************************************
 *
 ******************************************************************************/
void Velocity::add(double total, Angle angle)
{
   dx += total * sin(angle.getRadians());
   dy += total * cos(angle.getRadians());
}
