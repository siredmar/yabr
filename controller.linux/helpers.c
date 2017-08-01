/*
 * helpers.c
 *
 *  Created on: Mar 31, 2014
 *      Author: armin
 */
#include "helpers.h"

int return_comport(const char *comport)
{
   int retval = 0;

   if (strcmp(comport, "ttyS0") == 0)
      retval = 0;
   else if (strcmp(comport, "ttyS1") == 0)
      retval = 1;
   else if (strcmp(comport, "ttyS2") == 0)
      retval = 2;
   else if (strcmp(comport, "ttyS3") == 0)
      retval = 3;
   else if (strcmp(comport, "ttyS4") == 0)
      retval = 4;
   else if (strcmp(comport, "ttyS5") == 0)
      retval = 5;
   else if (strcmp(comport, "ttyS6") == 0)
      retval = 6;
   else if (strcmp(comport, "ttyS7") == 0)
      retval = 7;
   else if (strcmp(comport, "ttyS8") == 0)
      retval = 8;
   else if (strcmp(comport, "ttyS9") == 0)
      retval = 9;
   else if (strcmp(comport, "ttyS10") == 0)
      retval = 10;
   else if (strcmp(comport, "ttyS11") == 0)
      retval = 11;
   else if (strcmp(comport, "ttyS12") == 0)
      retval = 12;
   else if (strcmp(comport, "ttyS13") == 0)
      retval = 13;
   else if (strcmp(comport, "ttyS14") == 0)
      retval = 14;
   else if (strcmp(comport, "ttyS15") == 0)
      retval = 15;
   else if (strcmp(comport, "ttyUSB0") == 0)
      retval = 16;
   else if (strcmp(comport, "ttyUSB1") == 0)
      retval = 17;
   else if (strcmp(comport, "ttyUSB2") == 0)
      retval = 18;
   else if (strcmp(comport, "ttyUSB3") == 0)
      retval = 19;
   else if (strcmp(comport, "ttyUSB4") == 0)
      retval = 20;
   else if (strcmp(comport, "ttyUSB5") == 0)
      retval = 21;
   else if (strcmp(comport, "ttyAMA0") == 0)
      retval = 22;
   else if (strcmp(comport, "ttyAMA1") == 0)
      retval = 23;
   else if (strcmp(comport, "ttyACM0") == 0)
      retval = 24;
   else if (strcmp(comport, "ttyACM1") == 0)
      retval = 25;
   else if (strcmp(comport, "rfcomm0") == 0)
      retval = 26;
   else if (strcmp(comport, "rfcomm1") == 0)
      retval = 27;
   else if (strcmp(comport, "ircomm0") == 0)
      retval = 28;
   else if (strcmp(comport, "ircomm1") == 0)
      retval = 29;

   return retval;
}

int return_baudrate(const char *baud)
{
   int retval;
   retval = atoi(baud);

   return retval;
}




