#include <LiquidCrystal.h>

///////////////////

// VIKTIG FÖR LABB3

//////////////////

#define trigPin 12

#define echoPin 13

#define motorPin 11

#define blueLight 10

#define yellowLight 9

#define redLight 8

const int sensorPin = A0;

const float baseLineTemp = 20.0;

float duration, distance;

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()

{

    pinMode(trigPin, OUTPUT);

    pinMode(echoPin, INPUT);

    pinMode(motorPin, OUTPUT);

    Serial.begin(9600);

    for (int pinNum = 8; pinNum < 12; pinNum++)

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

    digitalWrite(trigPin, HIGH);

    delayMicroseconds(100);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    int sensorVal = analogRead(sensorPin);

    Serial.print(sensorPin);

    float voltage = (sensorVal / 1024.0) * 5.0;

    float temp = (voltage - .5) * 100;

    const float soundSpeed = .0343;

    distance = (duration * soundSpeed) / 2;

    Serial.print("Distance: ");

    Serial.print(distance);

    Serial.println(" cm");

    if (temp < baseLineTemp + 2)

    {

        digitalWrite(blueLight, HIGH);

        digitalWrite(yellowLight, LOW);

        digitalWrite(redLight, LOW);

        digitalWrite(motorPin, LOW);

        lcd.setCursor(0, 0);

        lcd.print("Degrees C:");

        lcd.print(temp);

        lcd.setCursor(0, 1);

        for (int i = 0; i < 16; i++)
        {

            lcd.print(" ");
        }
    }

    else if (temp >= baseLineTemp + 2 && temp < baseLineTemp + 8)

    {

        digitalWrite(blueLight, LOW);

        digitalWrite(yellowLight, HIGH);

        digitalWrite(redLight, LOW);

        if (distance < 30.0)
        {

            digitalWrite(motorPin, HIGH);
        }

        else
        {

            digitalWrite(motorPin, LOW);
        }

        lcd.setCursor(0, 0);

        lcd.print("Degrees C:");

        lcd.print(temp);

        lcd.setCursor(0, 1);

        lcd.print("Place hand: ");
    }

    else if (temp >= baseLineTemp + 10)

    {

        digitalWrite(blueLight, LOW);

        digitalWrite(yellowLight, LOW);

        digitalWrite(redLight, HIGH);

        digitalWrite(motorPin, HIGH);

        lcd.setCursor(0, 0);

        lcd.print("Degress C:");

        lcd.print(temp);

        lcd.setCursor(0, 1);

        lcd.print("Cooling down.");

        delay(2000);

        lcd.clear();

        delay(2000);
    }

    // delay(1);
}
