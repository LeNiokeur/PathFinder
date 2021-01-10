# PathFinder

Projet C Ing4 SE APP
TROYAN Hugo
DAMIENS Léa


Ce robot a pour but de trouver son chemin de manière autonome grâce au capteur ultrasonique. Il possède 2 moteurs DC, un servomoteur sur lequel est monté le capteur ultrasonique, une caméra permettant de prendre une photo lors d'une détection d'obstacle et des LEDs rouge et verte de fonctionnement.

Les moteurs DC sont alimentés via un module de contrôle L298N, permettant de les faire fonctionner dans les deux sens de rotation.
Le servomoteur est contrôlé par un signal PWM fourni par la Raspberry Pi.

Le robot est autonomone en alimentation. La Raspberry Pi est alimentée par une alimentation 5V sur piles, de même que pour les moteurs DC et leur module de contrôle qui sont alimentés par une pile 9V.
