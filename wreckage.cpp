//
//  Wreckage.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "wreckage.h"

/******************************************************************************
 *
 ******************************************************************************/
Wreckage::Wreckage(const Position& position, const Velocity& velocity)
{
   double randomAngle = random(1, 360);
   Angle angle;
   angle.setDegrees(randomAngle);
   double totalVelocity = velocity.getTotal();
   
   this->velocity = velocity;
   this->velocity.add(random(1000, 4000), angle);
   
   
   int pixelsX = 20.0 * sin(angle.getRadians());
   int pixelsY = 20.0 * cos(angle.getRadians());
   
   this->position = position;
   this->position.setPixelsX(this->position.getPixelsX() + pixelsX);
   this->position.setPixelsY(this->position.getPixelsY() + pixelsY);
   alive = true;
}

/******************************************************************************
 *
 ******************************************************************************/

