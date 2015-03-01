/************************************************************************/
/* ButtonTracker test sketch, v1.0.                                     */
/*                                                                      */
/* This library is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* This library is distributed in the hope that it will be useful, but  */
/* WITHOUT ANY WARRANTY; without even the implied warranty of           */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU     */
/* General Public License for more details.                             */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with this library. If not, see <http://www.gnu.org/licenses/>. */
/*                                                                      */
/* Written by Thomas Mittet (code@lookout.no) January 2010.             */
/************************************************************************/

#include <ButtonTracker.h>
// debounceTimeoutMs = 30, clickTimeoutMs = 450, buttonPin = 4
ButtonTracker button1 = ButtonTracker(30, 450, 4);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  button1.update();
  switch(button1.value)
  {
    case -1:
      Serial.println("Button held (down longer than clickTimeoutMs)");
      break;
    case -2:
      Serial.println("Button held and then clicked once");
      break;
    case -3:
      Serial.println("Button held and then clicked twice");
      break;
    case 1:
      Serial.println("Button clicked");
      break;
    case 2:
      Serial.println("Button double-clicked");
      break;
    case 3:
      Serial.println("Button triple-clicked");
      break;
  }
}
