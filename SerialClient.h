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
 *  along with arduino_serial_client.  If not, see 
 *  <http://www.gnu.org/licenses/>.                                        *
 ***************************************************************************/

#ifndef __SERIAL_CLIENT_H
#define __SERIAL_CLIENT_H
	
#include "Client.h"
#include "IPAddress.h"

class SerialClient : public Client {

public:
  SerialClient();
  SerialClient(int baud);

  virtual int connect(IPAddress ip, uint16_t port);
  virtual int connect(const char *host, uint16_t port);
  virtual size_t write(uint8_t b);
  virtual size_t write(const uint8_t *buf, size_t size);
  virtual int available();
  virtual int read();
  virtual int read(uint8_t *buf, size_t size);
  virtual int peek();
  virtual void flush();
  virtual void stop();
  virtual uint8_t connected();
  virtual operator bool();

protected:
  bool conn_state = false;
};

#endif
