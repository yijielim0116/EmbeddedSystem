/*
 * BlowerTest.c
 *
 *  Created on: Sep 26, 2024
 *      Author: YiJie
 */

#include "BlowerTest.h"
#include "DAVE.h"

void runBlowerTest(void)
{
	static uint8_t simBlowerSpeedCmd;
	static uint8_t simRightTempCmd;
	static uint8_t simLeftTempCmd;


	uint32_t elapsed_time;
	int32_t timer_status;


	int32_t CANstatus;
	uint8_t can_data_arr[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	timer_status = TIMER_Clear(&TIMER_0);
	timer_status = TIMER_Start(&TIMER_0);

	can_data_arr[6] = simBlowerSpeedCmd & 0x0F;
	can_data_arr[4] = simLeftTempCmd & 0x3F;
	can_data_arr[5] = simRightTempCmd & 0x3F;

	CANstatus = CAN_NODE_MO_UpdateData(&TestNode_LMO_01_Config, can_data_arr);

	if(CANstatus == CAN_NODE_STATUS_SUCCESS){
		CAN_NODE_MO_Transmit(&TestNode_LMO_01_Config);
	}

	timer_status = TIMER_Stop(&TIMER_0);
	elapsed_time = TIMER_GetTime(&TIMER_0);

}


