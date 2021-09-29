/***********************************************************************/
/*                                                                     */
/*  FILE       :ExampleCode.ino                                        */
/*  DATE       :Sep 27th, 2021                                         */
/*  DESCRIPTION:Main Arduino routines                                  */
/*                                                                     */
/*  CPU TYPE   :Arduino Due ATmega328P                                 */
/*  AUTHOR     :Luis Angel Cabral                                      */
/*                                                                     */
/*  PROJECT    :Code Example                                           */
/*  IDE        :Arduino IDE 1.8.16                                     */
/*                                                                     */
/*                                                                     */
/***********************************************************************/

#include "I_GetAndSetInterface.h"
#include "LED_Process.h"
#include "ButtonProcess.h"


unsigned long previousMillis = 0;
const long maintTickMs = 10;

U8 buttonStateGreen = 0;
U8 buttonStateBlue = 0;

Button_t blueButton;
U8 blueDigitalPinNumber = 5;
U8 blueDelayMs = (U8)100/maintTickMs;

Button_t greenButton;
U8 greenDigitalPinNumber = 4;
U8 greenDelayMs = (U8)100/maintTickMs;

LED_t blueLED;
U8 blueLEDdigitalPinNumber = 3;

LED_t greenLED;
U8 greenLEDdigitalPinNumber = 2;

void setup() {
  SR_Button_Init(
    &blueButton,
    blueDigitalPinNumber,
    blueDelayMs);

  SR_Button_Init(
    &greenButton,
    greenDigitalPinNumber,
    greenDelayMs);

  SR_Led_Init(
    &blueLED,
    blueLEDdigitalPinNumber);

  SR_Led_Init(
    &greenLED,
    greenLEDdigitalPinNumber);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= maintTickMs) 
  {
    previousMillis = currentMillis;

    //Proccess
    SR_ButtonProcces( &greenButton );
    SR_ButtonProcces( &blueButton );

    //Refresh Output
    buttonStateGreen = SR_GetButtonState( &greenButton );
    buttonStateBlue = SR_GetButtonState( &blueButton );

    if ( buttonStateGreen == unpressedButton) {
      greenLED.interface.api->SetState(&greenLED.interface, off);
    } else {
      greenLED.interface.api->SetState(&greenLED.interface, on);
    }

    if (buttonStateBlue == unpressedButton) {
      blueLED.interface.api->SetState(&blueLED.interface, off);
    } else {
      blueLED.interface.api->SetState(&blueLED.interface, on);
    }    
  }
}
