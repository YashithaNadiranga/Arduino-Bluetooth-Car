# define leftMfront 6
# define leftMback 9
# define rightMfront 10
# define rightMback 11
# define frontL 2
# define backL 4
# define horn 7
int mSpeed = 255;
char data;

void setup() {
  pinMode(leftMfront, OUTPUT);
  pinMode(leftMback, OUTPUT);
  pinMode(rightMfront, OUTPUT);
  pinMode(rightMback, OUTPUT);
  pinMode(frontL, OUTPUT);
  pinMode(backL, OUTPUT);
  pinMode(horn, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    data = Serial.read();
    Serial.println(data);

    if (data == 'F') {
      goFront();
    }
    else if (data == 'B') {
      goBack();
    }
    else if (data == 'R') {
      goRight();
    }
    else if (data == 'L') {
      goLeft();
    }
    else if (data == 'G') {
      forwardLeft();
    }
    else if (data == 'I') {
      forwardRight();
    }
    else if (data == 'H') {
      backLeft();
    }
    else if (data == 'j') {
      backRight();
    }
    else if (data == 'S') {
      Stop();
    }
    else if (data == '1') {
      mSpeed = 100;
    }
    else if (data == '2') {
      mSpeed = 110;
    }
    else if (data == '3') {
      mSpeed = 130;
    }
    else if (data == '4') {
      mSpeed = 150;
    }
    else if (data == '5') {
      mSpeed = 170;
    }
    else if (data == '6') {
      mSpeed = 190;
    }
    else if (data == '7') {
      mSpeed = 210;
    }
    else if (data == '8') {
      mSpeed = 220;
    }
    else if (data == '9') {
      mSpeed == 230;
    }
    else if (data == 'q') {
      mSpeed == 250;
    }
    else if (data == 'W') {
      analogWrite(2, HIGH);
    }
    else if (data == 'w') {
      analogWrite(2, LOW);
    }
    else if (data == 'V') {
      analogWrite(4, HIGH);
    }
    else if (data == 'v') {
      analogWrite(4, LOW);
    }
    else if (data == 'X') {
      analogWrite(7, HIGH);
    }
    else if (data == 'x') {
      analogWrite(7, LOW);
    }
  }
}


void goFront() {
  analogWrite(leftMfront, mSpeed);
  analogWrite(leftMback, 0);
  analogWrite(rightMfront, mSpeed);
  analogWrite(rightMback, 0);
}


void goBack() {
  analogWrite(leftMfront, 0);
  analogWrite(leftMback, mSpeed);
  analogWrite(rightMfront, 0);
  analogWrite(rightMback, mSpeed);
}


void goRight() {
  analogWrite(leftMfront, mSpeed);
  analogWrite(leftMback, 0);
  analogWrite(rightMfront, 0);
  analogWrite(rightMback, 0);
}


void goLeft() {
  analogWrite(leftMfront, 0);
  analogWrite(leftMback, 0);
  analogWrite(rightMfront, mSpeed);
  analogWrite(rightMback, 0);
}


void forwardLeft(){
  analogWrite(leftMfront,mSpeed * 1/3);
  analogWrite(leftMback, 0);
  analogWrite(rightMfront, mSpeed);
  analogWrite(rightMback, 0);
}


void forwardRight(){
  analogWrite(leftMfront, mSpeed);
  analogWrite(leftMback, 0);
  analogWrite(rightMfront, mSpeed * 1 / 3);
  analogWrite(rightMback, 0);
}


void backLeft(){
  analogWrite(leftMfront, 0);
  analogWrite(leftMback, mSpeed * 1 / 3);
  analogWrite(rightMfront, 0);
  analogWrite(rightMback, mSpeed);
}


void backRight(){
  analogWrite(leftMfront, 0);
  analogWrite(leftMback, mSpeed);
  analogWrite(rightMfront, 0);
  analogWrite(rightMback, mSpeed * 1 / 3);
}

void Stop() {
  analogWrite(leftMfront, 0);
  analogWrite(leftMback, 0);
  analogWrite(rightMfront, 0);
  analogWrite(rightMback, 0);
}