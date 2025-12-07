#include <Servo.h>

//Definición de los servos
Servo servo1;
Servo servo2;
Servo servo3;

String inputString = "";
bool stringComplete = false;

//Parsear q1, q2, q3
float q1 = 0, q2 = 0, q3 = 0;

// ------------------------------
// ACTIVAR/DESACTIVAR PRINTS
// ------------------------------
bool DEBUG = false;    //Se cambia a true para activar serial prints en la consola de python (solo para Debug)

void setup() {
  Serial.begin(115200);

  //Puerto digital PWM asignado a cada servomotor
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);

  //Arrancar servos en la posición de HOME (brazos verticales, punta retraída)
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);


  inputString.reserve(40);

  if (DEBUG) Serial.println("Iniciando Arduino (DEBUG ON)");
}

void loop() {
  //Debug, imprime en el monitor serial (python) el valor de los ángulos recibidos
  //únicamente para debug y revisiones de comunicación efectiva, porque los serial prints
  //introducen pausas que podrían hacer que el robot tenga menor fluidez
  if (stringComplete) {
    
    if (DEBUG) {
      Serial.print("Recibido crudo: ");
      Serial.println(inputString);
    }

    int c1 = inputString.indexOf(',');
    int c2 = inputString.indexOf(',', c1 + 1);

    if (c1 > 0 && c2 > 0) {
      q1 = inputString.substring(0, c1).toFloat();
      q2 = inputString.substring(c1 + 1, c2).toFloat();
      q3 = inputString.substring(c2 + 1).toFloat();
    }

    if (DEBUG) {
      Serial.print("Parseado -> q1: "); Serial.print(q1);
      Serial.print(" | q2: "); Serial.print(q2);
      Serial.print(" | q3: "); Serial.println(q3);
    }


    //Mover los servos según los ángulos recibidos
    servo1.write(q1);
    servo2.write(q2);
    servo3.write(q3);

    //Limpiar buffer
    inputString = "";
    stringComplete = false;

    //Responder a Python
    Serial.println("OK");    //NO QUITAR, es parte del protocolo
  }
}

//Comunicación serial
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}

