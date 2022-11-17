//
//  collisionBody.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "collisionBody.h"
#include "position.h"
#include <algorithm>
using namespace std;

bool CollisionBody::isCollision(CollisionBody box1, CollisionBody box2) {
  
   using std::abs;

   double dMax = max(abs(box1.getDx()), abs(box1.getDy()));
   dMax = max(dMax, abs(box2.getDx()));
   dMax = max(dMax, abs(box2.getDy()));

   float  distMin = std::numeric_limits<double>::max();

   double slice = 1.0 / dMax;

   for (float percent = 0.0; percent <= 1.0; percent += slice) {
      float x1 = box1.getX() + (box1.getDx() * percent);
      float y1 = box1.getY() + (box1.getDy() * percent);
      float x2 = box2.getX() + (box2.getDx() * percent);
      float y2 = box2.getY() + (box2.getDy() * percent);
      
      float distSquared = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

      float distMin = min(distMin, distSquared);
   }

   if (distMin < box1.getRadius() + box2.getRadius())
      return true;
   return false;
}
