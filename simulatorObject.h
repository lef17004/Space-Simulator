/***********************************************************************
 * Header File:
 *    Simuator Object: Base Class for All objects
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class holds all the necessary information that All objects 
 *    use
 ************************************************************************/

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
   
public:
   SimulatorObject(): position(Position()),
                      velocity(Velocity()),
                      radius(0),
                      alive(true) {}

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

   //Velocity & operator = (Velocity & rhs)
   
   virtual void advance(const SimulatorObject & gravitySource);
   virtual void draw();
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
   virtual void rotate();
   virtual CollisionBody getCollisionBody();
   virtual CollisionBody getCollisionBody2();
   
   int getRadius() const { return radius; }
   void setRadius(int radius) { this->radius = radius; }
   
   Position getPosition() { return position; }
   void setPosition(Position position) { this->position = position; }
   
   double getX() const { return position.getMetersX(); }
   void setX(double x) { position.setMetersX(x); }
   double getY() const {return position.getMetersY(); }
   void setY(double y) { position.setMetersY(y); }
   Velocity& getVelocity()  { return velocity; }
   void setVelocity(const Velocity & velocity) { this->velocity = velocity; }
   double getDx() const { return velocity.getX(); }
   void setDx(double dx) { velocity.setX(dx); }
   double getDy() const { return velocity.getY(); }
   void setDy(double dy) { velocity.setY(dy); }
   Angle getRotation() const { return rotationAngle; }
   void setRotation(const Angle & rotation) { this->rotationAngle = rotation; }
   bool isAlive() const { return alive; }
   void setAlive(bool isAlive) { alive = isAlive; }
   double getHeight() const { return sqrt((getX() * getX()) + (getY() * getY())); }
   
   void kill() { alive = false; }

   friend class TestSimulatorObject;
   friend class TestSatellite;
};