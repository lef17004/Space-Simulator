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



class SimulatorObject
{
private:
   Position position;
   Velocity velocity;
   int radius;
   bool alive;
   
public:
   SimulatorObject() {}
   virtual void advance(SimulatorObject earth);
   virtual void draw();
   virtual SimulatorObject hit();
   virtual void rotate();
   virtual CollisionBody getCollisionBody();
   
   int getRadius() { return 0; }
   void setRadius(int radius) {}
   
   Position getPosition() { return Position(); }
   void setPosition(Position position) {}
   
   double getX() { return 0; }
   void setX(double x) {};
   double getY() {return 0; }
   void setY(double y) {}
   Velocity getVelocity() { return velocity; }
   void setVelocity(Velocity velocity) { }
   double getDx() { return 0; }
   void setDx(double dx) {}
   double getDy() { return 0; }
   void setDy(double dy) {}
   double getRotation() { return 0; }
   void setRotation(double rotation) {}
   bool isAlive() { return false; }
   void setAlive(bool isAlive) {}
   double getHeight() { return 0; }
   
   void kill() {}
};
