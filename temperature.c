const int motor = 7;
const int sensorPin = A0;
const float baseLineTemp = 20.0;

void setup()
{
    Serial.begin(9600);
    pinMode(motor, OUTPUT);

    for (int pinNum = 2; pinNum < 5; pinNum++)
    {
        pinMode(pinNum, OUTPUT);
        digitalWrite(pinNum, LOW);
    }
}
void loop()
{
    int sensorVal = analogRead(sensorPin);

    Serial.print("Sensor Value: ");
    Serial.print(sensorPin);

    float voltage = (sensorVal / 1024.0) * 5.0;

    Serial.print(", Volts: ");
    Serial.print(voltage);

    Serial.print(", Degrees C: ");
    float temp = (voltage - .5) * 100;
    Serial.print(temp);

    if (temp < baseLineTemp + 2)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
    }
    else if (temp >= baseLineTemp + 2 && temp < baseLineTemp + 4)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(7, HIGH);
    }
    else if (temp >= baseLineTemp + 6)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(7, HIGH);
    }
    delay(1);
}
