/***********************************************************************/
/*                                                                     */
/*  FILE       :ButtonProcess.h                                        */
/*  DATE       :Sep 27th, 2021                                         */
/*  DESCRIPTION:Button Process                                         */
/*                                                                     */
/*  CPU TYPE   :Arduino Due ATmega328P                                 */
/*  AUTHOR     :Luis Angel Cabral                                      */
/*                                                                     */
/*  PROJECT    :Code Example                                           */
/*  IDE        :Arduino IDE 1.8.16                                     */
/*                                                                     */
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
