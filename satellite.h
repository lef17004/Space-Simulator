//
//  Satellite.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "simulatorObject.h"
#include "uiDraw.h"
#include "input.h"
#include "projectile.h"
#include "wreckage.h"

/******************************************************************************
 * SATELLITE
 * This class is the base class for the rest of the satellites.
 ******************************************************************************/
class Satellite: public SimulatorObject
{
   void advance(const SimulatorObject & gravitySource);
};

/******************************************************************************
 * SPUTNIK
 * This class draws and accurately positions the Sputnik satellite so it can
 * be displayed accurately in its orbit.
 ******************************************************************************/
class Sputnik: public Satellite
{
public:
   Sputnik()
   {
      position = Position(-36515095.13, 21082000.0);
      velocity = Velocity(2050.0, 2684.68);
      radius = 4;
   }
   
   virtual void draw()
   {
      drawSputnik(position, rotationAngle.getRadians());
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
};

/******************************************************************************
 * GPS
 * This class draws and accurately positions the base of the GPS Satellites so 
 * they can be displayed accurately in their orbit.
 ******************************************************************************/
class GPS : public Satellite
{
public:
   GPS(const Position & givenPosition, const Velocity & givenVelocity, const Angle & angle)
   {
      position = givenPosition;
      velocity = givenVelocity;
      radius = 12;
      rotationAngle.setRadians(angle.getRadians());
      rotationAmount = -0.007;
   }

   virtual void draw()
   {
      drawGPS(position, rotationAngle.getRadians());
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
};

/******************************************************************************
 * HUBBLE
 * This class draws and accurately positions the Hubble Telescope so it can be
 * accurately displayed in orbit.
 ******************************************************************************/
class Hubble : public Satellite
{
public:
   Hubble()
   {
      position = Position(0, -42164000.0);
      velocity = Velocity(3100.0, 0.0);
      radius = 10;
   }

   virtual void draw()
   {
      drawHubble(position, rotationAngle.getRadians());
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
};

/******************************************************************************
 * STARLINK
 * This class draws and accurately positions the Starlink Satellite so it can be
 * accurately displayed in orbit.
 ******************************************************************************/
class StarLink: public Satellite
{
public:
   StarLink()
   {
      position = Position(0.0, -13020000.0);
      velocity = Velocity(5800.0, 0.0);
      radius = 6;
   }
   
   virtual void draw()
   {
      drawStarlink(position, rotationAngle.getRadians());
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
   
};

/******************************************************************************
 * DRAGON
 * This class draws and accurately positions the Dragon Satellite so it can be
 * accurately displayed in orbit.
 ******************************************************************************/
class Dragon: public Satellite
{
public:
   Dragon()
   {
      position = Position(0.0, 8000000.0);
      velocity = Velocity(-7900.0 , 0.0);
      radius = 7;
   }
   
   virtual void draw()
   {
      drawCrewDragon(position, rotationAngle.getRadians());
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
};

/******************************************************************************
 * DREAMCHASER
 * This class draws the DreamChaser and holds the mechanics for movement
 * and deploying projectiles.
 ******************************************************************************/
class DreamChaser: public Satellite
{
private:
   bool applyThrust;
   
public:
   DreamChaser()
   {
      position.setPixelsX(-450);
      position.setPixelsY(450);
      velocity = Velocity(0, -2000);
      radius = 10;
      applyThrust = false;
      rotationAmount = 0;
   }
   
   void applyInput(const Input & input);
   void advance(const SimulatorObject & gravitySource);
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection);
   
   void draw()
   {
      drawShip(position, rotationAngle.getRadians(), applyThrust);
   }
   
   Projectile * shoot()
   {
      return new Projectile(position, velocity, rotationAngle);
   }
   
   
};
