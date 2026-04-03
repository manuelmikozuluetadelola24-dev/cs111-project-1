
#ifndef __XOSHIRO256PLUSPLUS_H_

#define __XOSHIRO256PLUSPLUS_H_

#endif

#include <stdint.h>

void seedXoshiro();

uint64_t nextXoshiro(void);

void jump(void);

void long_jump(void);
