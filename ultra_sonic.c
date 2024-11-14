const int trigPin = 2;
const int echoPin = 3;

float duration, distance;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trigPin, LOW);

    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);

    delayMicroseconds(100);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    const float soundSpeed = .0343;
    distance = (duration * soundSpeed) / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    delay(100);
}
