/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testSimulatorObject.h"
#include "testCollisionBody.h"
#include "testSatellite.h"

/*****************************************************************
 * TESTRUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
//   TestPosition().run();
  // TestSimulatorObject().run();
   TestCollisionBody().run();
//   TestSatellite().run();
}
