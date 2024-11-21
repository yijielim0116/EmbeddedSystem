/*
 * main.c
 *
 *  Created on: 2024 Sep 26 15:31:53
 *  Author: YiJie
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t init_status;
  uint32_t elapsed_time;
  int32_t timer_status;



  init_status = DAVE_Init();


  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  timer_status = TIMER_Clear(&TIMER_0);
	  timer_status = TIMER_Start(&TIMER_0);
	  runBlowerSpeedCtrl();
	  DIGITAL_IO_SetOutputLow(&LED_0);
	  runBlowerTest();

	  timer_status = TIMER_Stop(&TIMER_0);

	  elapsed_time = TIMER_GetTime(&TIMER_0);




  }
}
