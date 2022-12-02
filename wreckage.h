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

class GPSCenter : public Wreckage
{
public:
   GPSCenter(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 7;
   }
   void draw()
   {
      drawGPSCenter(position, rotationAngle.getRadians());
   }

};

class GPSLeft : public Wreckage
{
public:
   GPSLeft(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawGPSLeft(position, rotationAngle.getRadians());
   }

};

class GPSRight : public Wreckage
{
public:
   GPSRight(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawGPSRight(position, rotationAngle.getRadians());
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

class HubbleLeft : public Wreckage
{
public:
   HubbleLeft(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawHubbleLeft(position, rotationAngle.getRadians());
   }
};

class HubbleRight : public Wreckage
{
public:
   HubbleRight(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawHubbleRight(position, rotationAngle.getRadians());
   }
};

class StarlinkBody : public Wreckage
{
public:
   StarlinkBody(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 2;
   }
   void draw()
   {
      drawStarlinkBody(position, rotationAngle.getRadians());
   }

};

class StarlinkArray : public Wreckage
{
public:
   StarlinkArray(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 4;
   }
   void draw()
   {
      drawStarlinkArray(position, rotationAngle.getRadians());
   }

};

class DragonCenter : public Wreckage
{
public:
   DragonCenter(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 6;
   }
   void draw()
   {
      drawCrewDragonCenter(position, rotationAngle.getRadians());
   }

};

class DragonLeft : public Wreckage
{
public:
   DragonLeft(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 6;
   }
   void draw()
   {
      drawCrewDragonLeft(position, rotationAngle.getRadians());
   }

};

class DragonRight : public Wreckage
{
public:
   DragonRight(const Position& position, const Velocity& velocity)
   {
      Wreckage(position, velocity);
      radius = 6;
   }
   void draw()
   {
      drawCrewDragonRight(position, rotationAngle.getRadians());
   }

};

class Fragment: public Satellite
{
   friend class TestSatellite;
};
