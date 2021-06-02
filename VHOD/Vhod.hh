
#ifndef VHOD_H
#define	VHOD_H

#include <stdint.h>
#include "avr/io.h"

/************************************************************/
					/*		 SETTINGS		*/
					
#define FILTER_TIME_MS									15
#define USE_FILTERING									1
/************************************************************/


#if (USE_FILTERING == 1)
	#ifndef CASTIMER_H
	#error "LITL: FILTERING of input requeres the timer library, please include it thru #include \"castimer.h\""
	#endif
#endif





class class_VHOD // pin, port, stanje ko ni pritisnjen
{
private:
	uint8_t filtered_curr_state		:	1;
	uint8_t unfiltered_curr_state	:	1;	
	uint8_t prev_state				:	1;
	uint8_t rising_edge_var			:	1;
	uint8_t falling_edge_var		:	1;
	uint8_t default_state			:	1;
	uint8_t first_read				:	1;
    
	uint8_t pin;
    char port;

#if (USE_FILTERING == 1)
	class_TIMER filter_timer = class_TIMER(NULL, 0, NULL);
#endif

public:
    bool value();
    bool risingEdge();
    bool fallingEdge();

	class_VHOD(uint8_t pin, char port, char default_state);
};

#define readBIT(reg, bit)				(		(	(reg >> bit) & 0x1	)												)
#define writeBIT(reg, bit, val)			(		(reg = val ? ( reg | (0x1 << bit) ) : ( reg  &  ~(0x1 << bit)))			)


#endif


