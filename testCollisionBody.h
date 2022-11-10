#pragma once
#include "collisionBody.h"

class TestCollisionBody
{
public:
   void run()
   {
      test_SameSizeNoVolocityNoCollision();
   }
   
   void test_SameSizeNoVolocityNoCollision()
   {
      // Setup
      CollisionBody body1;
      body1.radius = 5;
      body1.x = 5;
      body1.y = 5;
      body1.dx = 0;
      body1.dy = 0;
      
      CollisionBody body2;
      body2.radius = 5;
      body2.x = -5;
      body2.y = -5;
      body2.dx = 0;
      body2.dy = 0;
      
      
      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);
      
      // Verify
      assert(false == isCollision);
      
      assert(5 == body1.radius);
      assert(5 == body1.x);
      assert(5 == body1.y);
      assert(0 == body1.dx);
      assert(0 == body1.dy);
      
      assert(5 == body2.radius);
      assert(-5 == body2.x);
      assert(-5 == body2.y);
      assert(0 == body2.dx);
      assert(0 == body2.dy);
      // Teardown
   }
};
