#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//Include C files
#include "servoMotorControl.c"
#include "camera_V2.c"
#include "DCMotor.c"
#include "Ultrason.c"

// Commande pour compiler :
//gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt

int main(int argc, char *argv[]){
    // Test d'inclusion de servoMotorControl.c
    //int angle = 90;
    // Temps en ms pendant lequel le servo moteur bloque sur l'angle envoyé
    //int timeSetAngle = 500;
    //setServoMotor(&angle, &timeSetAngle);

    // Test d'inclusion de camera_V2.c
    //initializeCamera();

    // Test d'inclusion de DCMotor.c
    initializeDCMotors();
    
    // Test d' inclusion de Ultrason.c
    initializeUS_sensor();
    while (1)
    {
        int LeftDistance;
        int RightDistance;
        int angle = 90;   
        int Leftangle = 0;
        int Rightangle = 180;
        int timeSetAngle = 1000;
        int dist=getDistance();
        printf("Distance: %dcm\n", dist);
        delay(100);
        if (dist<30){
            LED(dist);
            moveBackward();
            initializeCamera();
            delay(500);
            //Integrer servo pour connaitre la distance à gauche et à droite
            setServoMotor(&angle, &timeSetAngle);
            delay(500);
            
            //Valeur distance à gauche
            setServoMotor(&Leftangle, &timeSetAngle);
            LeftDistance = getDistance();
            delay(500);
            
            setServoMotor(&angle, &timeSetAngle);
            delay(500);
           
            //Valeur de distance à droite
            setServoMotor(&Rightangle, &timeSetAngle);
            RightDistance = getDistance();
            
            setServoMotor(&angle, &timeSetAngle);
            delay(500);

            //Comparaison des deux distance
            
            if (LeftDistance>RightDistance) {
                turnLeft();
                delay(500);
            }
            else if (LeftDistance<RightDistance) {
                turnRight();
                delay(500);
            }
        }
        else if(dist>30){
            LED(dist);
           moveForward();
        }
            
    }
    return 0;
}
