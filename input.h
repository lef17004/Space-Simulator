//
//  input.h
//  Lab07
//
//  Created by Michael LeFevre on 11/30/22.
//

#pragma once
class Input
{
private:
   bool upPressed;
   bool downPressed;
   bool leftPressed;
   bool rightPressed;
   bool spacePressed;
   
public:
   Input(): upPressed(false), downPressed(false), leftPressed(false), rightPressed(false), spacePressed(false) {}
   
   void pressUp()    { upPressed = true; }
   void pressDown()  { downPressed = true; }
   void pressLeft()  { leftPressed = true; }
   void pressRight() { rightPressed = true; }
   void pressSpace() { spacePressed = true; }
   
   void setUpPressed(bool isPressed) { upPressed = isPressed; }
   void setDownPressed(bool isPressed) { downPressed = isPressed; }
   void setLeftPressed(bool isPressed) { leftPressed = isPressed; }
   void setRightPressed(bool isPressed) { rightPressed = isPressed; }
   void setSpacePressed(bool isPressed) { spacePressed = isPressed; }
   
   bool isUpPressed()    const { return upPressed; }
   bool isDownPressed()  const { return downPressed; }
   bool isLeftPressed()  const { return leftPressed; }
   bool isRightPressed() const { return rightPressed; }
   bool isSpacePressed() const { return spacePressed; }
   
};
