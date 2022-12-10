/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include <cassert>


Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}

/*******************************************
 * POSITION extraction
 *       Prompt for coordinates
 ******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;
   
   pt.setMetersX(x);
   pt.setMetersY(y);
   
   return in;
}

/******************************************************************************
 * POSITION::ADD
 * Calculates the new x and y after applying velocity.
 ******************************************************************************/
void Position::add(const Velocity & velocity)
{
   setMetersX(getMetersX() + velocity.getX() * TIME);
   setMetersY(getMetersY() + velocity.getY() * TIME);
}

/******************************************************************************
 * * POSITION::ADD
 * Calculates the new x and y after applying velocity and acceleration.
 ******************************************************************************/
void Position::add(const Velocity & velocity, const Acceleration & acceleration)
{
   setMetersX(getMetersX() + (velocity.getX() * TIME) + (0.5 * acceleration.getX() * TIME * TIME));
   setMetersY(getMetersY() + (velocity.getY() * TIME) + (0.5 * acceleration.getY() * TIME * TIME));
}
