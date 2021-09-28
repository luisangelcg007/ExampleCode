/***********************************************************************/
/*                                                                     */
/*  FILE       :AlarmWithCounterBreathPeriod.h                         */
/*  DATE       :July 6, 2020                                           */
/*  DESCRIPTION:After specific breath period number an alarm is set.   */
/*                                                                     */
/*  CPU TYPE   :Arduino Due AT91SAM3X8E 512K Flash 96K RAM @ 84 MHz    */
/*  AUTHOR     :Hasan Torres                                           */
/*             :Luis Daniel Estrada                                    */
/*             :Luis Fernando Lopez                                    */
/*             :Luis Angel Cabral                                      */
/*                                                                     */
/*  PROJECT    :VENTILATOR for COVID-19 Emergency                      */
/*  IDE        :Arduino IDE 1.8.12                                     */
/*  Compiler   :GCC Ver. 4.8.3-2014q1                                  */
/*                                                                     */
/*  Copyright 2020-2021 Mabe TyP                                       */
/*  All rights reserved                                                */
/*                                                                     */
/***********************************************************************/

#ifndef ALARMWITHCOUNTERBREATHPERIOD_H
#define ALARMWITHCOUNTERBREATHPERIOD_H

#include "Arduino.h"
#include "GlobalDefine.h"

enum buttonStateEnumeration
{
    unpressedButton = 0,
    pressedButton
};

typedef struct 
{
    U8 digitalPinNumber;
    U8 delayMs;
    U8 counterMs;
    buttonStateEnumeration state;
} Button_t;

extern buttonStateEnumeration SR_GetButtonState( Button_t* button );
extern void SR_ButtonProcces( Button_t* button );
extern void SR_Button_Init(
    Button_t* button,
    U8 digitalPinNumber,
    U8 delayMs);

#endif
