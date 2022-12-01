//
//  Wreckage.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "simulatorObject.h"
#include "satellite.h"

class HubbleComputer : public Satellite
{
public:
   HubbleComputer()
   {
      radius = 7;
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

class Wreckage: public SimulatorObject
{
   
};




class Fragment: public Satellite
{
   friend class TestSatellite;
};
