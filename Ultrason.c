//test pour afficher la distance en cm avec le capteur ultrason

#include <stdio.h>
#include <stdlib.h>
#include "Ultrason.h"
#include <wiringPi.h>

#define TRIG 4 // GPIO 23 - pin 16
#define ECHO 5 // GPIO 24 - pin 18
#define LEDV 0 
#define LEDB 2

 
void initializeUS_sensor() {
    // Setup de wiringPi
    wiringPiSetup();
    
    // I/O
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(LEDV, OUTPUT);
    pinMode(LEDB, OUTPUT);
    
    //TRIG starts LOW
    digitalWrite(TRIG, LOW);
    delay(30);
}
 
int getDistance() {
    // Send trig pulse
    digitalWrite(TRIG, HIGH);
    // Pulse 20 microsec long
    delayMicroseconds(20);
    // Back to LOW
    digitalWrite(TRIG, LOW);

    // Wait for echo start
    while(digitalRead(ECHO) == LOW);

    //Wait for echo end
    long startTime = micros();
    while(digitalRead(ECHO) == HIGH);
    long travelTime = micros() - startTime;

    //Get distance in cm
    int distance = travelTime / 58;
    return distance;
}
 

// Test distance
// If less than 20cm => LED is OFF
// If more than 20cm => LED is ON
void LED(int distance){

    if(distance < 20){
        digitalWrite(LEDV, 0);
        digitalWrite(LEDB, 1);

    }
    else{
        digitalWrite(LEDV, 1);
        digitalWrite(LEDB, 0);
    
    }
}

int printDistance(){
    //setup();
    while(1)
    {
        int dist=getDistance();
        printf("Distance: %dcm\n", dist);
        //LED(dist);
        delay(1000);
    }
    return 0;
    }
