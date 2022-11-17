//
//  collisionBody.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "collisionBody.h"
#include <algorithm>
#include <minwindef.h>

static bool isCollision(CollisionBody box1, CollisionBody box2) {
  
   using std::abs;

   float dMax = max(abs(box1.getDx()), abs(box1.getDy()));
   float dMax = max(dMax, abs(box2.getDx()));
   float dMax = max(dMax, abs(box2.getDy()));

   float distMin = std::numeric_limits<float>::max();

   float slice = 1.0 / dMax;

   

   
}
