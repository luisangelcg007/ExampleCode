/***********************************************************************/
/*                                                                     */
/*  FILE       :ExampleCode.ino                                 */
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

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  SR_Button_Init(
    &blueButton,
    blueDigitalPinNumber,
    blueDelayMs);

  SR_Button_Init(
    &greenButton,
    greenDigitalPinNumber,
    greenDelayMs);
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
      digitalWrite(2, LOW);
    } else {
      digitalWrite(2, HIGH);
    }

    if (buttonStateBlue == unpressedButton) {
      digitalWrite(3, LOW);
    } else {
      digitalWrite(3, HIGH);
    }    
  }
}
