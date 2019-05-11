/*
 * PROCESS.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: manar
 */

#ifndef PROCESS_H_
#define PROCESS_H_
#include "ACTUATORS.h"
#include "SENSORSREADER.h"
#define TempSaveLevel1 (20)
#define TempSaveLevel2 (24)
#define HumSaveLevel1 (50)
#define HumSaveLevel2 (70)
#define AmoniaSaveLevel1 (20)
#define AmoniaSaveLevel2 (25)
#define CoSaveLevel1 (50)
#define CoSaveLevel2 (100)

void APP_PROCESS_Init(void);
void APP_PROCESS_Process(void);

#endif /* PROCESS_H_ */
