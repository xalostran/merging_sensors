#include <LiquidCrystal.h>

///////////////////
// VIKTIG FÖR LABB3
//////////////////

#define trigPin 2
#define echoPin 3
#define blueLight 4
#define yellowLight 5
#define redLight 6
#define motorPin 7
const int sensorPin = A0;
const float baseLineTemp = 17.0;
bool sensorState;

const int rs = 13, en = 12, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600);

    for (int pinNum = 4; pinNum < 8; pinNum++)
    {
        pinMode(pinNum, OUTPUT);
        digitalWrite(pinNum, LOW);
    }
    pinMode(sensorPin, INPUT);
    lcd.begin(16, 2);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(100);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    int sensorVal = analogRead(sensorPin);

    Serial.print(sensorPin);

    float voltage = (sensorVal / 1024.0) * 5.0;
    float temp = (voltage - .5) * 100;
    const float soundSpeed = .0343;

    distance = (duration * soundSpeed) / 2;

    if (temp < baseLineTemp + 2)
    {
        digitalWrite(blueLight, HIGH);
        digitalWrite(yellowLight, LOW);
        digitalWrite(redLight, LOW);
        lcd.print("Degrees C:");
        lcd.print(temp);
        delay(2000);
        lcd.clear();
        delay(2000);
    }
    else if (temp >= baseLineTemp + 2 && temp < baseLineTemp + 4)
    {
        digitalWrite(blueLight, LOW);
        digitalWrite(yellowLight, HIGH);
        digitalWrite(redLight, LOW);
        lcd.print("Degrees C:");
        lcd.print(temp);
        delay(2000);
        lcd.clear();
        delay(2000);

        lcd.setCursor(0, 1);
        lcd.print("Place hand to turn on the fan");
    }
    else if (temp >= baseLineTemp + 6)
    {
        digitalWrite(blueLight, LOW);
        digitalWrite(yellowLight, LOW);
        digitalWrite(redLight, HIGH);
        lcd.print("Degress C:");
        lcd.print(temp);
        delay(2000);
        lcd.clear();
        delay(2000);

        lcd.setCursor(0, 1);
        lcd.print("It is getting too hot!");
    }
    else
    {
        lcd.print("Error");
    }
    delay(1);
}
