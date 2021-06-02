
#ifndef CASTIMER_H
#define CASTIMER_H



/*********************************************	SETTINGS	*************************************************/
#define SOURCE_INTERUPT								( 1 )			// Use ISR as timing source
	#define TIMER_ISR_VECTOR						( TIMER3_COMPA_vect )	
	#define TIMER_INCREMENT_VALUE_MS				( 1 )

#define SOURCE_SYSTEM_TIME							( 0 )			// Use System time as source
#if (SOURCE_SYSTEM_TIME == 1)
	#include "path_to_system_time_function_prototype"	
	#define SYSTEM_TIME_FUNCTION				   	(  some_function_call()	 )
#endif
/************************************************************************************************************/

/**											USAGE INSTRUCTIONS 											   **/
/************************************************************************************************************/
/* NOTE! The function hook functionality is only available in interrupt mode */
/*
 - To create a timer simply write class_TIMER TIMER_NAME = class_TIMER(function_hook, call period, function parameter) 
  NOTE: If you want the timer to run like a normal timer, simply set function_hook to NULL

- To get the timer value type TIMER_NAME.value()
- To reset the timer simply type TIMER_NAME.reset()
*/																		
/************************************************************************************************************/


#if (	SOURCE_INTERUPT == 1	)	
	#ifndef SEZNAM_INC
	#include "povezan_seznam.hh"
	#endif	
	#include <avr/interrupt.h>
#endif

class class_TIMER
{
private:
	bool timer_enabled = false;
	uint32_t timer_value = 0;

	/* Hook Function */
	void (*function_ptr)(void*) = NULL;
	uint32_t function_call_period = 0;
	void *function_parameter = NULL;
	
public:
    uint32_t vrednost();
    void ponastavi();
	void increment();

	class_TIMER(void (*function_hook)(void *), uint32_t function_call_period, void* function_parameter);
	#if (SOURCE_INTERUPT == 1)
		static Vozlisce_t <class_TIMER *> timer_list;
	#endif
};


/****************************************************************************************************************/
/*												LANGUAGE RENAMES 												*/

	#define	value()								  	vrednost()	
	#define	reset()								   	ponastavi()	

/****************************************************************************************************************/

#endif






