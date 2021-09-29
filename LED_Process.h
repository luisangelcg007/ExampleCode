/***********************************************************************/
/*                                                                     */
/*  FILE       :LED_Process.h                                        */
/*  DATE       :Sep 27th, 2021                                         */
/*  DESCRIPTION:LED Process                                         */
/*                                                                     */
/*  CPU TYPE   :Arduino Due ATmega328P                                 */
/*  AUTHOR     :Luis Angel Cabral                                      */
/*                                                                     */
/*  PROJECT    :Code Example                                           */
/*  IDE        :Arduino IDE 1.8.16                                     */
/*                                                                     */
/*                                                                     */
/***********************************************************************/

#ifndef LED_PROCESS_H
#define LED_PROCESS_H

#include "Arduino.h"
#include "GlobalDefine.h"
#include "I_GetAndSetInterface.h"

typedef struct 
{
    I_GetAndSet_t interface;
    U8 digitalPinNumber;
    StateEnumeration state;
} LED_t;

extern void SR_Led_Init(
    LED_t* instance,
    U8 digitalPinNumber);

#endif
