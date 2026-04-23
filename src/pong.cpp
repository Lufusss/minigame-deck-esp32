#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "controller.hpp"
#include "ball.hpp"
#include "display.hpp"


Pong::Pong()
    : scoreLeft(0),
    scoreRight(0),
    leftController(LEFT_POTI),
    rightController(RIGHT_POTI),
    leftPaddle(WALL_DISTANCE, 0, PADDLE_SIZE),
    rightPaddle(RIGHT_BORDER- WALL_DISTANCE, 0, PADDLE_SIZE),
    mainBall(0,0,1,1),
    oledScreen()
{}
void Pong::begin() { 
    oledScreen.begin();
}

void Pong::update() {
    leftPaddle.update(leftController.getValue());
    rightPaddle.update(rightController.getValue());
    mainBall.update();
    mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
    mainBall.bounceX(leftPaddle.getX(), leftPaddle.getUpperY(), leftPaddle.getLowerY());
    mainBall.bounceX(rightPaddle.getX(), rightPaddle.getUpperY(), rightPaddle.getLowerY());   
}

void Pong::drawScreen() {
    oledScreen.clear();
    oledScreen.drawPixel(mainBall.getX(), mainBall.getY());
    oledScreen.drawPaddle(leftPaddle.getX(), leftPaddle.getUpperY(), leftPaddle.getLowerY());
    oledScreen.drawPaddle(rightPaddle.getX(), rightPaddle.getUpperY(), rightPaddle.getLowerY());
    //oledScreen.drawScore(scoreLeft, scoreRight);
    oledScreen.update();
}

void Pong::checkScore() {
    int ballX = mainBall.getX();
    static int leftPlayerPoints = 0;
    static int rightPlayerPoints = 0;
    if (ballX <= LEFT_BORDER) {
        rightPlayerPoints +=1;
    }
    if (ballX >= RIGHT_BORDER) {
        leftPlayerPoints += 1;
    }
}