#include <Wire.h>
#include <MPU6050.h>
#include "headers/sensor.h"

MPU6050 mpu;

// Check Settings
void checkMPU6050(void)
{
    Serial.println();

    Serial.print(" * Sleep Mode:            ");
    Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");

    // To Get the Clock Source
    Serial.print(" * Clock Source:          ");
    switch (mpu.getClockSource())
    {
    case MPU6050_CLOCK_KEEP_RESET:
        Serial.println("Stops the clock and keeps the timing generator in reset");
        break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ:
        Serial.println("PLL with external 19.2MHz reference");
        break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ:
        Serial.println("PLL with external 32.768kHz reference");
        break;
    case MPU6050_CLOCK_PLL_ZGYRO:
        Serial.println("PLL with Z axis gyroscope reference");
        break;
    case MPU6050_CLOCK_PLL_YGYRO:
        Serial.println("PLL with Y axis gyroscope reference");
        break;
    case MPU6050_CLOCK_PLL_XGYRO:
        Serial.println("PLL with X axis gyroscope reference");
        break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:
        Serial.println("Internal 8MHz oscillator");
        break;
    }

    // ACCELEROMETER
    Serial.print(" * Accelerometer:         ");
    switch (mpu.getRange())
    {
    case MPU6050_RANGE_16G:
        Serial.println("+/- 16 g");
        break;
    case MPU6050_RANGE_8G:
        Serial.println("+/- 8 g");
        break;
    case MPU6050_RANGE_4G:
        Serial.println("+/- 4 g");
        break;
    case MPU6050_RANGE_2G:
        Serial.println("+/- 2 g");
        break;
    }

    Serial.print(" * Accelerometer offsets: ");
    Serial.print(mpu.getAccelOffsetX());
    Serial.print(" / ");
    Serial.print(mpu.getAccelOffsetY());
    Serial.print(" / ");
    Serial.println(mpu.getAccelOffsetZ());

    // GYROSCOPE
    Serial.print(" * Gyroscope:         ");
    switch (mpu.getScale())
    {
    case MPU6050_SCALE_2000DPS:
        Serial.println("2000 dps");
        break;
    case MPU6050_SCALE_1000DPS:
        Serial.println("1000 dps");
        break;
    case MPU6050_SCALE_500DPS:
        Serial.println("500 dps");
        break;
    case MPU6050_SCALE_250DPS:
        Serial.println("250 dps");
        break;
    }

    Serial.print(" * Gyroscope offsets: ");
    Serial.print(mpu.getGyroOffsetX());
    Serial.print(" / ");
    Serial.print(mpu.getGyroOffsetY());
    Serial.print(" / ");
    Serial.println(mpu.getGyroOffsetZ());

    Serial.println();
}

void getAccelValues(void)
{
    Vector normAccel = mpu.readNormalizeAccel();

    Serial.print(" Xnorm = ");
    Serial.print(normAccel.XAxis);
    Serial.print(" Ynorm = ");
    Serial.print(normAccel.YAxis);
    Serial.print(" Znorm = ");
    Serial.println(normAccel.ZAxis);
    delay(150);
}

void getGyroValues(void)
{
    Vector normGyro = mpu.readNormalizeGyro();

    Serial.print(" Xnorm = ");
    Serial.print(normGyro.XAxis);
    Serial.print(" Ynorm = ");
    Serial.print(normGyro.YAxis);
    Serial.print(" Znorm = ");
    Serial.println(normGyro.ZAxis);

    delay(150);
}