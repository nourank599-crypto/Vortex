#define SENSOR1 11
#define SENSOR2 12
#define BLACK 0
#define WHITE 1

#define IN1 4
#define IN2 5
#define ENA A0

#define IN4 6
#define IN3 7
#define ENB A1
#define CAR_SPEED 255

void forward() {
  // motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, CAR_SPEED);
  
  // motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, CAR_SPEED);
}

void backward() {
  // motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, CAR_SPEED);
  
  // motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, CAR_SPEED);
}

void right() {
  // motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, CAR_SPEED);
  
  // motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, LOW);
}

void left() {
  // motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, LOW);
  
  // motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, CAR_SPEED);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, LOW);
  
  // motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, LOW);
}

void setup() {
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if ((digitalRead(SENSOR1) == BLACK) && (digitalRead(SENSOR2) == BLACK)) {
    forward();
  }
  else if ((digitalRead(SENSOR1) == WHITE) && (digitalRead(SENSOR2) == WHITE)) {
    forward();
  }
  else if ((digitalRead(SENSOR1) == BLACK) && (digitalRead(SENSOR2) == WHITE)) {
    right();
  }
  else if ((digitalRead(SENSOR1) == WHITE) && (digitalRead(SENSOR2) == BLACK)) {
    left();
  }
}
