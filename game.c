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
int backgroundR;
int backgroundG;
int backgroundB;
int forgroundR;
int forgroundG;
int forgroundB;
int paddleSpeed = 1;
int ballSpeed = 2;
double ballDirectionX = 1;
double ballDirectionY = 1;
double PI = 3.14159265358979323846264338327950288419716939937510;
int player1Joystick;
int player2Joystick;

void drawPixel(int x, int y, int r, int g, int b) {
    int color = (r * 256 * 256 * 256) + (g * 256 * 256); + (b * 256) + 255;
    gfx_setColor(color); // ARGB for tv, RGBA for monitor
    gfx_setPixel(x, y);
}

void drawRectangle(int x, int y, int width, int height, int r, int g, int b) {
    int i;
    for(i = 0; i < x; i++) {
        int j;
        for(j = 0; j < y; j++) {
            drawPixel(i, j, r, g, b);
        }
    }
}

void drawCircle(int x, int y, int diameter, int r, int g, int b) {
    double i;
    for(i = 0; i < PI; i += (PI / 8)) {
        double sinOfi = sin(i);
        double cosOfi = cos(i);
        int j;
        for(j = 0; j < (diameter / 2); j++) {
            drawPixel(j * cosOfi, j * sinOfi, r, g, b);
            drawPixel(-1 * j * cosOfi, -1 * j * sinOfi, r, g, b);
        }
    }
}

void clearDisplay() {
    drawRectangle(0, 0, screenWidth, screenHeight, backgroundR, backgroundG, backgroundB);
}

void paintScore() {
    //TODO figure out how to render numbers with boxes
}

void paintPaddle1() {
    drawRectangle(paddle1X, paddle1Y, paddleWidth, paddleHeight, forgroundR, forgroundG, forgroundB);
}

void paintPaddle2() {
    drawRectangle(paddle2X, paddle2Y, paddleWidth, paddleHeight, forgroundR, forgroundG, forgroundB);
}

void paintBall() {
    drawCircle(ballX, ballY, ballRadius, forgroundR, forgroundG, forgroundB);
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
    backgroundR = 0;//maybe adjust later
    backgroundG = 0;//maybe adjust later
    backgroundB = 0;//maybe adjust later
    forgroundR = 0;//maybe adjust later
    forgroundG = 0;//maybe adjust later
    forgroundB = 0;//maybe adjust later
    player1Joystick = 0;
    player2Joystick = 0;
    gfx_start("/dev/fb0");
    //TODO finish variable initializations
    while(1 == 1) {
        getInput();
        calculate();
        paint();
        //TODO add short pause of some sort
    }
    return 0;
}
