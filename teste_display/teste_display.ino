#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 12);  // KKKK EU TROQUEI A 12 E 13


byte smiley[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  analogWrite(A0, 255);

  // definindo o caractere \x01 como o que criamos :D
  lcd.createChar(0x1, smiley);

  lcd.begin(16, 2);  // size of our display
}
String mstr = "Estudando \\";
uint32_t c = 0;
void loop() {
  c++;
  if (c % 2 == 0) {
    mstr = "Estudando O";
  } else {
    mstr = "Estudando o";
  }
  // put your main code here, to run repeatedly:
  lcd.print("1423");
  delay(1000);
  lcd.clear();
}
