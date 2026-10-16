#include <math.h>

const int sensorPin = 34;     // NTC analog giriş
const int redLed = 19;        // Kırmızı LED
const int greenLed = 23;      // Yeşil LED

const float THRESHOLD = 30.0; // Sıcaklık sınırı

// NTC sabitleri (10k NTC için tipik değerler)
const float nominalResistance = 10000;   // 25°C'deki direnç
const float nominalTemperature = 25;     // 25°C
const float bCoefficient = 3950;         // B değeri
const float seriesResistor = 10000;      // Modüldeki 10k sabit direnç

void setup() {
  Serial.begin(115200);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  int raw = analogRead(sensorPin);

  // ADC → voltaj oranı
  float voltageRatio = raw / 4095.0;

  // NTC direncini hesapla
  float resistance = seriesResistor * (voltageRatio / (1.0 - voltageRatio));

  // Steinhart–Hart (basitleştirilmiş B-formülü)
  float steinhart;
  steinhart = resistance / nominalResistance;       // R/R0
  steinhart = log(steinhart);                       // ln(R/R0)
  steinhart /= bCoefficient;                        // 1/B * ln(R/R0)
  steinhart += 1.0 / (nominalTemperature + 273.15); // + 1/T0
  steinhart = 1.0 / steinhart;                      // ters çevir
  steinhart -= 273.15;                              // Kelvin → °C

  float temperature = steinhart;

  Serial.print("Temperature: ");
  Serial.println(temperature);

  // LED kontrolü
  if (temperature > THRESHOLD) {
    digitalWrite(greenLed, LOW);

    // Kırmızı LED yanıp sönsün
    digitalWrite(redLed, HIGH);
    delay(200);
    digitalWrite(redLed, LOW);
    delay(200);

    Serial.println("WARNING: temperature too high!");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  delay(500);
}
