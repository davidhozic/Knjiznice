/************************************************************************/
/*							  SETTINGS                                  */
/************************************************************************/
#define  USE_FREERTOS_MALLOC   0	/* If you're using FreeRTOS */
#define  AVR_MODE			   1	/* WARNING! If this option is enabled DO NOT use the clear function unless your list is 1D (avr doesn't support delete()
										so free is used which doesn't call the constructors ergo, does not delete sub elements causing a memory leak) */
/************************************************************************/