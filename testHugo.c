#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
//Include C files
#include "servoMotorControl.c"
#include "camera_V2.c"
#include "DCMotor.c"
#include "Ultrason.c"


int main(int argc, char *argv[]){
    
    initializeUS_sensor();
    while(1){
        int dist = getDistance();
        printf("La distance : %d", dist);
    }

}
