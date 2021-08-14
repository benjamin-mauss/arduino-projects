// ARDUINO MORSE CODE PROJECT

// morse-code source:
// https://www.educamaisbrasil.com.br/enem/lingua-portuguesa/codigo-morse
#define pinLed 13
static struct morse_codes {
  // the characters that I allow in the string
  const char morse_alf[40] = "abcdefghijklmnopqrstuvwxyz1234567890 ,.";

  // . = short signal
  // - = long signal
  // 0 = short interval (between characters)
  // 1 = medium interval (between words)
  // 2 = long interval (between phrases)
  const char* morse_codes_arr[40] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".---", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
    "1", "2", "3"
  };
} morse;

void setup() {

  /*
avoid confusion when arduino is starting
*/
  digitalWrite(pinLed, HIGH);
  delay(3000);
  digitalWrite(pinLed, LOW);

  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  // only low case for now
  const char my_str[] = "hello";
  Serial.println(my_str);

  String morse_code_str;
  // convertendo my_str para código morse
  for (int x = 0; x < sizeof(my_str); x++) {
    for (int k = 0; k < sizeof(morse.morse_alf) - 1; k++) {
      if (my_str[x] == morse.morse_alf[k]) {
        morse_code_str += morse.morse_codes_arr[k];
        morse_code_str += '0';
        break;
      }
    }
  }
  Serial.println(morse_code_str);


  // Now, we want to interpretate this morse code
  for (int x = 0; x < morse_code_str.length(); x++) {
    delay(500); // between . and - or -- or .. etc
    if (morse_code_str[x] == '0') {
      // between a letter and other
      delay(1000);
    } else if (morse_code_str[x] == '1') {
      // between words
      delay(1000);
    } else if (morse_code_str[x] == '2') {
      // a comma
      delay(2000);
    }else if (morse_code_str[x] == '3') {
      // a dot
      delay(3000);
    } else if (morse_code_str[x] == '.') {
      // morse
      digitalWrite(pinLed, HIGH);
      delay(200);
      digitalWrite(pinLed, LOW);
    } else if (morse_code_str[x] == '-') {
      // morse
      digitalWrite(pinLed, HIGH);
      delay(800);
      digitalWrite(pinLed, LOW);
    } else {
      Serial.println("Error 1!");
    }
  }
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
