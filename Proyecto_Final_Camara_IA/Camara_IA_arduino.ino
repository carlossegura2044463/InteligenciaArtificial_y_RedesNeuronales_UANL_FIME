#include <Servo.h>

Servo horizontal;
Servo vertical;

const int PIN_HORIZONTAL = 9;
const int PIN_VERTICAL = 10;

const int CENTRO = 90;
const int H_MIN = 50;
const int H_MAX = 130;
const int V_MIN = 55;
const int V_MAX = 125;

int actualH = CENTRO;
int actualV = CENTRO;

void moverConTopes(int pedidoH, int pedidoV) {
  int destinoH = constrain(pedidoH, H_MIN, H_MAX);
  int destinoV = constrain(pedidoV, V_MIN, V_MAX);

  while (actualH != destinoH || actualV != destinoV) {
    if (actualH < destinoH) actualH++;
    else if (actualH > destinoH) actualH--;

    if (actualV < destinoV) actualV++;
    else if (actualV > destinoV) actualV--;

    horizontal.write(actualH);
    vertical.write(actualV);
    delay(30);
  }

  Serial.print("Angulo ordenado: horizontal = ");
  Serial.print(actualH);
  Serial.print(" | vertical = ");
  Serial.println(actualV);
}

void setup() {
  Serial.begin(9600);

  horizontal.attach(PIN_HORIZONTAL);
  vertical.attach(PIN_VERTICAL);
  horizontal.write(CENTRO);
  vertical.write(CENTRO);

  Serial.println("H: recorrido horizontal | V: recorrido vertical");
  Serial.println("+: horizontal +5 grados | -: horizontal -5 grados");
  Serial.println("F: frente 5 grados | A: atras 5 grados | C: centrar");
}

void loop() {
  if (Serial.available() == 0) return;

  char orden = Serial.read();

  switch (orden) {
    case 'H':
    case 'h':
      moverConTopes(H_MIN, CENTRO);
      delay(1200);
      moverConTopes(H_MAX, CENTRO);
      delay(1200);
      moverConTopes(CENTRO, CENTRO);
      break;

    case 'V':
    case 'v':
      moverConTopes(CENTRO, V_MIN);
      delay(1200);
      moverConTopes(CENTRO, V_MAX);
      delay(1200);
      moverConTopes(CENTRO, CENTRO);
      break;

    case '+':
      moverConTopes(actualH + 5, actualV);
      break;

    case '-':
      moverConTopes(actualH - 5, actualV);
      break;

    case 'F':
    case 'f':
      moverConTopes(actualH, actualV - 5);
      break;

    case 'A':
    case 'a':
      moverConTopes(actualH, actualV + 5);
      break;

    case 'C':
    case 'c':
      moverConTopes(CENTRO, CENTRO);
      break;
  }
}