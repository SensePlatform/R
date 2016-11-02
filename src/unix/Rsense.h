/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 2006-2014  The R Core Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  https://www.R-project.org/Licenses/
 */
 
/*
 * Added by Anand Patil (anand@cloudera.com), 6 Jan 2015.
 */

#include <R_ext/RStartup.h>
#include "Runix.h"

int  Rsense_ReadConsole(const char *prompt, unsigned char *buf, int len, int addtohistory) {
  char* prompt_;
  int out;
  prompt_ = (char*) malloc(sizeof(int) * (22 + 20 + strlen(prompt)));
  strcpy(prompt_, "SENSE_READ_START_2BjhQ"); // 22 characters
  strcat(prompt_, prompt); // up to 256 characters
  strcat(prompt_, "SENSE_READ_END_2BjhQ"); // 20 characters
  out = Rstd_ReadConsole(prompt_, buf, len, addtohistory);
  free(prompt_);
  return out;
}

void Rsense_WriteConsoleEx(const char *buf, int len, int otype) {
  // char* buf_;
  // int outlen;
  // if (otype) {
  //   // Not all errors written to stderr.
  //   outlen = len + 21 + 23;
  //   buf_ = (char*) malloc(sizeof(int) * outlen);
  //   strcpy(buf_, "SENSE_ERROR_START_2JvPi"); // 23 characters
  //   strcat(buf_, buf);
  //   strcat(buf_, "SENSE_ERROR_END_2JvPi"); // 21 characters
  //   Rstd_WriteConsole(buf_, outlen);
  //   free(buf_);
  // } else {
    // Default is stdout.
    Rstd_WriteConsole(buf, len);
  // }
}
