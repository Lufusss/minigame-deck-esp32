#ifndef PADDLE_HPP
#define PADDLE_HPP

class Paddle {

private:
    int wallDistance;
    int size;
    int y;

public:
    Paddle(int startX, int startY, int size);
    void update();
    int getY() const;
};

#endif