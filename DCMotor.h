//
//  DCMotor.h
//  RaspberryPi
//
//  Created by Boulon Marie on 09/11/2020.
//  Copyright © 2020 Troyan Hugo. All rights reserved.
//

#ifndef DCMotor_h
#define DCMotor_h

#include <stdio.h>

void initializeDCMotors(void);
void moveForward(int *tempsMouvement);
void moveBackward(int *tempsMouvement);
void turnLeft(int *tempsMouvement);
void turnRight(int *tempsMouvement);

#endif /* DCMotor_h */
