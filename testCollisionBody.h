#pragma once
#include "collisionBody.h"

class TestCollisionBody
{
public:
   void run()
   {
      test_SameSizeNoVolocityNoCollision();
      test_SameSizeNoVolocityCollision();
      test_DifferentSizeNoVolocityNoCollision();
      test_DifferentSizeNoVolocityCollision();
      test_CollisionWithDx();
      test_CollisionWithDy();
      test_CollisionWithDyDx();
      test_BothMoving();
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

   void test_SameSizeNoVolocityCollision()
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
      body2.x = 4;
      body2.y = 5;
      body2.dx = 0;
      body2.dy = 0;


      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);

      // Verify
      assert(true == isCollision);

      assert(5 == body1.radius);
      assert(5 == body1.x);
      assert(5 == body1.y);
      assert(0 == body1.dx);
      assert(0 == body1.dy);

      assert(5 == body2.radius);
      assert(4 == body2.x);
      assert(5 == body2.y);
      assert(0 == body2.dx);
      assert(0 == body2.dy);
      // Teardown
   }

   void test_DifferentSizeNoVolocityNoCollision()
   {
      // Setup
      CollisionBody body1;
      body1.radius = 5;
      body1.x = 0;
      body1.y = 0;
      body1.dx = 0;
      body1.dy = 0;

      CollisionBody body2;
      body2.radius = 10;
      body2.x = 16;
      body2.y = 16;
      body2.dx = 0;
      body2.dy = 0;


      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);

      // Verify
      assert(false == isCollision);

      assert(5 == body1.radius);
      assert(0 == body1.x);
      assert(0 == body1.y);
      assert(0 == body1.dx);
      assert(0 == body1.dy);

      assert(10 == body2.radius);
      assert(16 == body2.x);
      assert(16 == body2.y);
      assert(0 == body2.dx);
      assert(0 == body2.dy);
      // Teardown
   }

   void test_DifferentSizeNoVolocityCollision()
   {
      // Setup
      CollisionBody body1;
      body1.radius = 5;
      body1.x = 0;
      body1.y = 0;
      body1.dx = 0;
      body1.dy = 0;

      CollisionBody body2;
      body2.radius = 10;
      body2.x = 10;
      body2.y = 10;
      body2.dx = 0;
      body2.dy = 0;


      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);

      // Verify
      assert(true == isCollision);

      assert(5 == body1.radius);
      assert(0 == body1.x);
      assert(0 == body1.y);
      assert(0 == body1.dx);
      assert(0 == body1.dy);

      assert(10 == body2.radius);
      assert(10 == body2.x);
      assert(10 == body2.y);
      assert(0 == body2.dx);
      assert(0 == body2.dy);
      // Teardown
   }

   void test_CollisionWithDx()
   {
      // Setup
      CollisionBody body1;
      body1.radius = 5;
      body1.x = 0;
      body1.y = 0;
      body1.dx = 60;
      body1.dy = 0;

      CollisionBody body2;
      body2.radius = 10;
      body2.x = 20;
      body2.y = 0;
      body2.dx = 0;
      body2.dy = 0;


      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);

      // Verify
      assert(true == isCollision);

      assert(5 == body1.radius);
      assert(0 == body1.x);
      assert(0 == body1.y);
      assert(60 == body1.dx);
      assert(0 == body1.dy);

      assert(10 == body2.radius);
      assert(20 == body2.x);
      assert(0 == body2.y);
      assert(0 == body2.dx);
      assert(0 == body2.dy);
      // Teardown
   }

   void test_CollisionWithDy()
   {
      // Setup
      CollisionBody body1;
      body1.radius = 5;
      body1.x = 0;
      body1.y = 0;
      body1.dx = 0;
      body1.dy = 100;

      CollisionBody body2;
      body2.radius = 10;
      body2.x = 0;
      body2.y = 20;
      body2.dx = 0;
      body2.dy = 0;


      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);

      // Verify
      assert(true == isCollision);

      assert(5 == body1.radius);
      assert(0 == body1.x);
      assert(0 == body1.y);
      assert(0 == body1.dx);
      assert(100 == body1.dy);

      assert(10 == body2.radius);
      assert(0 == body2.x);
      assert(20 == body2.y);
      assert(0 == body2.dx);
      assert(0 == body2.dy);
      // Teardown
   }

   void test_CollisionWithDyDx()
   {
      // Setup
      CollisionBody body1;
      body1.radius = 5;
      body1.x = 0;
      body1.y = 0;
      body1.dx = 100;
      body1.dy = 100;

      CollisionBody body2;
      body2.radius = 10;
      body2.x = 20;
      body2.y = 20;
      body2.dx = 0;
      body2.dy = 0;


      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);

      // Verify
      assert(true == isCollision);

      assert(5 == body1.radius);
      assert(0 == body1.x);
      assert(0 == body1.y);
      assert(100 == body1.dx);
      assert(100 == body1.dy);

      assert(10 == body2.radius);
      assert(20 == body2.x);
      assert(20 == body2.y);
      assert(0 == body2.dx);
      assert(0 == body2.dy);
      // Teardown
   }

   void test_BothMoving()
   {
      // Setup
      CollisionBody body1;
      body1.radius = 5;
      body1.x = 0;
      body1.y = 0;
      body1.dx = 100;
      body1.dy = 100;

      CollisionBody body2;
      body2.radius = 10;
      body2.x = 20;
      body2.y = 20;
      body2.dx = -100;
      body2.dy = -100;


      // Exercise
      bool isCollision = CollisionBody::isCollision(body1, body2);

      // Verify
      assert(true == isCollision);

      assert(5 == body1.radius);
      assert(0 == body1.x);
      assert(0 == body1.y);
      assert(100 == body1.dx);
      assert(100 == body1.dy);

      assert(10 == body2.radius);
      assert(20 == body2.x);
      assert(20 == body2.y);
      assert(-100 == body2.dx);
      assert(-100 == body2.dy);
      // Teardown
   }
};
