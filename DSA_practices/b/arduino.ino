int red = 9;
int yellow = 8;
int green = 7;
int ultrasonicTrigger = 2; // Assuming your ultrasonic sensor's trigger pin is connected to digital pin 2
int ultrasonicEcho = 3;    // Assuming your ultrasonic sensor's echo pin is connected to digital pin 3

void setup()
{
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(ultrasonicTrigger, OUTPUT);
    pinMode(ultrasonicEcho, INPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(red, HIGH);
    RedLedoff();
    delay(1500);
    digitalWrite(red, LOW);

    digitalWrite(yellow, HIGH);
    // Activate ultrasonic sensor when the LED is yellow
    activateUltrasonicSensor();
    delay(1500);
    digitalWrite(yellow, LOW);
    delay(1500);

    digitalWrite(green, HIGH);
    // Activate ultrasonic sensor when the LED is green
    activateUltrasonicSensor();
    delay(300);
    digitalWrite(green, LOW);

    digitalWrite(yellow, HIGH);
    // Activate ultrasonic sensor when the LED is green
    activateUltrasonicSensor();
    delay(200);
    digitalWrite(yellow, LOW);
    delay(500);
}
void activateUltrasonicSensor()
{
    digitalWrite(ultrasonicTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(ultrasonicTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonicTrigger, LOW);

    Serial.println("I am on");

    digitalWrite(ultrasonicTrigger, LOW);
    delayMicroseconds(20000);
    digitalWrite(ultrasonicTrigger, HIGH);
    delayMicroseconds(2000);
    digitalWrite(ultrasonicTrigger, LOW);

    long duration = pulseIn(ultrasonicEcho, HIGH);

    // Calculate distance in centimeters
    int distance_cm = duration * 0.034 / 2;

    // Perform actions based on the distance
    if (distance_cm <= 10)
    {
        // If an object is very close (within 10 cm), do something
        Serial.println("Object is very close!");
        delay(2000);
        // Add your actions here, such as stopping the traffic light cycle
    }
    else if (distance_cm > 10 && distance_cm <= 20)
    {
        // If an object is moderately close (between 10 cm and 20 cm), do something else
        Serial.println("Object is moderately close.");
        delay(2000);
        // Add your actions here
    }
    else
    {
        // If no object is detected within a certain range, do a default action
        Serial.println("No object detected.");
        delay(2000);
        // Add your
    }
}
void RedLedoff()
{
    long duration = pulseIn(ultrasonicEcho, LOW);
    Serial.println("I am off");
}