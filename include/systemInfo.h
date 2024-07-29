/**
 * @file systemInfo.h
 * @brief Definition for constant values related to the hardware setup for the
 * motors.
 *
 * @author Harry Boyd - https://github.com/HBoyd255
 * @date 2024-07-29
 * @copyright Copyright (c) 2024
 */

#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

// Serial
#define SERIAL_BAUD_RATE 230400

// Motors
// Left (Motor 1)
#define LEFT_MOTOR_DIRECTION_PIN A0
#define LEFT_MOTOR_SPEED_PIN D9
#define LEFT_MOTOR_ENCODER_A_PIN D2
#define LEFT_MOTOR_ENCODER_B_PIN D4

// Right (Motor 2)
#define RIGHT_MOTOR_DIRECTION_PIN A1
#define RIGHT_MOTOR_SPEED_PIN D10
#define RIGHT_MOTOR_ENCODER_A_PIN D3
#define RIGHT_MOTOR_ENCODER_B_PIN A7

#endif  // SYSTEM_INFO_H