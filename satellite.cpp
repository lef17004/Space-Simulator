//
//  satellites.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "satellite.h"

/******************************************************************************
 *
 ******************************************************************************/
void Satellite::advance(const SimulatorObject & gravitySource)
{
   SimulatorObject::advance(gravitySource);
   if (random(1, 3000) == 50)
   {
      rotationAmount = 0.15;
      velocity.setX(velocity.getX() + 50);
      velocity.setY(velocity.getY() + 50);
   }
}

/******************************************************************************
 *
 ******************************************************************************/
void Sputnik::hit(std::list<SimulatorObject*> & simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void GPS::hit(std::list<SimulatorObject*> & simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new GPSCenter(position, velocity));
   simulatorCollection.push_back(new GPSLeft(position, velocity));
   simulatorCollection.push_back(new GPSRight(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}


/******************************************************************************
 *
 ******************************************************************************/
void Hubble::hit(std::list<SimulatorObject*> & simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new HubbleTelescope(position, velocity));
   simulatorCollection.push_back(new HubbleLeft(position, velocity));
   simulatorCollection.push_back(new HubbleRight(position, velocity));
   simulatorCollection.push_back(new HubbleComputer(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void StarLink::hit(std::list<SimulatorObject*> & simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new StarlinkBody(position, velocity));
   simulatorCollection.push_back(new StarlinkArray(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void Dragon::hit(std::list<SimulatorObject*> & simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new DragonLeft(position, velocity));
   simulatorCollection.push_back(new DragonRight(position, velocity));
   simulatorCollection.push_back(new DragonLeft(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void DreamChaser::applyInput(const Input & input)
{
   if (input.isLeftPressed())
      rotationAngle.add(-0.1);
   if (input.isRightPressed())
      rotationAngle.add(0.1);
   applyThrust = input.isDownPressed();
   
}

/******************************************************************************
 *
 ******************************************************************************/
void DreamChaser::advance(const SimulatorObject & gravitySource)
{
   if (applyThrust)
   {
      Acceleration thrust(30.0, rotationAngle);
      velocity.add(thrust, 3.5);
   }
   SimulatorObject::advance(gravitySource);
}

/******************************************************************************
 *
 ******************************************************************************/
void DreamChaser::hit(std::list<SimulatorObject*> & simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}
