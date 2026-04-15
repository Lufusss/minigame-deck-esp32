#include "ball.hpp"

// Constructor
Ball::Ball(int startX, int startY, int velocityX, int velocityY){
    x = startX;
    y = startY;
}

// ball position calculation
void update(){
    
}

// ball x-Value getter
int Ball::getX() const{
    return x;
}

// ball y-Value getter
int Ball::getY() const{
    return y;
}