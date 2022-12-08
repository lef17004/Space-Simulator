//
//  acceleration.cpp
//  Lab07
//
//  Created by Michael LeFevre on 10/24/22.
//

#include "position.h"
#include "angle.h"

/******************************************************************************
 *
 ******************************************************************************/
Acceleration::Acceleration(double total, double radians, bool reverse)
{
   ddx = total * sin(radians);
   ddy = total * cos(radians);
   
   if (reverse)
      this->reverse();
}

/******************************************************************************
 *
 ******************************************************************************/
Acceleration::Acceleration(double total, const Angle & angle)
{
   ddx = total * sin(angle.getRadians());
   ddy = total * cos(angle.getRadians());
}

/******************************************************************************
 *
 ******************************************************************************/
void Acceleration::reverse()
{
   ddx *= -1;
   ddy *= -1;
}
