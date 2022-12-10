/***********************************************************************
 * Source File:
 *    Simulator: Runs the simulation
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class sets up the simulator in the game.
 ************************************************************************/

#include "simulator.h"

/******************************************************************************
 * SIMULATOR
 * Puts all of the objects in the simulator.
 ******************************************************************************/
Simulator::Simulator()
{
   simulatorObjects.push_back(new Sputnik());
   simulatorObjects.push_back(new Hubble());
   simulatorObjects.push_back(new StarLink());
   simulatorObjects.push_back(new Dragon());
   
   
   simulatorObjects.push_back(new GPS(Position(0.0,           26560000.0),  Velocity(-3880.0,      0.0), Angle(PI / 2)));
   simulatorObjects.push_back(new GPS(Position(23001634.72,   13280000.0),  Velocity(-1940.0,  3360.18), Angle(3*PI/4)));
   simulatorObjects.push_back(new GPS(Position(23001634.72,  -13280000.0),  Velocity(1940.0,   3360.18), Angle(-3 * PI / 4)));
   simulatorObjects.push_back(new GPS(Position(0.0,           -26560000.0),  Velocity(3880.0,       0.0), Angle(PI / 2)));
   simulatorObjects.push_back(new GPS(Position(-23001634.72, -13280000.0),  Velocity(1940.0,  -3360.18), Angle(3 * PI / 4)));
   simulatorObjects.push_back(new GPS(Position(-23001634.72,  13280000.0),  Velocity(-1940.0, -3360.18), Angle(-3 * PI / 4)));
   
   
   
   simulatorObjects.push_back(&earth);
   simulatorObjects.push_back(&ship);
}

/******************************************************************************
 * SIMULATEFRAME
 * This simulates the frame of the simulator.
 ******************************************************************************/
void Simulator::simulateFrame(const Input & input)
{
   handleInput(input);
   advance();
   handleCollisions();
   draw();
}

/******************************************************************************
 * ADVANCE
 * Advances the simulation for the Earth and Star objects.
 ******************************************************************************/
void Simulator::advance()
{
   for (auto star: starArray)
      star.advance();
   
   
   for (auto object : simulatorObjects)
      object->advance(earth);
}

/******************************************************************************
 * DRAW
 * Draws the Star objects.
 ******************************************************************************/
void Simulator::draw()
{
   for (auto star: starArray)
      star.draw();
   
   for (auto object : simulatorObjects)
      object->draw();
}


/******************************************************************************
 * HANDLEINPUT
 * Handles input from the client for the simulation.
 ******************************************************************************/
void Simulator::handleInput(const Input & input)
{
   ship.applyInput(input);
   if (input.isSpacePressed())
   {
      simulatorObjects.push_back(ship.shoot());
   }
}


/******************************************************************************
 * HANDLECOLLISIONS
 * This handles the collisions for the simulation.
 ******************************************************************************/
void Simulator::handleCollisions()
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

