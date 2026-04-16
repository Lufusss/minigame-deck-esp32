#include "ball.hpp"
#include "conf.hpp"

// Constructor
Ball::Ball(int startX, int startY, int velocityX, int velocityY){
    x = startX;
    y = startY;
    veloX = velocityX;
    veloY = velocityY;
}

void Ball::resetToCenter(){
    y = SCREEN_HEIGHT / 2;
    x = SCREEN_WIDTH / 2;
}

void Ball::update(){
    y += veloY;
    x += veloX;
}

void Ball::bounceX(){
    
}

void Ball::bounceY(){
    if (y <= 0){
        veloY = veloY * -1;
    }
    if (y >= SCREEN_HEIGHT -1) {
        veloY = veloY *-1;
    }
}

int Ball::getX() const{
    return x;
}

// ball y-Value getter
int Ball::getY() const{
    return y;
}

