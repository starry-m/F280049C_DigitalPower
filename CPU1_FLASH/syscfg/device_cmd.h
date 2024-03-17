#ifndef DEVICE_CMD_H
#define DEVICE_CMD_H

#include <cpy_tbl.h>


#ifdef CMD0
void CMD0_init();
#endif
#ifdef CMD1
void CMD1_init();
#endif

void CMD_init();

#endif
