//
//  collisionBody.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once

#include "position.h"
#include "velocity.h"

class CollisionBody
{
private:
   double radius;
   double x;
   double y;
   double dx;
   double dy;
   
public:
   CollisionBody(): x(0), y(0), dx(0), dy(0), radius(0) {}
   CollisionBody(Position position, Velocity velocity, double radius): x(position.getMetersX()), y(position.getMetersY())
                                                                     , dx(velocity.getX()), dy(velocity.getY()), radius(radius) {}
   CollisionBody(double x, double y, double dx, double dy, double radius): x(x), y(y), dx(dx), dy(y), radius(radius) {}
   
   double getRadius() { return radius; }
   double getX() { return x; }
   double getY() { return y; }
   double getDx() { return dx; }
   double getDy() { return dy; }
   
   static bool isCollision(CollisionBody box1, CollisionBody box2);
   static bool isCollision2(CollisionBody obj1, CollisionBody obj2);
   
   friend class TestCollisionBody;
};
