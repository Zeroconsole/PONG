#include <unistd.h>
#include <math.h>
#include "graphics.h"
#include <linux/fb.h>
struct fb_var_screeninfo info;

int numbers[10][5] = {
                {0b111, 0b101, 0b101, 0b101, 0b111},//0
                {0b010, 0b010, 0b010, 0b010, 0b010},//1
                {0b111, 0b001, 0b111, 0b100, 0b111},//2
                {0b111, 0b001, 0b011, 0b001, 0b111},//3
                {0b101, 0b101, 0b111, 0b001, 0b001},//4
                {0b111, 0b100, 0b111, 0b001, 0b111},//5
                {0b111, 0b100, 0b111, 0b101, 0b111},//6
                {0b111, 0b101, 0b101, 0b101, 0b101},//7
                {0b111, 0b101, 0b111, 0b101, 0b111},//8
                {0b111, 0b101, 0b111, 0b001, 0b111}//9
                };
int player1Score;
int player2Score;
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
int foregroundColor;
int paddleSpeed = 1;
int ballSpeed = 2;
double ballDirectionX = 1;
double ballDirectionY = 0;
double PI = 3.14159265358979323846264338327950288419716939937510;
int player1Joystick;
int player2Joystick;

void drawPixel(int x, int y, int color) {
    //int color = (0 * 256 * 256 * 256) + (r * 256 * 256); + (g * 256) + b;
    gfx_setColor(color); // ARGB
    gfx_setPixel(x, y);
}

void drawBackgroundRectangle(int x, int y, int width, int height, int color) {
    int i;
    int j;
    gfx_setColor(color);
    for(i = 0; i < width; i++) {
        for(j = 0; j < height; j++) {
            if(((i > paddle1X) && (i < paddle1X + paddleWidth)
              && (j > paddle1Y) && (j < paddle1Y + paddleHeight))
              || ((i > paddle2X) && (i < paddle2X + paddleWidth)
              && (j > paddle2Y) && (j < paddle2Y + paddleHeight))
              || (
              (i > ballX - ballRadius) && (i < ballX + ballRadius)
              && (j > ballY - ballRadius) && (j < ballY + ballRadius)
              )
              ) {
                //do nothing
            }
            else {
                gfx_setPixel(x + i, y + j);
            }
        }
    }
}

void drawRectangle(int x, int y, int width, int height, int color) {
    int i;
    int j;
    gfx_setColor(color);
    for(i = 0; i < width; i++) {
        for(j = 0; j < height; j++) {
            gfx_setPixel(x + i, y + j);
        }
    }
}

void drawCircle(int x, int y, int diameter, int color) {
    double i;
    int j;
    for(i = 0; i < PI; i += (PI / 180)) {
        double sinOfi = sin(i);
        double cosOfi = cos(i);
        for(j = 0; j < (diameter / 2); j++) {
            drawPixel(x + (j * cosOfi), y + (j * sinOfi), color);
            drawPixel(x + (-1 * j * cosOfi), y + (-1 * j * sinOfi), color);
        }
    }
}

void clearDisplay() {
    drawBackgroundRectangle(0, 0, screenWidth, screenHeight, backgroundColor);
}

void paintScore() {
    //TODO figure out how to render numbers with boxes
    int number[5] = {
        numbers[player1Score][0],
        numbers[player1Score][1],
        numbers[player1Score][2],
        numbers[player1Score][3],
        numbers[player1Score][4]
        };
    int xOffset = 100;
    int yOffset = 100;
    int pixelSize = 25;
    int i;
    int j;
    for(i = 1; i <= 5; i++) {
      yOffset += i * pixelSize;
        //for(j = 1; j <= 3; j++) {
            //if(number[(i * j) - 1] == 1) {
                drawRectangle(xOffset + ((i - 1) * pixelSize), yOffset + ((j - 1) * pixelSize), pixelSize, pixelSize, foregroundColor);
            //}
            if(number[i] == 0b000) {
              //do nothing
            }
            else if(number[i] == 0b001) {
                drawRectangle(xOffset + (2 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
            }
            else if(number[i] == 0b010) {
                drawRectangle(xOffset + (1 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
            }
            else if(number[i] == 0b011) {
                drawRectangle(xOffset + (1 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
                drawRectangle(xOffset + (2 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
            }
            else if(number[i] == 0b100) {
                drawRectangle(xOffset + (0 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
            }
            else if(number[i] == 0b101) {
                drawRectangle(xOffset + (0 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
                drawRectangle(xOffset + (2 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
            }
            else if(number[i] == 0b110) {
                drawRectangle(xOffset + (0 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
                drawRectangle(xOffset + (1 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
            }
            else if(number[i] == 0b111) {
                drawRectangle(xOffset + (0 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
                drawRectangle(xOffset + (1 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
                drawRectangle(xOffset + (2 * pixelSize), yOffset + (0 * pixelSize), pixelSize, pixelSize, foregroundColor);
            }
        //}
    }
}

void paintPaddle1() {
    drawRectangle(paddle1X, paddle1Y, paddleWidth, paddleHeight, foregroundColor);
}

void paintPaddle2() {
    drawRectangle(paddle2X, paddle2Y, paddleWidth, paddleHeight, foregroundColor);
}

void paintBall() {
    drawCircle(ballX, ballY, ballRadius, foregroundColor);
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
    int ballCenterY = ballY;
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
    if(ballX > screenWidth) {
        player1Score++;
    }
    else if(ballX < 0) {
        player2Score++;
    }
}

void getInput() {
    //TODO interface with keyboard
    //pseudo code below
    //player1Joystick = (keyboardInput = "W") ? 1 : ((keyboardInput = "S") ? -1 : 0);
    //player2Joystick = (keyboardInput = "UP") ? 1 : ((keyboardInput = "DOWN") ? -1 : 0);
}

int main() {
    //gfx_getScreenInfo(info);
    //screenWidth = info.xres;// how in c?
    //screenHeight = info.yres;// how in c?
    player1Score = 0;
    player2Score = 0;
    screenWidth = 1920 / 3;
    screenHeight = 1080 / 3;
    paddleWidth = screenWidth / (16 * 4);//adjust later
    paddleHeight = (4 * screenHeight) / (9 * 4);//adjust later
    ballRadius = screenWidth / (16 * 4);//adjust later
    ballX = screenWidth / 2;//adjust later
    ballY = screenHeight / 2;//adjust later
    paddle1X = screenWidth / (16 * 4);//adjust later
    paddle1Y = (screenHeight / 2) - (paddleWidth / 2);//adjust later
    paddle2X = screenWidth - ((2 * screenWidth) / (16 * 4));//adjust later
    paddle2Y = (screenHeight / 2) - (paddleWidth / 2);//adjust later
    backgroundColor = 0x00FF0000;//maybe adjust later
    foregroundColor = 0x00FFFFFF;//maybe adjust later
    player1Joystick = 0;
    player2Joystick = 0;
    gfx_start("/dev/fb0");
//    drawCircle(screenWidth / 2, 300, 100, 0x00FF0000);
/*
    while(1 == 1) {
        drawRectangle(0, 0, screenWidth, screenHeight, 0x00FFFFFF);
    }
*/
//    gfx_setColor(0x00FFFFFF);
//    gfx_setPixel(100, 100);
    //TODO finish variable initializations

    while(1 == 1) {
        getInput();
        calculate();
        paint();
        //TODO add short pause of some sort
        sleep(0.3);
    }

    return 0;
}

