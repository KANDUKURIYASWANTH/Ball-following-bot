int trigpin1 = 9;
int echopin1 = 8;

int trigpin2 = 13;
int echopin2 = 12;

int trigpin3 = 10;
int echopin3 = 11;

int en1 = 5;
int en2 = 6;

void setup()
{
    Serial.begin(9600);

    pinMode(trigpin1, OUTPUT);
    pinMode(echopin1, INPUT);

    pinMode(trigpin2, OUTPUT);
    pinMode(echopin2, INPUT);

    pinMode(trigpin3, OUTPUT);
    pinMode(echopin3, INPUT);

    pinMode(en1, OUTPUT);
    pinMode(en2, OUTPUT);
}

void loop()
{
    long distance1, duration1, distance2, duration2, distance3, duration3;
    digitalWrite(trigpin1, HIGH);
    digitalWrite(trigpin2, HIGH);
    digitalWrite(trigpin3, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigpin1, LOW);
    digitalWrite(trigpin2, LOW);
    digitalWrite(trigpin3, LOW);
    duration1 = pulseIn(echopin1, HIGH);
    distance1 = (duration1 / 2) / 29.1;
    duration2 = pulseIn(echopin2, HIGH);
    distance2 = (duration2 / 2) / 29.1;
    duration3 = pulseIn(echopin3, HIGH);
    distance3 = (duration3 / 2) / 29.1;
    Serial.print(distance1);
    Serial.println("cm");

    long dis = min(distance1, min(distance2, distance3));

    if (dis < 5)      //there is a obstacle
    {   
        // finding which one is the least one 
        if (distance1 < distance2 && distance1 < distance3){
            //if obstacle is in the front
            chill();
        }
        if (distance2 < distance1 && distance2 < distance3){
            //if obstacle is in the front
            move_right();
        }
        if (distance3 < distance1 && distance3 < distance2){
            //if obstacle is in the front
            move_left();
        }

    }
    
}