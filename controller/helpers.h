/*
 * helpers.h
 *
 *  Created on: Mar 31, 2014
 *      Author: armin
 */

#ifndef HELPERS_H_
#define HELPERS_H_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


int return_comport(const char *comport);
int return_baudrate(const char *baud);
char charToNibble(char c);
unsigned char *hexStringToBytes(char *inhex);
unsigned char fileExists(char *fname);

#endif /* HELPERS_H_ */
