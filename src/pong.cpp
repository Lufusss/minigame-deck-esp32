#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "conf.hpp"
#include "pong.hpp"
#include "paddle.hpp"
#include "controller.hpp"
#include "ball.hpp"
#include "display.hpp"


#define _LOGGING_ON
#ifdef _LOGGING_ON
#define LOG_INFO(TAG, VALUE) Serial.print("INFO: "); Serial.print(TAG); Serial.println(VALUE);
#define LOG_DEBUG(TAG, VALUE) Serial.print("DEBUG: "); Serial.print(TAG); Serial.println(VALUE);
#define LOG_WARN(TAG, VALUE) Serial.print("WARN: "); Serial.print(TAG); Serial.println(VALUE);
#define LOG_WARN(TAG, VALUE) Serial.print("WARN: "); Serial.print(TAG); Serial.println(VALUE);
#else
#define LOG_INFO(TAG, VALUE)
#define LOG_DEBUG(TAG, VALUE)
#define LOG_WARN(TAG, VALUE)
#define LOG_WARN(TAG, VALUE)
#endif

Pong::Pong()
    : scoreLeft(0),
    scoreRight(0),
    leftController(LEFT_POTI),
    rightController(RIGHT_POTI),
    leftPaddle(WALL_DISTANCE, 0, PADDLE_SIZE),
    rightPaddle(RIGHT_BORDER- WALL_DISTANCE, 0, PADDLE_SIZE),
    mainBall(),
    oledScreen(),
    currentState(MENU)
{}
void Pong::begin() { 
    oledScreen.begin();
}

void Pong::update() {
    switch (currentState) {
        case MENU:
        LOG_DEBUG("State", currentState);
            if(!digitalRead(MIDDLE)) {
                currentState = IN_GAME;
            }
        break;

        case IN_GAME:
        LOG_DEBUG("State", currentState);
            leftPaddle.update(leftController.getValue());
            rightPaddle.update(rightController.getValue());
            mainBall.update(true, true);
            mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
            mainBall.bounceX(leftPaddle.getX(), leftPaddle.getUpperY(), leftPaddle.getLowerY());
            mainBall.bounceX(rightPaddle.getX(), rightPaddle.getUpperY(), rightPaddle.getLowerY());   
        break;

        case THROW_IN:
        LOG_DEBUG("State", currentState);
            mainBall.update(0, 1);
            mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
            if (!digitalRead(MIDDLE)) {
                currentState = IN_GAME;
            }
        break;

        case LEFT_WINS:
        LOG_DEBUG("State", currentState);
        break;

        case RIGHT_WINS:
        LOG_DEBUG("State", currentState);
        break;
    }
}

void Pong::drawScreen() {
    oledScreen.clear();
    oledScreen.drawPixel(mainBall.getX(), mainBall.getY());
    oledScreen.drawPaddle(leftPaddle.getX(), leftPaddle.getUpperY(), leftPaddle.getLowerY());
    oledScreen.drawPaddle(rightPaddle.getX(), rightPaddle.getUpperY(), rightPaddle.getLowerY());
    //oledScreen.drawScore(scoreLeft, scoreRight);
    oledScreen.update();
}

/*void Pong::checkScore() {
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
    */
void Pong::throwIn() {
    mainBall.resetToCenter();
    mainBall.update(0,1);
    mainBall.bounceY(UPPER_BORDER, LOWER_BORDER);
}

void Pong::addToScore() {
    scoreLeft += mainBall.checkScoreLeft();
    scoreRight += mainBall.checkScoreRight();
}
