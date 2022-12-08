//
//  lifespan.hpp
//  Lab07
//
//  Created by Michael LeFevre on 11/8/22.
//

#pragma once
/******************************************************************************
 *
 ******************************************************************************/
class LifeSpan
{
private:
   int life;
public:
   LifeSpan(): life(70) {};
   LifeSpan(int life): life(life) {}
   
   void advance() { life--; }
   bool isAlive() const { return life > 0; }
   void setLife(int life) { this->life = life; }
};
