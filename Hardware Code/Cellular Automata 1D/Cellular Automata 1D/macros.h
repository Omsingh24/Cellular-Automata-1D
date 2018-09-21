/*
 * macros.h
 *
 * Created: 12-Sep-18 5:20:43 PM
 *  Author: Om
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define BIT(x) (0x01 << (x))
#define SETBIT(ADDRESS, BITNUM) ((ADDRESS) |= BIT(BITNUM))
#define CLEARBIT(ADDRESS, BITNUM) ((ADDRESS) &= ~BIT(BITNUM))
#define FLIPBIT(ADDRESS, BITNUM) ((ADDRESS) ^= BIT(BITNUM))
#define CHECKBIT(ADDRESS, BITNUM) ((ADDRESS)&BIT(BITNUM))


#endif /* MACROS_H_ */