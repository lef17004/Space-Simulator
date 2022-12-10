/***********************************************************************
 * Source File:
 *   Satellite: Base for the man-made objects that orbit earth
 *   Also contains all the Specific Satellite Classes:
 *       -Sputnik
 *       -GPS
 *       -Hubble
 *       -Starlink
 *       -Dragon
 *       -DreamChaser
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    The Satellite object and all the child classes- all the man-made
 *    ones specifically
 ************************************************************************/

#include "satellite.h"



/******************************************************************************
 * Advance for Satellite.
 * Randomly makes a satellite defunct. Can be thrown off of orbit more than once.
 ******************************************************************************/
void Satellite::advance(const SimulatorObject & gravitySource)
{
   SimulatorObject::advance(gravitySource);
   if (random(1, 9000) == 50)
   {
      rotationAmount = 0.15;
      velocity.setX(velocity.getX() + 50);
      velocity.setY(velocity.getY() + 50);
   }
}

/******************************************************************************
 * SPUTNIK:: HIT
 * Kills  and adds to corrosponding fragments and parts on the screen.
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
 * * GPS:: HIT
 * Kills  and adds to corrosponding fragments and parts on the screen.
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
 * HUBBLE:: HIT
 * Kills and adds to corrosponding fragments and parts on the screen.
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
 * STARLINK:: HIT
 * Kills and adds to corrosponding fragments and parts on the screen.
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
 * DRAGON:: HIT
 * Kills and adds the corrospoding fragments and parts on the screen,
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
 * DREAMCHASER:: APPLYINPUT
 * Controls the ship based on user input.
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
 * DREAMCHASER::ADVANCE
 * Moves the dream chaser foward one frame in the simualtion.
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
 * DREAM CHASER::HIT
 * Destroys the ship and adds the corresponding pices and pragments on the screen. 
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