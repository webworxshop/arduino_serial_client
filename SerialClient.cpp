/***************************************************************************
 *  Copyright 2015 Rob Connolly <rob@webworxshop.com>                      *
 *                                                                         *
 *  This file is part of arduino_serial_client.                            *
 *                                                                         *
 *  arduino_serial_client is free software: you can redistribute it        *
 *  and/or modify it under the terms of the GNU General Public License     *
 *  as published by the Free Software Foundation, either version 3 of      *
 *  the License, or(at your option) any later version.                     *
 *                                                                         *
 *  Smartclock MK2 is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with arduino_serial_client.  If not, see                         *
 *  <http://www.gnu.org/licenses/>.                                        *
 ***************************************************************************/

#include "SerialClient.h"
#include "Arduino.h"

// This is just a thin wrapper around the Serial object for now,
// but it may get more intelligent in future.

SerialClient::SerialClient()
{
    Serial.begin(9600);
}

SerialClient::SerialClient(int baud)
{
    Serial.begin(baud);
}

int SerialClient::connect(IPAddress ip, uint16_t port)
{
    conn_state = true;
    return 1;
}

int SerialClient::connect(const char *host, uint16_t port)
{
    conn_state = true;
    return 1;
}

size_t SerialClient::write(uint8_t b) { Serial.write(b); }
size_t SerialClient::write(const uint8_t *buf, size_t size) 
    { return Serial.write(buf, size); }
int SerialClient::available() { return Serial.available(); }
int SerialClient::read() { return Serial.read(); }
int SerialClient::read(uint8_t *buf, size_t size) 
    { return Serial.readBytes((char*)buf, size); }
int SerialClient::peek() { return Serial.peek(); }
void SerialClient::flush() { return Serial.flush(); }

void SerialClient::stop()
{
    conn_state = false;
}

uint8_t SerialClient::connected() { return conn_state; } 
SerialClient::operator bool() { return true; }

