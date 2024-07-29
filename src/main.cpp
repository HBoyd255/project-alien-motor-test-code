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

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    // Setup left motor.
    pinMode(LEFT_MOTOR_DIRECTION_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_SPEED_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_ENCODER_A_PIN, INPUT);
    pinMode(LEFT_MOTOR_ENCODER_B_PIN, INPUT);

    // Setup right motor.
    pinMode(RIGHT_MOTOR_DIRECTION_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_SPEED_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_ENCODER_A_PIN, INPUT);
    pinMode(RIGHT_MOTOR_ENCODER_B_PIN, INPUT);
}

void loop() {
    Serial.print(" ENC1A:");
    Serial.print(digitalRead(LEFT_MOTOR_ENCODER_A_PIN));
    Serial.print(" ENC1B:");
    Serial.print(digitalRead(LEFT_MOTOR_ENCODER_B_PIN));
    Serial.print(" ENC2A:");
    Serial.print(digitalRead(RIGHT_MOTOR_ENCODER_A_PIN));
    Serial.print(" ENC2B:");
    Serial.println(digitalRead(RIGHT_MOTOR_ENCODER_B_PIN));
}
