#include <IRremote.h>
#define pinLed 13
#define pinSensor 10 // o que vai ser acionado quando clickar no botão OK

IRrecv sensor(pinSensor);
decode_results command;

bool ledStatus = false;

void setup() {
  Serial.begin(9600);  // sei lá que porra é essa

  // dizendo pra começar a escutar
  sensor.enableIRIn();

  pinMode(pinLed, OUTPUT);
}

void loop() {

  if (sensor.decode(&command)) {  // se recebeu alguma coisa do sensor, escreve o que recebeu em command
    Serial.println(command.value, HEX);
    if (command.value == 0xFF38C7) {
      
      digitalWrite(pinLed, ledStatus); 
      ledStatus = !ledStatus;
            
    }
    sensor.resume();
  }
  
}
