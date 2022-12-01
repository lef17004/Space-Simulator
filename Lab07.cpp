/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#define _USE_MATH_DEFINES

#include <math.h>
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "velocity.h"
#include "acceleration.h"
#include "constants.h"
#include "test.h"
#include "simulatorObject.h"
#include "satellite.h"
#include "earth.h"
#include "simulator.h"
#include "input.h"
using namespace std;



class SatelliteO
{
private:
   Velocity velocity;
   Position position;
   double rotation;
   double angle;

public:
   
   SatelliteO()
   {
      position = Position(21082000, 36515095);
      velocity = Velocity(-2685.0, 1550.0);
   }
   
   void advance()
   {
      double angle = atan2(0 - position.getMetersX(), 0 - position.getMetersY());
      double heightAboveEarth = position.getTotalMeters() - EARTH_RADIUS;
      double innerEquation = EARTH_RADIUS / (EARTH_RADIUS + heightAboveEarth);
      double gravity = GRAVITY_SEA_LEVEL * innerEquation * innerEquation;

      Acceleration accel(gravity, angle, position);
      velocity.add(accel);
      position.add(velocity, accel);
   }
   
   Position getPosition()
   {
      return position;
   }
};


/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {

     sim = SimulatorObject(Position(21082000, 36515095), Velocity(-2685.0, 1550.0), 5);
      angleEarth = 0.0;
   }

   Position ptUpperRight;
   SatelliteO sat;
   //SimulatorObject sim(Position(), Velocity(), 5);
   SimulatorObject sim;
   Sputnik spud;
   
   Earth earth;
   double angleEarth;
   
   Simulator simulator;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;
   Input input;
   input.setUpPressed(pUI->isUp());
   input.setDownPressed(pUI->isDown());
   input.setLeftPressed(pUI->isLeft());
   input.setRightPressed(pUI->isRight());
   input.setSpacePressed(pUI->isSpace());
   
   pDemo->simulator.simulateFrame(input);
   
   // rotate the earth
//   double rotationSpeed = -(2.0 * M_PI / 30.0 ) * (1440 / 86400.0);
//   pDemo->spud.advance(SimulatorObject());
//   pDemo->sat.advance();
//
//   pDemo->sim.advance(pDemo->earth);
//   pDemo->sim.draw();
//   pDemo->spud.draw();
//
//
// //
//   pDemo->earth.advance(pDemo->earth);
//   pDemo->earth.draw();
   
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   testRunner();
   // Initialize the demo
   Demo demo(ptUpperRight);
   
   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
