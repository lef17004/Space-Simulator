//
//  simulatorObject.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "position.h"
#include "velocity.h"
#include "collisionBody.h"
#include <vector>
#include "simulatorObject.h"
#include "angle.h"
#include "math.h"

class SimulatorObject
{
protected:
   Position position;
   Velocity velocity;
   Angle rotationAngle;
   int radius;
   bool alive;
   
   
public:
   SimulatorObject(): position(Position()),
                      velocity(Velocity()),
                      radius(0),
   alive(true) {rotationAngle.setRadians(M_PI - 0.9);}
   SimulatorObject(Position position, Velocity velocity, int radius):
                      position(position),
                      velocity(velocity),
   radius(radius), alive(true) {rotationAngle.setRadians(M_PI - 0.9);}
   
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
   
   virtual void advance(SimulatorObject earth);
   virtual void draw();
   virtual std::vector<SimulatorObject> hit();
   virtual void rotate();
   virtual CollisionBody getCollisionBody();
   
   int getRadius() { return radius; }
   void setRadius(int radius) { this->radius = radius; }
   
   Position getPosition() { return position; }
   void setPosition(Position position) { this->position = position; }
   
   double getX() { return position.getMetersX(); }
   void setX(double x) { position.setMetersX(x); }
   double getY() {return position.getMetersY(); }
   void setY(double y) { position.setMetersY(y); }
   Velocity getVelocity() { return velocity; }
   void setVelocity(const Velocity & velocity) { this->velocity = velocity; }
   double getDx() { return velocity.getX(); }
   void setDx(double dx) { velocity.setX(dx); }
   double getDy() { return velocity.getY(); }
   void setDy(double dy) { velocity.setY(dy); }
   Angle getRotation() { return rotationAngle; }
   void setRotation(const Angle & rotation) { this->rotationAngle = rotation; }
   bool isAlive() { return alive; }
   void setAlive(bool isAlive) { alive = isAlive; }
   double getHeight() { return sqrt((getX() * getX()) + (getY() * getY())); }
   
   void kill() { alive = false; }

   friend class TestSimulatorObject;
   friend class TestSatellite;
};
