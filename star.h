//
//  stars.h
//  Lab07
//
//  Created by Michael LeFevre on 11/30/22.
//

#pragma once
#include "position.h"
#include "uiDraw.h"

class Star
{
private:
   Position position;
   int phase;
   
public:
   Star()
   {
      position = Position(random(-62000000, 62000000), random(-62000000, 62000000));
      phase = random(0, 528);
   }
   
   void advance()
   {
      phase += 1;
   }
   
   void draw()
   {
      drawStar(position, phase);
   }
};
