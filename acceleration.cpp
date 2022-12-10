/***********************************************************************
 * Source File:
 *    Acceleration: Calculates the acceleration
 * Author:
 *    Michael LeFevre on 10/24/22.
 * Summary:
 *    Calculates the acceleration throughout the game for all the objects
 *    in play
 ************************************************************************/

#include "position.h"
#include "angle.h"



/******************************************************************************
 * ACCELERATION
 * Class constructor that takes total, radians and reverse inputs
 ******************************************************************************/
Acceleration::Acceleration(double total, double radians, bool reverse)
{
   ddx = total * sin(radians);
   ddy = total * cos(radians);
   
   if (reverse)
      this->reverse();
}

/******************************************************************************
 * ACCELERATION
 * Class constructor that takes total and angle as inputs
 ******************************************************************************/
Acceleration::Acceleration(double total, const Angle & angle)
{
   ddx = total * sin(angle.getRadians());
   ddy = total * cos(angle.getRadians());
}

/******************************************************************************
 * REVERSE
 * Reverses the acceleration
 ******************************************************************************/
void Acceleration::reverse()
{
   ddx *= -1;
   ddy *= -1;
}