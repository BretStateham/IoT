// Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.  
// Licensed under the BSD 2-Clause License.  
// See License.txt in the project root for license information.

#pragma once

#define MIN_PULSE_WIDTH 544
#define MAX_PULSE_WIDTH 2400
#define DEFAULT_PULSE_WIDTH 1500
#define REFRESH_INTERVAL 20000

#define MAX_SERVOS 16


class Servo
{
    uint8_t _servoIndex;
    int _min;
    int _max;
public:
    Servo();
    uint8_t attach(int pin);
    uint8_t attach(int pin, int min, int max);
    void detach();
    void write(int value);
    void writeMicroseconds(int value);
    int read();
    int readMicroseconds();
    bool attached();

};