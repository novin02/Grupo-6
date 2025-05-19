int PinoSensor1 = 2;  // PINO DIGITAL UTILIZADO PELO SENSOR
int PinoSensor2 = 3;  // PINO DIGITAL UTILIZADO PELO SENSOR
int PinoSensor3 = 4;  // PINO DIGITAL UTILIZADO PELO SENSOR
int PinoSensor4 = 7;  // PINO DIGITAL UTILIZADO PELO SENSOR
int PinoSensor5 = 8;  // PINO DIGITAL UTILIZADO PELO SENSOR

int Motor1F = 6;  // Motor 1 para frente
int Motor1T = 5;  // Motor 1 para trás
int Motor2F = 10; // Motor 2 para frente
int Motor2T = 9;  // Motor 2 para trás

void setup() {
  Serial.begin(9600);
  pinMode(PinoSensor1, INPUT);
  pinMode(PinoSensor2, INPUT);
  pinMode(PinoSensor3, INPUT);
  pinMode(PinoSensor4, INPUT);
  pinMode(PinoSensor5, INPUT);

  pinMode(Motor1F, OUTPUT);// esquerda
  pinMode(Motor1T, OUTPUT);
  pinMode(Motor2F, OUTPUT); //direita
  pinMode(Motor2T, OUTPUT);
}

void loop() {
  int Sensor1 = digitalRead(PinoSensor1);
  int Sensor2 = digitalRead(PinoSensor2);
  int Sensor3 = digitalRead(PinoSensor3);
  int Sensor4 = digitalRead(PinoSensor4);
  int Sensor5 = digitalRead(PinoSensor5);

  Serial.print("S1: "); Serial.print(Sensor1);
  Serial.print(" S2: "); Serial.print(Sensor2);
  Serial.print(" S3: "); Serial.print(Sensor3);
  Serial.print(" S4: "); Serial.print(Sensor4);
  Serial.print(" S5: "); Serial.println(Sensor5);

  if (Sensor3 == HIGH && ((Sensor5 == 0 or Sensor1 == 0) or (Sensor2 == 0 or Sensor4 == 0) )) { // Centro na linha
    moveForward(220);
  } else if (Sensor5 == HIGH && Sensor1 == LOW) { // Curva rápida à direita
    turn(220,0);
  } else if (Sensor1 == HIGH && Sensor5 == LOW) { // Curva rápida à esquerda
    turn(0,220);
  }  else if (Sensor4 == HIGH && Sensor2 == LOW) { // Curva suave à direita
    turn(230,40);
  } else if (Sensor2 == HIGH && Sensor4 == LOW) { // Curva suave à esquerda
    turn(40,230);
  } else {
    stopMotors(); 
  }
}

void moveForward(int speed) {
  analogWrite(Motor1F, speed);
  analogWrite(Motor1T, 0);
  analogWrite(Motor2F, speed);
  analogWrite(Motor2T, 0);
}

void turn(int speedL, int speedR) {
  analogWrite(Motor1F, speedL);
  analogWrite(Motor1T, 0);
  analogWrite(Motor2F, speedR);
  analogWrite(Motor2T, 0);
}

/*void turnLeft(int speedL, int speedR) {
  analogWrite(Motor1F, speedL);
  analogWrite(Motor1T, 0);
  analogWrite(Motor2F, speedR);
  analogWrite(Motor2T, 0);
}*/

void stopMotors() {
  analogWrite(Motor1F, 0);
  analogWrite(Motor1T, 0);
  analogWrite(Motor2F, 0);
  analogWrite(Motor2T, 0);
}
