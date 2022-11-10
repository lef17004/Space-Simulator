//
//  testSimulatorObject.h
//  Lab07
//
//  Created by Michael LeFevre on 11/9/22.
//

#pragma once

#include "simulatorObject.h"
#include "position.h"
#include "velocity.h"

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
      test_hitWreckage();
      test_rotate();
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
      test_setRotation();
      test_getRotation();
      test_isAlive();
      test_setAlive();
      test_getHeight();
      
   }
   
   void test_defaultConstructor()
   {
      
   }
   
   void test_nonDefaultConstructor()
   {
      
   }
   
   void test_advanceFrameOne()
   {
      // Setup
      SimulatorObject satellite;
      satellite.setX(0);
      satellite.setY(42164000);
      satellite.setDx(3100);
      satellite.setDy(0);

      SimulatorObject earth;
      earth.setX(0);
      earth.setY(0);

      // Exercise
      satellite.advance(earth);

      // Verify
      assert(148800 == satellite.getX());
      assert(closeEnough(satellite.getY(), 42163224.504, 0.001));
      assert(3100 == satellite.getDx());
      assert(closeEnough(satellite.getDy(), 10.771, 0.001));

      // Teardown
   }
   
   void test_advanceFrameTwo()
   {
      // Setup
      SimulatorObject satellite;
      satellite.setX(0);
      satellite.setY(42164000);
      satellite.setDx(3100);
      satellite.setDy(0);

      SimulatorObject earth;
      earth.setX(0);
      earth.setY(0);
      
      satellite.advance(earth);

      // Exercise
      satellite.advance(earth);

      // Verify
      assert(closeEnough(satellite.getX(), 297597.263, 0.001));
      assert(closeEnough(satellite.getY(), 42161931.9953, 0.001));
      assert(closeEnough(satellite.getDx(), 3099.962, 0.001));
      assert(closeEnough(satellite.getDy(), 21.542, 0.001));

      // Teardown
      
   }
   
   void test_advanceFrameThree()
   {
      // Setup
      SimulatorObject satellite;
      satellite.setX(0);
      satellite.setY(42164000);
      satellite.setDx(3100);
      satellite.setDy(0);

      SimulatorObject earth;
      earth.setX(0);
      earth.setY(0);

      satellite.advance(earth);
      satellite.advance(earth);

      // Exercise
      satellite.advance(earth);

      // Verify
      assert(closeEnough(satellite.getX(), 446389.964, 0.001));
      assert(closeEnough(satellite.getY(), -42160122.476, 0.001));
      assert(closeEnough(satellite.getDx(), 3099.886, 0.001));
      assert(closeEnough(satellite.getDy(), 32.313, 0.001));

      // Teardown
   }
   
   void test_hitNoWreckage()
   {
      
   }
   
   void test_hitWreckage()
   {
      
   }
   
   void test_rotate()
   {
      
   }
   
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
   
   void test_getRadius()
   {
      
   }
   
   void test_setRadius()
   {
      
   }
   
   void test_getPosition()
   {
      
   }
   
   void test_setPosition()
   {
      
   }
   
   void test_getX()
   {
     
      
     
   }
   
   void test_setX()
   {
      
   }
   
   void test_getY()
   {
      
   }
   
   void test_setY()
   {
      
   }
   
   void test_getVelocity()
   {
      
   }
   
   void test_setVelocity()
   {
      
   }
   
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
      assert(10 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
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
      assert(10 == obj.velocity.getY());
      assert(5 == obj.radius);
      assert(true == obj.isAlive());
      // Teardown
   }
   
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
   
   void test_getRotation()
   {
      
   }
   
   void test_setRotation()
   {
      
   }
   
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

