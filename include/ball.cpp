#include "ball.hpp"

// Constructor
Ball::Ball(int startX, int startY, int velocityX, int velocityY){
    x = startX;
    y = startY;
}

void Ball::resetToCenter(){
    // ball reset (after scoring)
}

void Ball::update(){
    // ball position calculation
}

void Ball::bounceX(){
    // flipping direction horizontally
}

void Ball::bounceY(){
    //flipping direction vertically
}

int Ball::getX() const{
    return x;
}

// ball y-Value getter
int Ball::getY() const{
    return y;
}

