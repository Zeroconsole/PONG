#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "graphics.h"
int screenWidth;
int screenHeight;
int paddleWidth;
int paddleHeight;
int ballRadius;
int ballX;
int ballY;
int paddle1X;
int paddle1Y;
int paddle2X;
int paddle2Y;
int backgroundColor;
int forgroundColor;
int paddleSpeed = 1;
int ballSpeed = 2;
double ballDirectionX = 1;
double ballDirectionY = 1;
double PI = 3.14159265358979323846264338327950288419716939937510;
int player1Joystick;
int player2Joystick;

void drawPixel(int x, int y, int color) {
    //int color = (0 * 256 * 256 * 256) + (r * 256 * 256); + (g * 256) + b;
    gfx_setColor(color); // ARGB
    gfx_setPixel(x, y);
}

void drawRectangle(int x, int y, int width, int height, int color) {
    int i;
    for(i = 0; i < x; i++) {
        int j;
        for(j = 0; j < y; j++) {
            drawPixel(i, j, color);
        }
    }
}

void drawCircle(int x, int y, int diameter, int color) {
    double i;
    for(i = 0; i < PI; i += (PI / 8)) {
        double sinOfi = sin(i);
        double cosOfi = cos(i);
        int j;
        for(j = 0; j < (diameter / 2); j++) {
            drawPixel(j * cosOfi, j * sinOfi, color);
            drawPixel(-1 * j * cosOfi, -1 * j * sinOfi, color);
        }
    }
}

void clearDisplay() {
    drawRectangle(0, 0, screenWidth, screenHeight, backgroundColor);
}

void paintScore() {
    //TODO figure out how to render numbers with boxes
}

void paintPaddle1() {
    drawRectangle(paddle1X, paddle1Y, paddleWidth, paddleHeight, forgroundColor);
}

void paintPaddle2() {
    drawRectangle(paddle2X, paddle2Y, paddleWidth, paddleHeight, forgroundColor);
}

void paintBall() {
    drawCircle(ballX, ballY, ballRadius, forgroundColor);
}

void paint() {
    clearDisplay();
    paintScore();
    paintPaddle1();
    paintPaddle2();
    paintBall();
}

void calculate() {
    if(player1Joystick == -1) {
        paddle1Y += paddleSpeed;
    }
    else if(player1Joystick == 1) {
        paddle1Y -= paddleSpeed;
    }
    if(player2Joystick == -1) {
        paddle2Y += paddleSpeed;
    }
    else if(player2Joystick == 1) {
        paddle2Y -= paddleSpeed;
    }
    ballX += ballDirectionX;
    ballX -= ballDirectionY;
    int ballCenterY = ballY + ballRadius;
    if((ballX < paddle1X) && (ballCenterY > paddle1Y) && (ballCenterY < (paddle1Y + paddleHeight))) {
        if(ballCenterY < (paddle1Y + (paddleHeight / 3))) {
            //If we want to make the ball act differently
            //based on where it hits the paddle we can do that here
        }
        else if(ballCenterY < (paddle1Y + ((2 * paddleHeight) / 3))) {
            //If we want to make the ball act differently
            //based on where it hits the paddle we can do that here
        }
        else if(ballCenterY < (paddle1Y + ((3 * paddleHeight) / 3))) {
            //If we want to make the ball act differently
            //based on where it hits the paddle we can do that here
        }
        ballDirectionX *= -1;
        ballDirectionY *= -1;
    }
    else if((ballX > paddle2X) && (ballCenterY > paddle2Y) && (ballCenterY < (paddle2Y + paddleHeight))) {
        if(ballCenterY < (paddle1Y + (paddleHeight / 3))) {
            //If we want to make the ball act differently
            //based on where it hits the paddle we can do that here
        }
        else if(ballCenterY < (paddle1Y + ((2 * paddleHeight) / 3))) {
            //If we want to make the ball act differently
            //based on where it hits the paddle we can do that here
        }
        else if(ballCenterY < (paddle1Y + ((3 * paddleHeight) / 3))) {
            //If we want to make the ball act differently
            //based on where it hits the paddle we can do that here
        }
        ballDirectionX *= -1;
        ballDirectionY *= -1;
    }
}

void getInput() {
    //TODO interface with keyboard
    //pseudo code below
    //player1Joystick = (keyboardInput = "W") ? 1 : ((keyboardInput = "S") ? -1 : 0);
    //player2Joystick = (keyboardInput = "UP") ? 1 : ((keyboardInput = "DOWN") ? -1 : 0);
}

void function(int color) {
    drawRectangle(0, 0, 100, 100, color);
    sleep(1);
}

int main() {
    screenWidth = 1280;// how in c?
    screenHeight = 720;// how in c?
    paddleWidth = screenWidth / (16 * 4);//adjust later
    paddleHeight = (4 * screenHeight) / (9 * 4);//adjust later
    ballRadius = screenWidth / (16 * 4);//adjust later
    ballX = screenWidth / 2;//adjust later
    ballY = screenHeight / 2;//adjust later
    paddle1X = screenWidth / (16 * 4);//adjust later
    paddle1Y = (screenHeight / 2) - (paddleWidth / 2);//adjust later
    paddle2X = screenWidth - ((2 * screenWidth) / (16 * 4));//adjust later
    paddle2Y = (screenHeight / 2) - (paddleWidth / 2);//adjust later
    backgroundColor = 0x000000FF;//maybe adjust later
    forgroundColor = 0x00FF0000;//maybe adjust later
    player1Joystick = 0;
    player2Joystick = 0;
    gfx_start("/dev/fb0");
    //TODO finish variable initializations
    function(0xFFFFFFFF);
    function(0x00FFFFFF);
    function(0xFF00FFFF);
    function(0xFFFF00FF);
    function(0xFFFFFF00);
    function(0x00000000);
    function(0xFF000000);
    function(0x00FF0000);
    function(0x0000FF00);
    function(0x000000FF);
    /*
    while(1 == 1) {
        getInput();
        calculate();
        paint();
        //TODO add short pause of some sort
    }
    */
    return 0;
}
