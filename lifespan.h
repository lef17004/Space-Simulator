/***********************************************************************
 * Header File:
 *    Lifespan: Life of all objects
 * Author:
 *    Michael LeFevre on 11/8/22.
 * Summary:
 *    Every object in the game has a life, this is where that is controlled
 ************************************************************************/

#pragma once



/******************************************************************************
 * LIFESPAN
 * This class rules the lifespans of all objects in the simulation.
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