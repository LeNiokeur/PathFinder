//test pour afficher la distance en cm avec le capteur ultrason

#include <stdio.h>
#include <stdlib.h>
#include "Ultrason.h"
#include <wiringPi.h>

#define TRIG 4 // GPIO 23 - pin 16
#define ECHO 5 // GPIO 24 - pin 18
#define LEDV 3 
#define LEDB 2

// A modifier : le calcul de la distance avec travelTime ??

 
void initializeUS_sensor() {
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

    int distance;

    // Send trig pulse
    digitalWrite(TRIG, HIGH);
    // Pulse 20 microsec long
    delayMicroseconds(20);
    // Back to LOW
    digitalWrite(TRIG, LOW);
    // Wait for echo start during ~2000 µs
    int isSignalBack = 0;
    for (int i = 0; i < 2000; i++) {
        if (digitalRead(ECHO) == LOW) {
            isSignalBack = 1;
            break;
        }
        delayMicroseconds(1);
    }
    //while(digitalRead(ECHO) == LOW);
    
    // If we have an echo we calculate travelTime
    if (isSignalBack) {
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;

        //Get distance in cm
        distance = travelTime / 58;
    }
    else {
        distance = 1000000;
    }

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
        LED(dist);
        delay(500);
    }
    return 0;
}
