// PINLER
const int ledPin = 19;       // LED
const int potPin = 35;       // Slide pot (SIG)

// DURUMLAR
unsigned long oncekiZaman = 0;
int ledDurum = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // --- Pot değerini oku ---
  int potDeger = analogRead(potPin);   // 0–4095
  Serial.println(potDeger);

  // --- Parlaklık PWM değeri ---
  int pwm = map(potDeger, 0, 4095, 0, 255);

  // --- Blink frekansı ---
  int hiz = map(potDeger, 0, 4095, 50, 800);

  // --- Blink sistemi ---
  unsigned long simdi = millis();
  if (simdi - oncekiZaman >= hiz) {
    ledDurum = !ledDurum;
    oncekiZaman = simdi;
  }

  // --- LED açıkken PWM uygula, kapalıyken tamamen kapat ---
  if (ledDurum == HIGH) {
    analogWrite(ledPin, pwm);   // parlaklık kontrolü
  } else {
    digitalWrite(ledPin, LOW);  // tamamen kapat
  }
}
