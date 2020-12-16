#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//Include C files
#include "servoMotorControl.c"
#include "camera_V2.c"
#include "DCMotor.c"
#include "Ultrason.c"



int main(int argc, char *argv[]){
    // Test d'inclusion de servoMotorControl.c
    int angle = 90;
    // Temps en ms pendant lequel le servo moteur bloque sur l'angle envoyé
    int timeSetAngle = 500;
    setServoMotor(&angle, &timeSetAngle);

    // Test d'inclusion de camera_V2.c
    initializeCamera();

    // Test d'inclusion de DCMotor.c
    initializeDCMotors();
    
    // Test d'inclusion de Ultrason.c
    initializeUS_sensor();
    printDistance();
    //TODO : pb avec la fonction testDistance lors de l'appel de
    // libWiringpi.sodistance ??
    while (1)
    {
        int dist=getDistance();
        printf("Distance: %dcm\n", dist);
        testDistance(&dist);
        delay(1000);
    }
}
