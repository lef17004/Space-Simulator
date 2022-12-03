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

class Satellite: public SimulatorObject
{
   void advance(const SimulatorObject & gravitySource)
   {
      SimulatorObject::advance(gravitySource);
      if (random(1, 1000) == 50)
      {
         rotationAmount = 0.5;
      }
   }
};

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
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

class GPS : public Satellite
{
public:
   GPS(Position givenPosition, Velocity givenVelocity)
   {
      position = givenPosition;
      velocity = givenVelocity;
      radius = 12;
   }

   virtual void draw()
   {
      drawGPS(position, rotationAngle.getRadians());
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new GPSCenter(position, velocity));
      simulatorCollection.push_back(new GPSLeft(position, velocity));
      simulatorCollection.push_back(new GPSRight(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

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
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new HubbleTelescope(position, velocity));
      simulatorCollection.push_back(new HubbleLeft(position, velocity));
      simulatorCollection.push_back(new HubbleRight(position, velocity));
      simulatorCollection.push_back(new HubbleComputer(position, velocity));
   }
};


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
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new StarlinkBody(position, velocity));
      simulatorCollection.push_back(new StarlinkArray(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
   
};

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
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new DragonLeft(position, velocity));
      simulatorCollection.push_back(new DragonRight(position, velocity));
      simulatorCollection.push_back(new DragonLeft(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};

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
   }
   
   void applyInput(const Input & input)
   {
      if (input.isLeftPressed())
         rotationAngle.add(-0.1);
      if (input.isRightPressed())
         rotationAngle.add(0.1);
      applyThrust = input.isDownPressed();
      
   }
   
   void advance(const SimulatorObject & gravitySource)
   {
      if (applyThrust)
      {
         Acceleration thrust(30.0, rotationAngle);
         velocity.add(thrust, 5);
      }
      SimulatorObject::advance(gravitySource);
   }
   
   void draw()
   {
      drawShip(position, rotationAngle.getRadians(), applyThrust);
   }
   
   void rotate()
   {
      
   }
   
   Projectile * shoot()
   {
      return new Projectile(position, velocity, rotationAngle);
   }
   
   virtual void hit(std::list<SimulatorObject*> & simulatorCollection)
   {
      SimulatorObject::hit(simulatorCollection);
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
      simulatorCollection.push_back(new Fragment(position, velocity));
   }
};
