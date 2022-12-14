/***********************************************************************
 * Header File:
 *    Simulator: Runs the simulation
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class sets up the simulator in the game.
 ************************************************************************/

#pragma once
#include "earth.h"
#include "satellite.h"
#include "simulatorObject.h"
#include <list>
#include <array>
#include "star.h"
#include "input.h"



/******************************************************************************
 * SIMULATOR
 * This class sets up the simulator in the game.
 ******************************************************************************/
class Simulator
{
private:
   Earth earth;
   std::list<SimulatorObject *> simulatorObjects;
   std::array<Star, 1750> starArray;
   DreamChaser ship;
   
   void advance();
   void draw();
   void handleInput(const Input & input);
   void handleCollisions();
   
public:
   Simulator();
   void simulateFrame(const Input & input);
};