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

      Acceleration accel(gravity, angle, false);
      velocity.add(accel);
      position.add(velocity, accel);
   }
   
   Position getPosition()
   {
      return position;
   }
};

class SatelliteTest
{
private:
   double x;
   double y;
   double dx;
   double dy;
   
public:
   SatelliteTest()
   {
     
      x = 0.0;
      y = 8000000.0;
      dx = -7900.0;
      dy = 0.0;
   }
   
   SatelliteTest(double x, double y, double dx, double dy): x(x), y(y), dx(dx), dy(dy)
   {
   
   }
   
   void advance()
   {
      double time = 48.0;
      double earthRadius = 6378000.0;
      double gravityAtSeaLevel = -9.80665;
      
      double angle = atan2(0 - x, 0 - y);
      double heightAboveEarth = sqrt(x * x + y * y) - earthRadius;
      
      double gravityAccel = gravityAtSeaLevel * (earthRadius / (earthRadius + heightAboveEarth )) * (earthRadius / (earthRadius + heightAboveEarth ));
      
      double ddx = -gravityAccel * sin(angle);
      double ddy = -gravityAccel * cos(angle);
      
      
      double newDx = dx + ddx * time;
      double newDy = dy + ddy * time;
      
      double newX = x + newDx * time + 0.5 * ddx * time * time;
      double newY = y + newDy * time + 0.5 * ddy * time * time;
      
      newX = x + newDx * time;
      newY = y + newDy * time;
      
      dx = newDx;
      dy = newDy;
      x = newX;
      y = newY;
      
   }
   
   void draw()
   {
      //drawHubble(Position(x, y), 0);
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
   SatelliteTest test;
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
