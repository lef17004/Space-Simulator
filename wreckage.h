//
//  Wreckage.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "simulatorObject.h"
#include "satellite.h"

class Wreckage: public SimulatorObject
{
public:
   Wreckage() {}
   Wreckage (const Position & position, const Velocity & velocity)
   {
      
   }
};

class HubbleComputer : public Wreckage
{
public:
   HubbleComputer(const Position & position, const Velocity & velocity)
   {
      Wreckage(position, velocity);
      radius = 7;
   }
   void draw()
   {
      drawHubbleComputer(position, rotationAngle.getRadians());
   }
   
};

class HubbleLeft : public Satellite
{
public:
   HubbleLeft()
   {
      radius = 8;
   }
};

class HubbleRight : public Satellite
{
public:
   HubbleRight()
   {
      radius = 8;
   }
};






class Fragment: public Satellite
{
   friend class TestSatellite;
};
