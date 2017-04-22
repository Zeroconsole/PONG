int screenWidth;
int screenHeight;
int paddleWidth;
int paddleHeight;
int ballRadius;
int ballX;
int ballY;
int ballR;
int ballG;
int ballB;
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
/**
I'm thinking
-1 down
0 is not moving
1 right
**/
int player1Joystick;
int player2Joystick;

void drawPixel(int x, int y, int r, int g, int b) {
    //TODO call Hanavan's code somehow
}

void drawRectangle(int x, int y, int width, int height, int r, int g, int b) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            drawPixel(i, j, r, g, b);
        }
    }
}

void drawCircle(int x, int y, int diameter, int r, int g, int b) {
    //TODO haven't done yet cuz math
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
    drawCircle(ballX, ballY, ballRadius, ballR, ballG, ballB);
}

void paint() {
    clearDisplay();
    paintScore();
    paintPaddle1();
    paintPaddle2();
    paintBall();
}

void calculate() {
    //TODO all calculations go here
}

void getInput() {
    //TODO interface with keyboard
    //pseudo code below
    //player1Joystick = (keyboardInput = "W") ? 1 : ((keyboardInput = "S") ? -1 : 0);
    //player2Joystick = (keyboardInput = "UP") ? 1 : ((keyboardInput = "DOWN") ? -1 : 0);
}

int main() {
    //TODO initializations of variables
    screenWidth = 0;// how in c?
    screenHeight = 0;// how in c?
    paddleWidth = screenWidth / (16 * 4);//adjust later
    paddleHeight = (4 * screenHeight) / (9 * 4);//adjust later
    ballRadius = screenWidth / (16 * 4);//adjust later
    ballX = screenWidth / 2;//adjust later
    ballY = screenHeight / 2;//adjust later
    ballR = 255;
    ballG = 255;
    ballB = 255;
    paddle1X = screenWidth / (16 * 4);//adjust later
    paddle1Y = (screenHeight / 2) - (paddleWidth / 2);//adjust later
    paddle2X = screenWidth - ((2 * screenWidth) / (16 * 4));//adjust later
    paddle2Y = (screenHeight / 2) - (paddleWidth / 2);//adjust later
    backgroundR = 0;
    backgroundG = 0;
    backgroundB = 0;
    forgroundR = 0;
    forgroundG = 0;
    forgroundB = 0;
    player1Joystick = 0;
    player2Joystick = 0;
    //TODO finish variable initializations
    while(true) {
        getInput();
        calculate();
        paint();
        //TODO add short pause of some sort
    }
    return 0;
}
