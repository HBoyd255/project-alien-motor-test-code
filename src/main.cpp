/**
 * @file main.cpp
 * @brief The main file and entry point of the project.
 *
 * @author Harry Boyd - https://github.com/HBoyd255
 * @date 2024-07-29
 * @copyright Copyright (c) 2024
 */

//  ██████╗ ██████╗  ██████╗      ██╗███████╗ ██████╗████████╗
//  ██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝██╔════╝╚══██╔══╝
//  ██████╔╝██████╔╝██║   ██║     ██║█████╗  ██║        ██║
//  ██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝  ██║        ██║
//  ██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗╚██████╗   ██║
//  ╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝
//
//   █████╗    ██╗        ██╗   ███████╗   ███╗   ██╗
//  ██╔══██╗   ██║        ██║   ██╔════╝   ████╗  ██║
//  ███████║   ██║        ██║   █████╗     ██╔██╗ ██║
//  ██╔══██║   ██║        ██║   ██╔══╝     ██║╚██╗██║
//  ██║  ██║██╗███████╗██╗██║██╗███████╗██╗██║ ╚████║██╗
//  ╚═╝  ╚═╝╚═╝╚══════╝╚═╝╚═╝╚═╝╚══════╝╚═╝╚═╝  ╚═══╝╚═╝

// Ascii text generated at https://patorjk.com/software/taag/
// Font used - ANSI Shadow

#include <Arduino.h>

#include "systemInfo.h"

#define TEST_ENCODERS true
#define TEST_MOTORS false

int leftMotorSteps = 0;
int rightMotorSteps = 0;

void leftMotorISR() {
    if (digitalRead(LEFT_MOTOR_ENCODER_A_PIN) !=
        digitalRead(LEFT_MOTOR_ENCODER_B_PIN)) {
        leftMotorSteps++;
    } else {
        leftMotorSteps--;
    }
}

void rightMotorISR() {
    if (digitalRead(RIGHT_MOTOR_ENCODER_A_PIN) !=
        digitalRead(RIGHT_MOTOR_ENCODER_B_PIN)) {
        rightMotorSteps++;
    } else {
        rightMotorSteps--;
    }
}

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    // Setup left motor encoders.
    pinMode(LEFT_MOTOR_ENCODER_A_PIN, INPUT);
    pinMode(LEFT_MOTOR_ENCODER_B_PIN, INPUT);

    // Setup left motor drive.
    pinMode(LEFT_MOTOR_DIRECTION_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_SPEED_PIN, OUTPUT);

    // Setup right motor encoders.
    pinMode(RIGHT_MOTOR_ENCODER_A_PIN, INPUT);
    pinMode(RIGHT_MOTOR_ENCODER_B_PIN, INPUT);

    // Setup right motor drive.
    pinMode(RIGHT_MOTOR_DIRECTION_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_SPEED_PIN, OUTPUT);

    // Attach the interrupt service routines.
    attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER_A_PIN),
                    leftMotorISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER_A_PIN),
                    rightMotorISR, CHANGE);
}

void loop() {
    if (TEST_ENCODERS) {
        // Print the encoder values.
        Serial.print(" ENC1A:");
        Serial.print(digitalRead(LEFT_MOTOR_ENCODER_A_PIN));
        Serial.print(" ENC1B:");
        Serial.print(digitalRead(LEFT_MOTOR_ENCODER_B_PIN));
        Serial.print(" ENC1 Steps:");
        Serial.print(leftMotorSteps);

        Serial.print(" ENC2A:");
        Serial.print(digitalRead(RIGHT_MOTOR_ENCODER_A_PIN));
        Serial.print(" ENC2B:");
        Serial.print(digitalRead(RIGHT_MOTOR_ENCODER_B_PIN));
        Serial.print(" ENC2 Steps:");
        Serial.println(rightMotorSteps);
    }

    if (TEST_MOTORS) {
        // Drive forwards.
        digitalWrite(LEFT_MOTOR_DIRECTION_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_DIRECTION_PIN, HIGH);

        // Ramp up the motor speed.
        for (int i = 0; i < 255; i++) {
            analogWrite(LEFT_MOTOR_SPEED_PIN, i);
            analogWrite(RIGHT_MOTOR_SPEED_PIN, i);
            delay(10);
        }

        delay(1000);

        // Ramp down the motor speed.
        for (int i = 255; i > 0; i--) {
            analogWrite(LEFT_MOTOR_SPEED_PIN, i);
            analogWrite(RIGHT_MOTOR_SPEED_PIN, i);
            delay(10);
        }

        // Drive backwards.
        digitalWrite(LEFT_MOTOR_DIRECTION_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_DIRECTION_PIN, LOW);

        // Ramp up the motor speed.
        for (int i = 0; i < 255; i++) {
            analogWrite(LEFT_MOTOR_SPEED_PIN, i);
            analogWrite(RIGHT_MOTOR_SPEED_PIN, i);
            delay(10);
        }

        delay(1000);

        // Ramp down the motor speed.
        for (int i = 255; i > 0; i--) {
            analogWrite(LEFT_MOTOR_SPEED_PIN, i);
            analogWrite(RIGHT_MOTOR_SPEED_PIN, i);
            delay(10);
        }
    }
}
