//test pour afficher la distance en cm avec le capteur ultrason

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define TRIG 4 // GPIO 23 - pin 16
#define ECHO 5 // GPIO 24 - pin 18
#define LED 27 // GPIO 16 - pin 36

void testDistance(int *distance);
 
void setup() {
    // Setup de wiringPi
    wiringPiSetup();
    
    // I/O
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(LED, OUTPUT);
    
    //TRIG starts LOW
    digitalWrite(TRIG, LOW);
    delay(30);
}
 
int getCM() {
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
 
int main(void) {
    setup();
    while (1)
    {
        int dist=getCM();
        printf("Distance: %dcm\n", dist);
        testDistance(&dist);
    }
    delay(1000);
    }
 
    return 0;
}

// Test distance
// If less than 30cm => LED is OFF
// If more than 30cm => LED is ON
void testDistance(int *distance){
    if(distance < 30){
        digitalWrite(LED, 0);
    }
    else{
        digitalWrite(LED, 1);
    }
}
