/***********************************************************************/
/*                                                                     */
/*  FILE       :AlarmWithCounterBreathPeriod.cpp                       */
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

#include "ButtonProcess.h"

/************************************************************************
 Name:          void SR_GetButtonState  
 Parameters:    Button_t* button: Button instance.
 Returns:       None
 Called by:     None
 Calls:         None
 Description:   Return the button state.
************************************************************************/
buttonStateEnumeration SR_GetButtonState( Button_t* button )
{
    return button->state;
}

/************************************************************************
 Name:          SR_ButtonProcces
 Parameters:    Button_t* button: Button instance.
 Returns:       None
 Called by:     None
 Calls:         digitalRead()
 Description:   Monitor the button digital pin to deternmine the button state.
************************************************************************/
void SR_ButtonProcces( Button_t* button )
{
    U8 localButtonState;

    localButtonState = digitalRead(button->digitalPinNumber);

    switch( button->state )
    {
        case unpressedButton:
            if(localButtonState == HIGH)
            {
                button->counterMs--;

                if(button->counterMs == 0)
                {
                    button->state = pressedButton;
                    button->counterMs = button->delayMs;
                }
            }
            else
            {
                button->counterMs = button->delayMs;
            }

            break;
        case pressedButton:
            if(localButtonState == LOW)
            {
                button->counterMs--;

                if(button->counterMs == 0)
                {
                    button->state = unpressedButton;
                    button->counterMs = button->delayMs;
                }
            }
            else
            {
                button->counterMs = button->delayMs;
            }
            break;
        default:
            button->state = unpressedButton;
            button->counterMs = button->delayMs;
            break;
    }
}

/************************************************************************
 Name:          SR_HighPressureAlarmId4_Init
 Parameters:    Button_t* button: Button instance.
                U8 digitalPinNumber: digital pin number on arduino board.
                U8 delayMs: time delay to determine the buton state.
 Returns:       None
 Called by:     None
 Calls:         None
 Description:   Initialices a Button.
************************************************************************/
void SR_Button_Init(
    Button_t* button,
    U8 digitalPinNumber,
    U8 delayMs)
{    
    button->digitalPinNumber = digitalPinNumber;
    button->delayMs = delayMs;
    button->counterMs = delayMs;
    button->state = unpressedButton;

    pinMode(button->digitalPinNumber, OUTPUT);
}
