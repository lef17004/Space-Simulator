//
//  Wreckage.cpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#include "wreckage.h"

/******************************************************************************
 *
 ******************************************************************************/
Wreckage::Wreckage(const Position& position, const Velocity& velocity)
{
   double randomAngle = random(1, 360);
   Angle angle;
   angle.setDegrees(randomAngle);
   
   this->velocity = velocity;
   this->velocity.add(random(1000, 4000), angle);
   
   
   int pixelsX = 20.0 * sin(angle.getRadians());
   int pixelsY = 20.0 * cos(angle.getRadians());
   
   this->position = position;
   this->position.setPixelsX(this->position.getPixelsX() + pixelsX);
   this->position.setPixelsY(this->position.getPixelsY() + pixelsY);
   alive = true;
}

/******************************************************************************
 *
 ******************************************************************************/
void Fragment::advance(const SimulatorObject& gravitySource)
{
   SimulatorObject::advance(gravitySource);
   life.advance();
   
   if (!life.isAlive())
      kill();
}


/******************************************************************************
 *
 ******************************************************************************/
void GPSCenter::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void GPSLeft::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}


/******************************************************************************
 *
 ******************************************************************************/
void GPSRight::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void HubbleTelescope::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void HubbleComputer::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void HubbleLeft::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void HubbleRight::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void StarlinkBody::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void StarlinkArray::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void DragonCenter::hit(std::list<SimulatorObject*>& simulatorCollection)
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
void DragonLeft::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 *
 ******************************************************************************/
void DragonRight::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}
