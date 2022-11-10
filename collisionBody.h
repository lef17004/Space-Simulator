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
   CollisionBody() {}
   CollisionBody(Position position, Velocity velocity, double radius) {}
   CollisionBody(double x, double y, double dx, double dy, double radius) {}
   
   double getRadius() { return 0; }
   double getX() { return 0; }
   double getY() { return 0; }
   double getDx() { return 0; }
   double getDy() { return 0; }
   
   static bool isCollision(CollisionBody box1, CollisionBody box2) { return true; }
   
   friend class TestCollisionBody;
};
