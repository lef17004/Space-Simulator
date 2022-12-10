/***********************************************************************
 * Source File:
 *    Wreckage: Space waste
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    This class is a collection of space junk created from broken
 *    Satellites, and earth if it is destroyed. Made up of Both
 *    Fragments and Parts
 ************************************************************************/

#include "wreckage.h"



/******************************************************************************
 * WRECKAGE
 * This class has the math for the wreckage.
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
 * FRAGMENT
 * This class has the behaviors of the fragments.
 ******************************************************************************/
void Fragment::advance(const SimulatorObject& gravitySource)
{
   SimulatorObject::advance(gravitySource);
   life.advance();
   
   if (!life.isAlive())
      kill();
}

/******************************************************************************
 * GPSCENTER
 * This class has the amount of fragments for when the GPSCenter part is hit.
 ******************************************************************************/
void GPSCenter::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * GPSLEFT
 * This class has the amount of fragments for when the GPSLeft part is hit.
 ******************************************************************************/
void GPSLeft::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * GPSRIGHT
 * This class has the amount of fragments for when the GPSRight part is hit.
 ******************************************************************************/
void GPSRight::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * HUBBLETELESCOPE
 * This class has the amount of fragments for when the Hubble Telescope part is hit.
 ******************************************************************************/
void HubbleTelescope::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * HUBBLECOMPUTER
 * This class has the amount of fragments for when the Hubble Computer part is hit.
 ******************************************************************************/
void HubbleComputer::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * HUBBLELEFT
 * This class has the amount of fragments for when the Hubble Left part is hit.
 ******************************************************************************/
void HubbleLeft::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * HUBBLERIGHT
 * This class has the amount of fragments for when the Hubble Right part is hit.
 ******************************************************************************/
void HubbleRight::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * STARLINKBODY
 * This class has the amount of fragments for when the Starlink Body part is hit.
 ******************************************************************************/
void StarlinkBody::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * STARLINKARRAY
 * This class has the amount of fragments for when the Starlink Array part is hit.
 ******************************************************************************/
void StarlinkArray::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * DRAGONCENTER
 * This class has the amount of fragements for when the Dragon Center part is hit.
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
 * DRAGONLEFT
 * This class has the amount of fragements for when the Dragon Left part is hit.
 ******************************************************************************/
void DragonLeft::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}

/******************************************************************************
 * DRAGONRIGHT
 * This class has the amount of fragements for when the Dragon Right part is hit.
 ******************************************************************************/
void DragonRight::hit(std::list<SimulatorObject*>& simulatorCollection)
{
   SimulatorObject::hit(simulatorCollection);
   simulatorCollection.push_back(new Fragment(position, velocity));
   simulatorCollection.push_back(new Fragment(position, velocity));
}