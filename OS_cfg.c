/*
 * OS_config.c
 *
 *  Created on: Mar 6, 2018
 *      Author: Ahmed
 */
#include "OS_cfg.h"
#include "STD_TYPES.h"
#include "task1.h"
#include "task2.h"
#include "Clock_adjust.h"
#include "taskSwitchLed.h"
#include "sw.h"
#include "KP_int.h"

/* Every 50 periodicity equal to 1 second, TICK = 20ms */
const OS_config_task OS_cfg[] = {{voidTask1, 40}, // Regular CLOCK
									{voidTask2, 2}, //DISPLAY and CHANGE DISPLAY
								{voidClockAdjust, 15},  //Adjust the CLock
								{taskSwitchLed, 1},
								{SW_voidSwTask, 1}};


const u8 u8NumberOfTasks = sizeof(OS_cfg)/sizeof(OS_cfg[0]) ;


