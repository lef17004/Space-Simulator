/***********************************************************************
 * Header File:
 *    Test Simulator Object: Units tests to test the SimulatorObject class
 * Author:
 *    Michael LeFevre
 * Summary:
 *    This class contains unit tests made to tes the SimulatorObject Class
 ************************************************************************/

#pragma once

#include "simulatorObject.h"
#include "position.h"
#include "velocity.h"
#include "earth.h"



/******************************************************************************
 * TESTSIMULATOROBJECT
 * This is a collection of tests for the test simulation that focuses on
 * the simulation objects throughout the game.
 ******************************************************************************/
class TestSimulatorObject
{
public:
   void run()
   {
      test_defaultConstructor();
      test_nonDefaultConstructor();
      test_advanceFrameOne();
      test_advanceFrameTwo();
      test_advanceFrameThree();
      test_hitNoWreckage();
      test_getCollisionBody();
      test_getRadius();
      test_setRadius();
      test_getPosition();
      test_setPosition();
      test_getX();
      test_getY();
      test_setX();
      test_setY();
      test_getVelocity();
      test_setVelocity();
      test_getDx();
      test_setDx();
      test_getDy();
      test_setDy();
      test_isAlive();
      test_setAlive();
      test_getHeight();
      
   }
   
   // Test default constructor
   void test_defaultConstructor()
   {
      // Setup
      SimulatorObject obj;
      
      
      // Exercise
      
      
      // Verify
      assert(0 == obj.position.getMetersX());
      assert(0 == obj.position.getMetersY());
      assert(0 == obj.velocity.getX());
      assert(0 == obj.velocity.getY());
      assert(0 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test nondefault constructor
   void test_nonDefaultConstructor()
   {
      // Setup
      SimulatorObject obj(Position(10, 20), Velocity(30, 40), 100);
      
      
      // Exercise
      
      
      // Verify
      assert(10 == obj.position.getMetersX());
      assert(20 == obj.position.getMetersY());
      assert(30 == obj.velocity.getX());
      assert(40 == obj.velocity.getY());
      assert(100 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test 1 frame of movement
   void test_advanceFrameOne()
   {
      // Setup
      SimulatorObject satellite;
      satellite.setX(0);
      satellite.setY(42164000);
      satellite.setDx(3100);
      satellite.setDy(0);
      satellite.radius = 10;
      satellite.alive = true;
      
      Earth earth;
      earth.setX(0);
      earth.setY(0);
      
      // Exercise
      satellite.advance(earth);
      
      // Verify
      assert(closeEnough(satellite.getX(), 148800.0, 0.001));
      assert(closeEnough(satellite.getY(), 42163483.002, 0.001));
      assert(3100 == satellite.getDx());
      assert(closeEnough(satellite.getDy(), -10.771, 0.001));
      assert(10 == satellite.radius);
      assert(true == satellite.isAlive());
      
      // Teardown
   }
   
   // Test 2 frames of movement
   void test_advanceFrameTwo()
   {
      // Setup
      SimulatorObject satellite;
      satellite.setX(0);
      satellite.setY(42164000);
      satellite.setDx(3100);
      satellite.setDy(0);
      satellite.radius = 10;
      satellite.alive = true;
      
      Earth earth;
      earth.setX(0);
      earth.setY(0);
      
      satellite.advance(earth);
      
      // Exercise
      satellite.advance(earth);
      
      // Verify
      assert(closeEnough(satellite.getX(), 297598.175, 0.001));
      assert(closeEnough(satellite.getY(), 42162449.004, 0.001));
      assert(closeEnough(satellite.getDx(), 3099.962, 0.001));
      assert(closeEnough(satellite.getDy(), -21.542, 0.001));
      assert(10 == satellite.radius);
      assert(true == satellite.isAlive());
      
      // Teardown
      
   }
   
   // Test three frames of movment
   void test_advanceFrameThree()
   {
      // Setup
      SimulatorObject satellite;
      satellite.setX(0);
      satellite.setY(42164000);
      satellite.setDx(3100);
      satellite.setDy(0);
      satellite.radius = 10;
      satellite.alive = true;
      
      Earth earth;
      earth.setX(0);
      earth.setY(0);
      
      satellite.advance(earth);
      satellite.advance(earth);
      
      // Exercise
      satellite.advance(earth);
      
      // Verify
      assert(closeEnough(satellite.getX(), 446392.701, 0.001));
      assert(closeEnough(satellite.getY(), 42160898.008, 0.001));
      assert(closeEnough(satellite.getDx(), 3099.886, 0.001));
      assert(closeEnough(satellite.getDy(), -32.313, 0.001));
      assert(10 == satellite.radius);
      assert(true == satellite.isAlive());
      // Teardown
   }
   
   //Test hit with no wreckage
   void test_hitNoWreckage()
   {
      // Setup
      Position pos;
      pos.setMetersX(4);
      pos.setMetersY(3);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      std::list<SimulatorObject *> list;
      
      
      // Exercise
      obj.hit(list);
      
      // Verify
      assert(0 == list.size());
      assert(4 == obj.position.getMetersX());
      assert(3 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(false == obj.isAlive());
      // Teardown
   }
   
   
   // Test creating a collision body
   void test_getCollisionBody()
   {
      // Setup
      SimulatorObject satellite;
      satellite.setX(0);
      satellite.setY(42164000);
      satellite.setDx(3100);
      satellite.setDy(0);
      satellite.radius = 5;
      
      // Exercise
      CollisionBody body = satellite.getCollisionBody();
      
      // Verify
      assert(0 == body.getX());
      assert(42164000 == body.getY());
      assert(3100 == body.getDx());
      assert(0 == body.getDy());
      assert(5 == body.getRadius());
      
      // Teardown
   }
   
   // Test getting the radius
   void test_getRadius()
   {
      // Setup
      Position pos;
      pos.setMetersX(4);
      pos.setMetersY(3);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      // Exercise
      int radiusReturned = obj.getRadius();
      
      // Verify
      assert(5 == radiusReturned);
      
      assert(4 == obj.position.getMetersX());
      assert(3 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test setting the radius
   void test_setRadius()
   {
      // Setup
      Position pos;
      pos.setMetersX(4);
      pos.setMetersY(3);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      // Exercise
      obj.setRadius(10);
      
      // Verify
      assert(4 == obj.position.getMetersX());
      assert(3 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(10 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test getting the position
   void test_getPosition()
   {
      // Setup
      Position pos;
      pos.setMetersX(4);
      pos.setMetersY(3);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      // Exercise
      Position posReturned = obj.getPosition();
      
      // Verify
      assert(4 == posReturned.getMetersX());
      assert(3 == posReturned.getMetersY());
      
      assert(4 == obj.position.getMetersX());
      assert(3 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test setting the positon
   void test_setPosition()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      Position pos2;
      pos2.setMetersX(100);
      pos2.setMetersY(200);
      
      // Exercise
      obj.setPosition(pos2);
      
      // Verify
      assert(pos2.getMetersX() == obj.position.getMetersX());
      assert(pos2.getMetersY() == obj.position.getMetersY());
      
      assert(100 == obj.position.getMetersX());
      assert(200 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test getting X.
   void test_getX()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      double x = obj.getX();
      
      // Verify
      assert(3 == x);
      
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test setting x
   void test_setX()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      obj.setX(22);
      
      // Verify
      assert(22 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test getting y
   void test_getY()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      double y = obj.getY();
      
      // Verify
      assert(4 == y);
      
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test setting y
   void test_setY()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      obj.setY(22);
      
      // Verify
      assert(3 == obj.position.getMetersX());
      assert(22 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test getting velocity
   void test_getVelocity()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      Velocity returnedVelocity = obj.getVelocity();
      
      // Verify
      assert(5 == returnedVelocity.getX());
      assert(5 == returnedVelocity.getY());
      
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test set velccity
   void test_setVelocity()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      Velocity vel2;
      vel2.setX(55);
      vel2.setY(100);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      obj.setVelocity(vel2);
      
      // Verify
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(55 == obj.velocity.getX());
      assert(100 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test getting dx
   void test_getDx()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      double dx = obj.getDx();
      
      // Verify
      assert(5 == dx);
      
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test setting dx
   void test_setDx()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      obj.setDx(10);
      
      // Verify
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(10 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test getting dy
   void test_getDy()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      double dy = obj.getDy();
      
      // Verify
      assert(dy == obj.velocity.getY());
      
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test setting dy
   void test_setDy()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      obj.setDy(10);
      
      // Verify
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(10 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test checking if alive
   void test_isAlive()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      bool isAlive = obj.isAlive();
      
      // Verify
      assert(true == isAlive);
      
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // Test setting alive
   void test_setAlive()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      obj.setAlive(false);
      
      // Verify
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(false == obj.isAlive());
      // Teardown
   }
   
   // Test getting height
   void test_getHeight()
   {
      // Setup
      Position pos;
      pos.setMetersX(3);
      pos.setMetersY(4);
      
      Velocity vel;
      vel.setX(5);
      vel.setY(5);
      
      SimulatorObject obj;
      obj.position = pos;
      obj.velocity = vel;
      obj.radius = 5;
      obj.alive = true;
      
      
      // Exercise
      double height = obj.getHeight();
      
      // Verify
      assert(5 == height);
      
      assert(3 == obj.position.getMetersX());
      assert(4 == obj.position.getMetersY());
      assert(5 == obj.velocity.getX());
      assert(5 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }
};

