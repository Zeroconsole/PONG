int screenWidth;
int screenHeight;
int paddleWidth;
int paddleHeight;
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
int player1Joystick;
int player2Joystick;

void drawPixel(int x, int y, int r, int g, int b) {
  //TODO
}

void drawRectangle(int x, int y, int width, int height, int r, int g, int b) {
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      drawPixel(i, j, r, g, b);
    }
  }
}

void drawCircle(int x, int y, int diameter) {
  //TODO
}

void clearDisplay() {
  drawRectangle(0, 0, screenWidth, screenHeight, backgroundR, backgroundG, backgroundB);
}

paintScore() {
  //TODO
}

paintPaddle1() {
  drawRectangle(paddle1X, paddle1Y, paddleWidth, paddleHeight, forgroundR, forgroundG, forgroundB);
}

paintPaddle2() {
  drawRectangle(paddle2X, paddle2Y, paddleWidth, paddleHeight, forgroundR, forgroundG, forgroundB);
}

paintBall() {
  //TODO
}

void paint() {
  clearDisplay();
  paintScore();
  paintPaddle1();
  paintPaddle2();
  paintBall();
}

void calculate() {
  //TODO
}

void getInput() {
  //TODO
}

int main() {
  //TODO initializations of variables
  while(true) {
    getInput();
    calculate();
    paint();
  }
  return 0;
}
