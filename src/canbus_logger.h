/**
 * ecutools: IoT Automotive Tuning, Diagnostics & Analytics
 * Copyright (C) 2014  Jeremy Hahn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CANBUSLOGGER_H
#define CANBUSLOGGER_H

#define CANBUS_LOGTYPE_FILE   (1 << 0)
#define CANBUS_LOGTYPE_AWSIOT (1 << 1)

#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>
#include <syslog.h>
 #include "canbus.h"

typedef struct {
  uint8_t canbus_flags;
  pthread_t canbus_thread;
  struct canbus_filter *filters[10];
  canbus_client *canbus;
  bool isrunning;
  unsigned int type;
  char *logdir;
} canbus_logger;

unsigned int canbus_logger_run(canbus_logger *logger);
unsigned int canbus_logger_stop(canbus_logger *logger);

#endif