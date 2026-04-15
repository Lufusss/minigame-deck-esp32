#ifndef BALL_HPP
#define BALL_HPP

class Ball {

private:
    int x;
    int y;

public:
    Ball(int startX, int startY, int velocityX, int velocityY);
    void resetToCenter();

    void update();
    
    void bounceY();
    void bounceX();

    int getX() const;
    int getY() const;
};

#endif
