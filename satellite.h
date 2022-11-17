//
//  Satellite.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "simulatorObject.h"
#include "uiDraw.h"

class Satellite: public SimulatorObject
{
   
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
};
