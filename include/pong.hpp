#include "controller.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "display.hpp"
#include "player.hpp"



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

        Player leftPlayer;
        Player rightPlayer;

        enum pongStates{
            MENU,
            IN_GAME,
            THROW_IN,
            LEFT_WINS,
            RIGHT_WINS,
        };

        pongStates currentState;

    public:
        Pong();
        void begin();
        void update();
        void drawScreen();
        void checkScore();
        int getScoreLeft() const;
        int getScoreRight() const;
        void throwIn();
};