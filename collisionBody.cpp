//
//  collisionBody.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "collisionBody.h"
#include <algorithm>
using namespace std;

bool CollisionBody::isCollision(CollisionBody box1, CollisionBody box2) {
  
   using std::abs;

   double dMax = max(abs(box1.getDx()), abs(box1.getDy()));
   dMax = max(dMax, abs(box2.getDx()));
   dMax = max(dMax, abs(box2.getDy()));

   double distMin = std::numeric_limits<double>::max();

   double slice = 1.0 / dMax;

   

   return false;
}
