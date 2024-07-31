# Project Alien Motor Test Code

<!-- Harry Boyd - 29/07/2024 - github.com/hboyd255 -->

This repository contains code that allows me to test the motors and encoders of
the Project A.L.I.E.N. robot.

The microcontroller used is the Arduino nano 33 BLE, as per the spec of the
university project that this spun from.

The motors are "Micro Metal Gearmotor with Encoder (MMME) – 50:1 Regular",
availible at
[pimoroni.com](https://shop.pimoroni.com/products/micro-metal-gearmotor-with-micro-metal-motor-encoder).

The wheels are "Narrow Moon Buggy Wheels - Pair", availible at
[thepihut.com](https://thepihut.com/products/narrow-moon-buggy-wheels-pair).

The motor driver is the "DFRobot DC Motor Driver", availible at
[thepihut.com](https://thepihut.com/products/fermion-tb6612fng-2x1-2a-dc-motor-driver).

## Breadboard Layout

This is the way that I set the hardware up on a breadboard.

![Two motors set up on a breadboard](/photos/Breadboard.jpg)

## Notes

### Encoder Distance

One rotation of the wheels counts for 300 encoder ticks, so with a wheel
diameter of 47 mm, the circumference is 147.7 mm. This means that 300 encoder
ticks is 147.7 mm, so 1 encoder tick is 0.4923 mm.

### Motor Direction

Please keep in mind that the "DFRobot DC Motor Driver" inverts the direction of
motor 2. This is because the "Direction" doesn't refer to the rotational
direction of the motor, but the direction that the motor will drive, assuming
that the motors are mounted on opposite sides of the robot. This can be seen in
the
[schematic](https://dfimg.dfrobot.com/nobody/wiki/dd70bd9131bdf504736e6debdee835fe.pdf),
where BO1 and BO2 are swapped.
