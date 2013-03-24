/* Arduino I2cMaster Library
 * Copyright (C) 2010 by William Greiman
 *
 * This file is part of the Arduino I2cMaster Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino I2cMaster Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef I2C_MASTER_H
#define I2C_MASTER_H
/**
 * \file
 * \brief Software I2C and hardware TWI library
 */
#if ARDUINO < 100
#include <WProgram.h>
#else  // ARDUINO
#include <Arduino.h>
#endif  // ARDUINO


/** Delay used for software I2C */
uint8_t const I2C_DELAY_USEC = 4;

/** Bit to or with address for read start and read restart */
uint8_t const I2C_READ = 1;

/** Bit to or with address for write start and write restart */
uint8_t const I2C_WRITE = 0;


//------------------------------------------------------------------------------
/**
 * \class SoftI2cMaster
 * \brief Software I2C master class
 */
class SoftI2cMaster {
 public:
  SoftI2cMaster(uint8_t sdaPin, uint8_t sclPin);
  uint8_t read(uint8_t last);
  bool restart(uint8_t addressRW);
  bool start(uint8_t addressRW);
  void stop(void);
  bool write(uint8_t b);
 private:
  uint8_t sdaPin_;
  uint8_t sclPin_;
};
#endif  // I2C_MASTER_H