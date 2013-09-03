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
