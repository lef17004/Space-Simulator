/***********************************************************************
 * Header File:
 *    Wreckage: Space waste
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class is a collection of space junk created from broken
 *    Satellites, and earth if it is destroyed. Made up of Both
 *    Fragments and Parts
 ************************************************************************/

#pragma once
#include "simulatorObject.h"
#include "uiDraw.h"
#include "lifespan.h"



/******************************************************************************
 * WRECKAGE
 * This class is the base for all of the wreckage that happens when an 
 * object collides with another in the game.
 ******************************************************************************/
class Wreckage : public SimulatorObject
{   
public:
   Wreckage() {}
   Wreckage(const Position& position, const Velocity& velocity);
};

/******************************************************************************
 * FRAGMENT
 * This class holds the code for the fragments that emit from the parts when 
 * they are hit by another object.
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
   void advance(const SimulatorObject& gravitySource);
};

/******************************************************************************
 * GPSCENTER
 * This holds the center of the GPS satellites for when they break off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * GPSLEFT
 * This holds the left side of the GPS satellites for when they break off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);

};

/******************************************************************************
 * GPSRIGHT
 * This holds the right side of the GPS satellites for when they break off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * HUBBLETELESCOPE
 * This is the code for the Hubble Telescope for when the Hubble Satellite
 * breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * HUBBLECOMPUTER
 * This is the code for the Hubble Computer for when the Hubble Satellite
 * breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * HUBBLELEFT
 * This is the code for the Hubble's left side for when the Hubble Satellite
 * breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);};

/******************************************************************************
 * HUBBLERIGHT
 * This is the code for the Hubble's right side for when the Hubble Satellite
 * breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * STARLINKBODY
 * This is the code for the body of the Starlink for when the Starlink Satellite
 * breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * STARLINKARRAY
 * This is the code for the array of the Starlink for when the Starlink Satellite
 * breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * DRAGONCENTER
 * This holds the center of the Dragon satellite for when it breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * DRAGONLEFT
 * This holds the left side of the Dragon satellite for when it breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};

/******************************************************************************
 * DRAGONRIGHT
 * This holds the right side of the Dragon satellite for when it breaks off into parts.
 ******************************************************************************/
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
   virtual void hit(std::list<SimulatorObject*>& simulatorCollection);
};