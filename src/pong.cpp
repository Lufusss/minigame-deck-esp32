#include <Arduino.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "input_conf.hpp"
#include "ball.hpp"


Controller L(LEFT_POTI);
Controller R(RIGHT_POTI);
Paddle LeftPlayer(WALL_DISTANCE, LEFT_POTI, PADDLE_SIZE);
Paddle RightPlayer(SCREEN_HEIGHT - WALL_DISTANCE, RIGHT_POTI, PADDLE_SIZE);
Ball mainBall(0, 0, 1, 1);


void pongUpdate() {
    mainBall.resetToCenter();
    LeftPlayer.update(L.getMappedValue());
    RightPlayer.update(R.getMappedValue());
    mainBall.update();

}