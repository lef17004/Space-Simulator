/***********************************************************************
 * Header File:
 *    Test Collision: Units tests to test the Collision class
 * Author:
 *    Michael LeFevre
 * Summary:
 *    This class contains unit tests made to tes the CollisionBody Class
 ************************************************************************/

#pragma once
#include "collisionBody.h"



/******************************************************************************
 * TESTCOLLISIONBODY
 * This is a collection of tests for the test simulation that focuses on 
 * the collisions throughout the game.
 ******************************************************************************/
class TestCollisionBody
{
public:
   void run()
   {
      test_getX();
      test_getY();
      test_getDx();
      test_getDy();
      test_SameSizeNoVolocityNoCollision();
      test_SameSizeNoVolocityCollision();
      test_DifferentSizeNoVolocityNoCollision();
      test_DifferentSizeNoVolocityCollision();
      test_CollisionWithDx();
      test_CollisionWithDy();
      test_CollisionWithDyDx();
      test_BothMoving();
   }
   
   // Test x getter
   void test_getX()
   {
      //Setup
      CollisionBody obj;
      obj.x = 5;
      obj.y = 5;
      obj.dx = 0;
      obj.dy = 0;

      //Exercise
      double x = obj.getX();

      //Verify
      assert(5 == x);
      assert(5 == obj.x);

      //Teardown
   }

   // Test y getter
   void test_getY()
   {
      //Setup
      CollisionBody obj;
      obj.x = 5;
      obj.y = 5;
      obj.dx = 0;
      obj.dy = 0;

      //Exercise
      double y = obj.getY();

      //Verify
      assert(5 == y);
      assert(5 == obj.y);

      //Teardown
   }

   // Test dx getter
   void test_getDx()
   {
      //Setup
      CollisionBody obj;
      obj.x = 5;
      obj.y = 5;
      obj.dx = 0;
      obj.dy = 0;

      //Exercise
      double dx = obj.getDx();

      //Verify
      assert(0 == dx);
      assert(0 == obj.dx);

      //Teardown
   }

   // Test dy getter
   void test_getDy()
   {
      //Setup
      CollisionBody obj;
      obj.x = 5;
      obj.y = 5;
      obj.dx = 0;
      obj.dy = 0;

      //Exercise
      double dy = obj.getDy();

      //Verify
      assert(0 == dy);
      assert(0 == obj.dy);

      //Teardown
   }

   // Test Collision between objects of the same size with no velocity
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

   // Test Collision between objects of the same size with no velocity
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

   // Test collision of different sized objects
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

   // Test collision of different size objects
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

   // Test collision of objects moving in the y direction
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

   // Test collisions moving in the dx direction
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

   // Test both objects moving 
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