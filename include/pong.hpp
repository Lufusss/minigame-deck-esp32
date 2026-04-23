#include "controller.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "display.hpp"



class Pong {
    private:
        int scoreLeft;
        int scoreRight;
        Controller leftController;
        Controller rightController;

        Paddle leftPaddle;
        Paddle rightPaddle;

        Ball mainBall;
        myDisplay oledScreen;

    public:
        Pong();
        void begin();
        void update();
        void drawScreen();
        void checkScore();
        int getScoreLeft() const;
        int getScoreRight() const;
};