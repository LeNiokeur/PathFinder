//
//  servoMotorControl.c
//  RaspberryPi
//
//  Created by Boulon Marie on 09/11/2020.
//  Copyright © 2020 Troyan Hugo. All rights reserved.
//

#include "servoMotorControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

// A MODIFIER : ajout fonction pour tourner a gauche, droite et centre en restant bloqué sur cette position sans bloquerle programme
// En utilisant une pin sur laquelle tu peux configurer une PWM qui s'arrete jamais sans bloqué le programme dans une boucle ou autre

#define SERVO 0 //Equivalent WiringPi 0 : GPIO 17
#define TPSACTIONMOTEUR 500 //Temps en ms pendant lequel le servo moteur prend l'angle spécifié en argument

// Le servo moteur tourne avec un angle de 0 à 180° en fonction du signal PWM qu'on lui injecte.
// Le signal est carré de période 20 ms
// Un angle de 0 ° correspond a 1ms à l'état haut
// Un angle de 90° correspond a 1.5ms à l'état haut
// Un angle de 180° correspond a 2ms à l'état haut

//timeSetAngle :Temps en ms pendant lequel le servo moteur prend l'angle spécifié en argument
int setServoMotor(int *angle, int *timeSetAngle)
{
    // Angle :
    // angle en degré (°) compris entre 0 et 180°
    // pulse :
    // Temps à l'état haut du signal carré qui sera envoyé sur la pin PWM du servo moteur
    // left :
    // Temps à l'état bas du signal PWM
    // i
    int pulse, left, i;
    
    //En argument l'angle que l'on veut envoyer au servo moteur
    //angle = atoi(argv[1]);
    //Un servo moteur peut tourner de 0 à 180°. Pas plus.
    if (*angle > 180 || *angle < 0 ) {*angle=0;}
    printf("angle to send : %d\n during : %dms", *angle, *timeSetAngle);
    
    //Mise de la pin GPIO 17 en sortie
    pinMode(SERVO, OUTPUT);
    //On envoie un 0 pour commencer (??)
    digitalWrite(SERVO,0);

    // Calcul de pulse
    pulse=(*angle*5.56)+1000;
    printf("pulse to send : %d\n",pulse);
    left=20000-pulse;
    i=0;
    
    // La rotation est effectuée sur le temps :TPSACTIONMOTEUR
    while ( i < *timeSetAngle ) {
        i += 20;
        digitalWrite(SERVO,1);
        delayMicroseconds(pulse);
        digitalWrite(SERVO,0);
        delayMicroseconds(left);
    }
    return 0;
}


void setPulse(int *angle) {
    // Fonction qui doit bloquer le servo moteur avec une PWM avec l'angle passé en paramètre
    // Cette fonction sera utilisée dans setLeftAngle, setRightAngle, setCenterAngle
}

void setLeftAngle() {
    // TODO
    //setPulse(0);
}

void setRightAngle() {
    // TODO
    //setPulse(180);
}

void setCenterAngle() {
    // TODO
    //setPulse(90);
}
