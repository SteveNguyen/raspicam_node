//*****************************************************************************
//
// File Name	: 'ivmech.cpp'
// Author	: Steve NGUYEN
// Contact      : steve.nguyen.000@gmail.com
// Created	: jeudi, juin 14 2018
// Revised	:
// Version	:
// Target MCU	:
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
//
// Notes:	notes
//
//*****************************************************************************

#include <wiringPi.h>
#include <wiringPiI2C.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ivmech.h"

static bool cam_pins[4][3]={
  {false, false, true}, //Cam 1 = EPIN=0 F1PIN=0 F2PIN=1
  {true, false, true},
  {false, true, false},
  {true, true, false}
};

static unsigned char cam_bus[4]={I2C_BUS0,I2C_BUS1,I2C_BUS2,I2C_BUS3};

static int i2cdevice=-1;

void ivmech_init()
{
  wiringPiSetup () ;
  pinMode (WIRINGPI_EPIN, OUTPUT) ;
  pinMode (WIRINGPI_F1PIN, OUTPUT) ;
  pinMode (WIRINGPI_F2PIN, OUTPUT) ;

  i2cdevice=wiringPiI2CSetup (0x70); //using /dev/i2c-1 (port I2C1)
  if(i2cdevice==-1)
  {
    printf("ERROR openning i2c device\n");
    return;
  }
  wiringPiI2CWriteReg8 (i2cdevice, I2C_REG, I2C_BUS0) ;
  usleep(50000);
}

void ivmech_change_camera(int cam_id)
{
  if(cam_id>=1 && cam_id<=4)
  {
    wiringPiI2CWriteReg8 (i2cdevice, I2C_REG, cam_bus[cam_id-1]);
    usleep(50000);
    digitalWrite (WIRINGPI_EPIN, cam_pins[cam_id-1][0]);
    digitalWrite (WIRINGPI_F1PIN, cam_pins[cam_id-1][1]);
    digitalWrite (WIRINGPI_F2PIN, cam_pins[cam_id-1][2]);
    printf("I2C DEBUG id:%d bus:%d %d:%d %d:%d %d:%d\n",cam_id, cam_bus[cam_id-1],WIRINGPI_EPIN,cam_pins[cam_id-1][0],WIRINGPI_F1PIN,cam_pins[cam_id-1][1],WIRINGPI_F2PIN,cam_pins[cam_id-1][2]);
  }
  else
    printf("cam_id out of range (%d)\n",cam_id);
}
