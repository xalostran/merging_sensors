#include <LiquidCrystal.h>

///////////////////
// VIKTIG FÖR LABB3
//////////////////

#define blueLight 7
#define yellowLight 8
#define redLight 9
const int sensorPin = A0;
const float baseLineTemp = 17.0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    Serial.begin(9600);

    for (int pinNum = 7; pinNum < 11; pinNum++)
    {
        pinMode(pinNum, OUTPUT);
        digitalWrite(pinNum, LOW);
    }
    pinMode(sensorPin, INPUT);
    lcd.begin(16, 2);
}

void loop()
{
    int sensorVal = analogRead(sensorPin);

    Serial.print(sensorPin);

    if (sensorVal > 0 && sensorVal < 1024)
    {
        float voltage = (sensorVal / 1024.0) * 5.0;
        float temp = (voltage - .5) * 100;

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
        }
        else
        {
            lcd.print("Error");
        }
        delay(1);
    }
