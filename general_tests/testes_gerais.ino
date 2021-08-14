int val = 0;         // variable to store the read value

void setup() {
pinMode(10,OUTPUT);
  analogWrite(A0, 255);
}

void loop() {
  val = analogRead(A1);  // read the input pin
  analogWrite(10, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
f  
}