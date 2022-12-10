//
//  simulatorObject.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//
#define _USE_MATH_DEFINES
#pragma once
#include "position.h"
#include "velocity.h"
#include "collisionBody.h"
#include <vector>
#include <list>
#include "simulatorObject.h"
#include "angle.h"
#include "math.h"


/******************************************************************************
 * SIMULATOROBJECT
 * This class sets up all of the objects in the simulation for the game.
 ******************************************************************************/
class SimulatorObject
{
protected:
   Position position;
   Velocity velocity;
   Angle rotationAngle;
   int radius;
   bool alive;
   double rotationAmount = 0.01;
   
   void setAlive(bool isAlive) { alive = isAlive; }
   void setRotation(const Angle & rotation) { this->rotationAngle = rotation; }
   void setDy(double dy) { velocity.setY(dy); }
   void setDx(double dx) { velocity.setX(dx); }
   void setVelocity(const Velocity & velocity) { this->velocity = velocity; }
   void setY(double y) { position.setMetersY(y); }
   void setX(double x) { position.setMetersX(x); }
   
   void setRadius(int radius) { this->radius = radius; }
   void setPosition(Position position) { this->position = position; }
   
   

   
public:
   SimulatorObject(): position(Position()),
                      velocity(Velocity()),
                      radius(0),
                      alive(true)
   {

      
   }
   SimulatorObject(Position position, Velocity velocity, int radius): position(position), velocity(velocity),
radius(radius), alive(true) {}
   
   SimulatorObject(const SimulatorObject & rhs)
   {
      this->position = rhs.position;
      this->velocity = rhs.velocity;
      this->radius = rhs.radius;
      this->alive = rhs.alive;
   }
   
   SimulatorObject & operator = (const SimulatorObject & rhs)
   {
      this->position = rhs.position;
      this->velocity = rhs.velocity;
      this->radius = rhs.radius;
      this->alive = rhs.alive;
      return *this;
   }

   
   virtual void advance(const SimulatorObject & gravitySource);
   virtual void draw();
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
   virtual void rotate();
   virtual CollisionBody getCollisionBody();
   virtual CollisionBody getCollisionBody2();
   
   int getRadius() const { return radius; }
   Position getPosition() { return position; }
   double getX() const { return position.getMetersX(); }
   double getY() const {return position.getMetersY(); }
   Velocity& getVelocity()  { return velocity; }
   double getDx() const { return velocity.getX(); }
   double getDy() const { return velocity.getY(); }
   Angle getRotation() const { return rotationAngle; }
   bool isAlive() const { return alive; }
   double getHeight() const { return sqrt((getX() * getX()) + (getY() * getY())); }
   
   void kill() { alive = false; }

   friend class TestSimulatorObject;
};
