//*****************************************************************************
//
// File Name	: 'ivmech.h'
// Author	: Steve NGUYEN
// Contact      : steve.nguyen.000@gmail.com
// Created	: mardi, juin 26 2018
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

#if !defined(IVMECH_H)
#define IVMECH_H

//GPIO BOARD PIN
#define BOARD_F1PIN 11
#define BOARD_F2PIN 12
#define BOARD_EPIN 7

#define WIRINGPI_F1PIN 0
#define WIRINGPI_F2PIN 1
#define WIRINGPI_EPIN 7


#define I2C_ADDR (0x70)
#define I2C_REG (0x00)

#define I2C_BUS0 (0x01)
#define I2C_BUS1 (0x02)
#define I2C_BUS2 (0x04)
#define I2C_BUS3 (0x08)

void ivmech_init();
void ivmech_change_camera(int cam_id);

#endif
