# PHYS3330 Final Project Code

This is the code that allows the safety box to function. It consists of three parts.

## 1. Potentiometer Password Lock

The potentiometer password setup consists of system of window comparator circuits with outputs combined by Boolean gates.

<img src="/pictures/schematic_1.png" width="400">

Fig. 1: Potentiometer password lock schematic

Window comparators are built with variable resistance values to change password required.

<img src="/pictures/WindowComparatorCircuit.jpg" width="400">

Fig. 2: A single window comparator circuit

Three such window comparator circuits are combined to make the password lock.

<img src="/pictures/PasswordCircuit.jpg" width="400">

Fig. 3: Potentiometer password lock internals

Potentiometers are used for user password input.

<img src="/pictures/PotentiometerPasswordInput.jpg" width="400">

Fig. 4: Password input potentiometers

## 2. Laser Tripwire System

The laser tripwire uses photodiode circuits to check when a laser path is broken.

<img src="/pictures/schematic_2.png" width="400">

Fig. 5: Laser emitter circuit schematic

Three laser diodes are combined in series to create the laser 'cage'.

<img src="/pictures/LaserDiodeEmitterArray.jpg" width="400">

Fig. 6: Laser diode emitters

The diodes are mounted to the entrance of the box.

<img src="/pictures/PhotodiodeReciever.jpg" width="400">

Fig. 7:  Photo diode receiver unit

Photodiode receiver circuits check when the laser path is broken.

## 3. Alarm System

Alarm system is controlled using an Arduino which checks the logic of the electronics circuits.
