#define blueLight 2
#define yellowLight 3
#define redLight 4
#define motor 5
const int sensorPin = A0;
const float baseLineTemp = 20.0;

void setup()
{
    Serial.begin(9600);

    for (int pinNum = 2; pinNum < 6; pinNum++)
    {
        pinMode(pinNum, OUTPUT);
        digitalWrite(pinNum, LOW);
    }
}
void loop()
{
    int sensorVal = analogRead(sensorPin);

    // Serial.print("Sensor Value: ");
    Serial.print(sensorPin);

    float voltage = (sensorVal / 1024.0) * 5.0;

    // Serial.print(", Volts: ");
    Serial.print(voltage);

    // Serial.print(", Degrees C: ");
    float temp = (voltage - 0.5) * 100;
    Serial.print(temp);

    if (temp < baseLineTemp + 2)
    {
        digitalWrite(blueLight, HIGH);
        digitalWrite(yellowLight, LOW);
        digitalWrite(redLight, LOW);
        digitalWrite(motor, LOW);
    }
    else if (temp >= baseLineTemp + 2 && temp < baseLineTemp + 4)
    {
        digitalWrite(blueLight, HIGH);
        digitalWrite(yellowLight, HIGH);
        digitalWrite(redLight, LOW);
        digitalWrite(motor, HIGH);
    }
    else if (temp >= baseLineTemp + 6)
    {
        digitalWrite(blueLight, HIGH);
        digitalWrite(yellowLight, HIGH);
        digitalWrite(redLight, HIGH);
        digitalWrite(motor, HIGH);
    }
    delay(1);
}