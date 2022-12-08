//
//  Wreckage.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "simulatorObject.h"
#include "uiDraw.h"
#include "lifespan.h"

/******************************************************************************
 *
 ******************************************************************************/
class Wreckage : public SimulatorObject
{   
public:
   Wreckage() {}
   Wreckage(const Position& position, const Velocity& velocity);
};

/******************************************************************************
 *
 ******************************************************************************/
class Fragment : public Wreckage
{
private:
   LifeSpan life;
public:
   Fragment(const Position& position, const Velocity& velocity) : Wreckage(position, velocity)
   {
      radius = 2;
      life.setLife(random(50, 100));
      rotationAmount = 0.25;
   }
   void draw()
   {
      drawFragment(position, rotationAngle.getRadians());
   }
   void advance(const SimulatorObject& gravitySource)
   {
      SimulatorObject::advance(gravitySource);
      life.advance();

      if (!life.isAlive())
         kill();
   }
};


class GPSCenter : public Wreckage
{
public:
   GPSCenter(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 7;
   }
   void draw()
   {
      drawGPSCenter(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class GPSLeft : public Wreckage
{
public:
   GPSLeft(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawGPSLeft(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }

};

class GPSRight : public Wreckage
{
public:
   GPSRight(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawGPSRight(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class HubbleTelescope : public Wreckage
{
public:
   HubbleTelescope(const Position& position, const Velocity& velocity) : Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 10;
   }
   void draw()
   {
      drawHubbleTelescope(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class HubbleComputer : public Wreckage
{
public:
   HubbleComputer(const Position & position, const Velocity & velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 7;
   }
   void draw()
   {
      drawHubbleComputer(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class HubbleLeft : public Wreckage
{
public:
   HubbleLeft(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawHubbleLeft(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class HubbleRight : public Wreckage
{
public:
   HubbleRight(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 8;
   }
   void draw()
   {
      drawHubbleRight(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class StarlinkBody : public Wreckage
{
public:
   StarlinkBody(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 2;
   }
   void draw()
   {
      drawStarlinkBody(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class StarlinkArray : public Wreckage
{
public:
   StarlinkArray(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 4;
   }
   void draw()
   {
      drawStarlinkArray(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class DragonCenter : public Wreckage
{
public:
   DragonCenter(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 6;
   }
   void draw()
   {
      drawCrewDragonCenter(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class DragonLeft : public Wreckage
{
public:
   DragonLeft(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 6;
   }
   void draw()
   {
      drawCrewDragonLeft(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class DragonRight : public Wreckage
{
public:
   DragonRight(const Position& position, const Velocity& velocity): Wreckage(position, velocity)
   {
      Wreckage(position, velocity);
      radius = 6;
   }
   void draw()
   {
      drawCrewDragonRight(position, rotationAngle.getRadians());
   }
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};


