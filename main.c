#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//Include C files
#include "servoMotorControl.c"
#include "camera_V2.c"
#include "DCMotor.c"
#include "Ultrason.c"

// Include prototype function
void initialize_AllFunctions();

// Commande pour compiler :
//gcc -o main main.c -lwiringPi -lrt -lpthread -lm -lrt -lcrypt


// A MODIFIER  : le delay lors du move sur la gauche ou la droite (l50-60)
// le setServoMotor qui bloque assez longtemps sans bloquer le processus et qu'il fasse la capteur de la distance ? (l30 - 40)
int main(int argc, char *argv[]){
    
    // Initialize all sensors and functions
    initialize_AllFunctions();

    int leftDistance;
    int rightDistance;
    int centerDistance;
    int centerAngle = 90;   
    int leftangle = 0;
    int rightangle = 180;
    int timeSetAngle = 500;

    while (1)
    {

        //Start first move by checking best direction to go

/* ----------------------------------------------------
*  -         Check left and right for direction       -
*  ---------------------------------------------------- */

        // Distance sensor back to center
        setServoMotor(&centerAngle, &timeSetAngle);
        // Ya deja un temps d'action sur le servoMotor
        // Double delai ?
        delay(200);
        
        // Left check -90°
        setServoMotor(&leftangle, &timeSetAngle);
        leftDistance = getDistance();
        delay(500);
        
        // Je pense que tu peux l'envoyer à droite direct 
        // sans passer par la position centrale
        //setServoMotor(&angle, &timeSetAngle);
        //delay(500);
       
        // Right check +90°
        // Il bloque sur l'angle et mesure la distance ?
        setServoMotor(&rightangle, &timeSetAngle);
        rightDistance = getDistance();
        
        // Back to center position 0°
        setServoMotor(&centerAngle, &timeSetAngle);
        delay(100);

        //Compare distance for direction
// Peut etre ajouter le choix de reculer dès le premier move en supposant qu'il y ait rien derriere...
        if (leftDistance == rightDistance) {
            // Ca peut être gauche ou droite donc on va dire droite au hasard
            turnRight();
            delay(500);
        }
        else if (leftDistance > rightDistance) {
            // Dans le turnLeft il y a déja un délai
            turnLeft();
            delay(500);
        }
        else if (leftDistance < rightDistance) {
            turnRight();
            // Dans le turnRight il y a déja un delai
            delay(500);
        }

/* ----------------------------------------------------
*  -     Move forward until it reaches an obstacle    -
*  ---------------------------------------------------- */
        
        // Start to check distance
        centerDistance = getDistance();
        // Moving = green light
        LED(centerDistance);
        moveForward();
        // Move forward until obstacle
        while(centerDistance > 30) {
        // il faudra afficher la distance dans la console sans spam de milliers de print par seconde...
            //printf("Distance: %dcm\n", dist);
            centerDistance = getDistance();
        }
        // Stop motors
        stopMotors();
        // Stop = red light
        LED(centerDistance);
        // Take a picture
        initializeCamera();   
    // Back to beginning of loop 
    }

    return 0;
}

void initialize_AllFunctions(){

    // Setup de wiringPi
    wiringPiSetup();

    // Setup camera
    initializeCamera();

    // Setup DC motors
    initializeDCMotors();
    
    // Setup ultrasonic sensor
    initializeUS_sensor();

}
