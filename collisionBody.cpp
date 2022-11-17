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

/******************************************************************************
 * This class gets the points of the various bodies and will get the distances of 
 * the bodies to see if they collide.
 ******************************************************************************/
bool CollisionBody::isCollision(CollisionBody box1, CollisionBody box2) {
  
   // Finding the maximum distance travelled
   using std::abs;

   double dMax = max(abs(box1.getDx()), abs(box1.getDy()));
   dMax = max(dMax, abs(box2.getDx()));
   dMax = max(dMax, abs(box2.getDy()));
   dMax = max(dMax, 0.1);

   // Advance number
   float  distMin = std::numeric_limits<double>::max();

   // Percent of the speed
   double slice = 1.0 / dMax;

   // Cycling through percentage points
   for (float percent = 0.0; percent <= 1.0; percent += slice) {
      // Finding the points of the LHS and the RHS manually
      float x1 = box1.getX() + (box1.getDx() * percent);
      float y1 = box1.getY() + (box1.getDy() * percent);
      float x2 = box2.getX() + (box2.getDx() * percent);
      float y2 = box2.getY() + (box2.getDy() * percent);
      
      // How far apart they are now
      float distSquared = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));

      distMin = min(distMin, distSquared);
   }

   if (sqrt(distMin) < box1.getRadius() + box2.getRadius())
      return true;
   return false;
}
