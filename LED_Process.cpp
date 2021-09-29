/***********************************************************************/
/*                                                                     */
/*  FILE       :LED_Process.cpp                                      */
/*  DATE       :Sep 28th, 2021                                         */
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

#include "LED_Process.h"

/************************************************************************
 Name:          StateEnumeration GetLedState  
 Parameters:    I_GetAndSet_t *_instance: interface to get and set.
 Description:   Return the LED state.
************************************************************************/
static StateEnumeration GetLedState(I_GetAndSet_t *_instance)
{
    LED_t* instance = (LED_t*)_instance;
    return instance->state;
}


/************************************************************************
 Name:          void SetLedState  
 Parameters:    I_GetAndSet_t *_instance: interface to get and set.
 Description:   Return the LED state.
************************************************************************/
static void SetLedState(I_GetAndSet_t *_instance, StateEnumeration state)
{
    LED_t* instance = (LED_t*)_instance;
    instance->state = state;
    digitalWrite(instance->digitalPinNumber, instance->state);
}

static const I_GetAndSet_Api_t api =
   { GetLedState, SetLedState };

/************************************************************************
 Name:          SR_HighPressureAlarmId4_Init
 Parameters:    LED_t* button: Button instance.
                U8 digitalPinNumber: digital pin number on arduino board.
 Description:   Initialices a Button.
************************************************************************/
void SR_Led_Init(
    LED_t* instance,
    U8 digitalPinNumber)
{    
    instance->interface.api = &api;
    instance->digitalPinNumber = digitalPinNumber;
    instance->state = off;

    pinMode(instance->digitalPinNumber, OUTPUT);
}
