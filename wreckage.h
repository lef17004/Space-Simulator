//
//  Wreckage.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
#include "simulatorObject.h"
#include "satellite.h"


class Wreckage: public SimulatorObject
{
   
};




class Fragment: public Satellite
{
   friend class TestSatellite;
};
