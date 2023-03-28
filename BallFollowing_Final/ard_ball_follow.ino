// Motors 

//a1 a2 left motors
#define A1 1 //forward
#define A2 2 //backward
//a3 a4 right motors
#define A3 3 //forward
#define A4 4 //backward

//for Ultrasonic sensor
int trigpin1 = 9;
int echopin1 = 8;

int trigpin2 = 13;
int echopin2 = 12;

int trigpin3 = 10;
int echopin3 = 11;

int en1 = 5;
int en2 = 6;

String a,b,c;

float distance, x, y, x_upper = 380, x_lower = 250 ;
void setup()
{
    Serial.begin(9600);

    //   pinMode(trigpin1, OUTPUT);
    //   pinMode(echopin1, INPUT);

    //   pinMode(trigpin2, OUTPUT);
    //   pinMode(echopin2, INPUT);

    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);

    pinMode(en1, OUTPUT);
    pinMode(en2, OUTPUT);
}
void loop()
{
    if (Serial.available()) // checking if we are getting the input from the raspberry pi
    {
        a= Serial.readStringUntil('\n'); // reads the data sent from raspberry pi for the distance

        distance = a.toFloat();
        Serial.read();
        b = Serial.readStringUntil('\n');
        x = b.toFloat(); // X coordinate of ball
        Serial.read();
        c= Serial.readStringUntil('\n');
        y = c.toFloat();

        if (distance > 20)
        {
            //the ring around condition
            if (y>70){
                ring_around();
            }
            else{
                if (distance>25 && distance<=40){
                    no_chill();
                    if (x > x_upper){
                        move_right();}
                    if (x < x_lower){
                        move_left();}
                } 
                else{    
                    move_forward();
                    if (x > x_upper){
                        move_right();}
                    if (x < x_lower){
                        move_left();}
                }
            }
            
        }
        
        else if (distance >=5 && distance <= 20)
        {
            //the ring around condition
            if (y>70){
                ring_around();
            }
            else{
                move_forward();
                if (x > x_upper)
                    move_right();
                if (x < x_lower)
                    move_left();
            }
        }
    }

    //Ultrasonic sensor part
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


// functions for the arduino code starts here

void move_forward()
{
    analogWrite(A1, 200);
    analogWrite(A2, 0);
    analogWrite(A3, 200);
    analogWrite(A4, 0);
}

void move_left()
{
    analogWrite(A1, 0);
    analogWrite(A2, 100);
    analogWrite(A3, 195);
    analogWrite(A4, 0);
}

void move_right()
{
    analogWrite(A1, 195);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A4, 100);
}
void chill(){
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A4, 0);
}
void no_chill(){
    analogWrite(en1, 250);
    analogWrite(en2, 250);
}

void ring_around(){
    analogWrite(A1, 0);
    analogWrite(A2, 100);
    analogWrite(A3, 200);
    digitalWrite(A4,0);
}


