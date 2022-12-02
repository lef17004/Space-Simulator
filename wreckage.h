//
//  Wreckage.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "simulatorObject.h"
#include "satellite.h"
#include "uiDraw.h"

class Wreckage: public SimulatorObject
{
public:
   Wreckage() {}
   Wreckage (const Position & position, const Velocity & velocity)
   {
      double randomAngle = random(1, 360);
      Angle angle;
      angle.setDegrees(randomAngle);
      double totalVelocity = velocity.getTotal();
      
      this->velocity = velocity;
      this->velocity.setX(0);
      this->velocity.setY(0);
      this->velocity.add(totalVelocity + random(5000, 9000), angle);
      
      int pixelsX = 4 * sin(angle.getRadians());
      int pixelsY = 4 * cos(angle.getRadians());
      
      this->position = position;
      this->position.setMetersX(this->position.getMetersX() + pixelsX);
      this->position.setMetersY(this->position.getMetersY() + pixelsY);
      
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
