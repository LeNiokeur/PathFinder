//
//  Led.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 09/11/2020.
//  Copyright © 2020 Troyan Hugo. All rights reserved.
//

#include "Led.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

#define LEDV 3 
#define LEDB 2

void initialize_Led(){
    pinMode(LEDV, OUTPUT);
    pinMode(LEDB, OUTPUT);
    LedRed();
}

void LedGreen(){
    digitalWrite(LEDV, 1);
    digitalWrite(LEDB, 0);
}

void LedRed(){
    digitalWrite(LEDV, 0);
    digitalWrite(LEDB, 1);
}
