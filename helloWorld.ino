//Basic code stucture for Particle Photon using Particle Build online IDE
//Based on the startup tutorials on the Particle docs Guide
//By Sarah Busch in October 2016

int sensorValue;

void setup() 
{
    pinMode(D0, OUTPUT); //pins 0-1 are controlling external leds
    pinMode(D1, OUTPUT);
    pinMode(D7, OUTPUT); //pin 7 is controlling the onboard led tied to it
    
    pinMode(A0, INPUT); //read voltage on photoresistor
    pinMode(A5, OUTPUT); //send a consistent power to the photoresistor
    digitalWrite(A5, HIGH); //power the photoresistor
    
    //declaration of a Particle.variable() so that we can access the value from the cloud
    //when we ask the cloud for "analogvalue" it will reference the int "sensorValue" in this app
    Particle.variable("analogValue", &sensorValue, INT);
    
    //declaration of a Particle.function so the leds can be toggled from the cloud
    //'when we ask the cloud for the function "led", it will emply the function ledToggle() from this app
    Particle.function("led",ledToggle);
    
    //ensure all leds are off to start
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D7, HIGH); //onboard led turns on to indicate this app in flashed properly and running
}

void loop() 
{
    //get the analog value of the photoresistor
    sensorValue = analogRead(A0);
    delay(100);
}

int ledToggle(String command) //'Particle.functions always take a string as an argument and return and integer.'
{
    if (command=="on") //toggles led on
    {
        digitalWrite(D0, HIGH);
        return 1;
    }
    else if (command=="off") //toggle led off
    {
        digitalWrite(D0, LOW);
        return 0;
    }
    else //if the command is not valid
    {
        return -1;
    }
}

