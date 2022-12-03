//
//  Simulator.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "earth.h"
#include "satellite.h"
#include "simulatorObject.h"
#include <list>
#include <array>
#include "star.h"
#include "input.h"

class Simulator
{
private:
   Earth earth;
   std::list<SimulatorObject *> simulatorObjects;
   std::array<Star, 1750> starArray;
   DreamChaser ship;
   
   void advance()
   {
      for (auto star: starArray)
         star.advance();
      
      
      for (auto object : simulatorObjects)
         object->advance(earth);
   }
   
   void draw()
   {
      for (auto star: starArray)
         star.draw();
      
      for (auto object : simulatorObjects)
         object->draw();
   }
   
   void handleInput(const Input & input)
   {
      ship.applyInput(input);
      if (input.isSpacePressed())
      {
         simulatorObjects.push_back(ship.shoot());
      }
   }
   
   void handleCollisions()
   {
      
      for (auto it = simulatorObjects.begin(); it != simulatorObjects.end(); it++)
      {
         auto it2 = it;
         for (it2++; it2 != simulatorObjects.end(); it2++)
         {
            if (CollisionBody::isCollision2((*it)->getCollisionBody2(), (*it2)->getCollisionBody2()) &&
                (*it)->isAlive() && (*it2)->isAlive())
            {
               (*it)->hit(simulatorObjects);
               (*it2)->hit(simulatorObjects);
            }
         }
      }
      
      for (auto it = simulatorObjects.rbegin(); it != simulatorObjects.rend(); it++)
      {
         if (!(*it)->isAlive())
         {
            simulatorObjects.remove(*it);
         }
      }
   }
   
public:
   Simulator()
   {
      simulatorObjects.push_back(new Sputnik());
      simulatorObjects.push_back(new Hubble());
      simulatorObjects.push_back(new StarLink());
      simulatorObjects.push_back(new Dragon());
      simulatorObjects.push_back(new GPS(Position(0.0,           26560000.0),  Velocity(-3880.0,      0.0)));
      simulatorObjects.push_back(new GPS(Position(23001634.72,   13280000.0),  Velocity(-1940.0,  3360.18)));
      simulatorObjects.push_back(new GPS(Position(23001634.72,  -13280000.0),  Velocity(1940.0,   3360.18)));
      simulatorObjects.push_back(new GPS(Position(0.0,           -26560000.0),  Velocity(3880.0,       0.0)));
      simulatorObjects.push_back(new GPS(Position(-23001634.72, -13280000.0),  Velocity(1940.0,  -3360.18)));
      simulatorObjects.push_back(new GPS(Position(-23001634.72,  13280000.0),  Velocity(-1940.0, -3360.18)));
      
      
      
      simulatorObjects.push_back(&earth);
      simulatorObjects.push_back(&ship);
   }
   
   void simulateFrame(const Input & input)
   {
      handleInput(input);
      advance();
      handleCollisions();
      draw();
   }
   
   
};
