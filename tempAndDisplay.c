#include <LiquidCrystal.h>

///////////////////
// VIKTIG FÖR LABB3
//////////////////

#define blueLight 7
#define yellowLight 8
#define redLight 9
#define motor 10
const int sensorPin = A0;
const float baseLineTemp = 20.0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    Serial.begin(9600);

    for (int pinNum = 7; pinNum < 11; pinNum++)
    {
        pinMode(pinNum, OUTPUT);
        digitalWrite(pinNum, LOW);

        // set up the LCD's number of columns and rows:
        // Print a message to the LCD.
    }
    pinMode(sensorPin, INPUT);
    lcd.begin(16, 2);
}

void loop()
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    // lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    // lcd.print(millis() / 1000);
    int sensorVal = analogRead(sensorPin);

    // Serial.print("Sensor Value: ");
    Serial.print(sensorPin);

    // Serial.print(", Volts: ");
    // Serial.print(voltage);

    // Serial.print(", Degrees C: ");

    // Serial.print(temp);

    if (sensorVal > 0 && sensorVal < 1024)
    {
        float voltage = (sensorVal / 1024.0) * 5.0;
        float temp = (voltage - .5) * 100;

        if (temp < baseLineTemp + 2)
        {
            digitalWrite(blueLight, HIGH);
            digitalWrite(yellowLight, LOW);
            digitalWrite(redLight, LOW);
            // digitalWrite(motor, LOW);
            lcd.print("Degrees C:");
            lcd.print(temp);
            delay(2000);
            lcd.clear();
            delay(2000);
        }
        else if (temp >= baseLineTemp + 2 && temp < baseLineTemp + 4)
        {
            digitalWrite(blueLight, HIGH);
            digitalWrite(yellowLight, HIGH);
            digitalWrite(redLight, LOW);
            // digitalWrite(motor, HIGH);
            lcd.print("Degrees C:");
            lcd.print(temp);
            delay(2000);
            lcd.clear();
            delay(2000);
        }
        else if (temp >= baseLineTemp + 6)
        {
            digitalWrite(blueLight, HIGH);
            digitalWrite(yellowLight, HIGH);
            digitalWrite(redLight, HIGH);
            // digitalWrite(motor, HIGH);
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
}