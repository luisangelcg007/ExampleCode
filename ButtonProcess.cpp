/***********************************************************************/
/*                                                                     */
/*  FILE       :ButtonProcess.cpp                                      */
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

#include "ButtonProcess.h"

/************************************************************************
 Name:          void SR_GetButtonState  
 Parameters:    Button_t* button: Button instance.
 Description:   Return the button state.
************************************************************************/
buttonStateEnumeration SR_GetButtonState( Button_t* button )
{
    return button->state;
}

/************************************************************************
 Name:          SR_ButtonProcces
 Parameters:    Button_t* button: Button instance.
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
                button->_private.counterMs--;

                if(button->_private.counterMs == 0)
                {
                    button->state = pressedButton;
                    button->_private.counterMs = button->delayMs;
                }
            }
            else
            {
                button->_private.counterMs = button->delayMs;
            }

            break;
        case pressedButton:
            if(localButtonState == LOW)
            {
                button->_private.counterMs--;

                if(button->_private.counterMs == 0)
                {
                    button->state = unpressedButton;
                    button->_private.counterMs = button->delayMs;
                }
            }
            else
            {
                button->_private.counterMs = button->delayMs;
            }
            break;
        default:
            button->state = unpressedButton;
            button->_private.counterMs = button->delayMs;
            break;
    }
}

/************************************************************************
 Name:          SR_HighPressureAlarmId4_Init
 Parameters:    Button_t* button: Button instance.
                U8 digitalPinNumber: digital pin number on arduino board.
                U8 delayMs: time delay to determine the buton state.
 Description:   Initialices a Button.
************************************************************************/
void SR_Button_Init(
    Button_t* button,
    U8 digitalPinNumber,
    U8 delayMs)
{    
    button->digitalPinNumber = digitalPinNumber;
    button->delayMs = delayMs;
    button->_private.counterMs = delayMs;
    button->state = unpressedButton;

    pinMode(button->digitalPinNumber, INPUT);
}
