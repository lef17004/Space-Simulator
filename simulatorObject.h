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
#include "wreckage.h"

class SimulatorObject
{
private:
   Position position;
   Velocity velocity;
   int radius;
   bool isAlive;
   
public:
   SimulatorObject() {}
   
};
