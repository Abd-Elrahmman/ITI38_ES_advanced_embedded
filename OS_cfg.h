/*
 * OS_cfg.h
 *
 *  Created on: Mar 6, 2018
 *      Author: Ahmed
 */

#ifndef _OS_CFG_H
#define _OS_CFG_H
#include "STD_TYPES.h"

typedef struct{
	void(*pfTask)(void);
	u16 u16Periodicity;
}OS_config_task;

extern const OS_config_task OS_cfg[];

extern const u8 u8NumberOfTasks;

#endif /* OS_CFG_H_ */
