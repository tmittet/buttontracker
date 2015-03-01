/************************************************************************/
/* ButtonTracker with Debounce Timer, v1.0.                             */
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

#include "ButtonTracker.h"

ButtonTracker::ButtonTracker(uint16_t debounceTimeoutMs, uint16_t clickTimeoutMs, uint8_t buttonPin)
{
  this->debounceTimeoutMs = debounceTimeoutMs;
  this->clickTimeoutMs = clickTimeoutMs;
  this->buttonPin = buttonPin;
  lastDebounce = millis();

  pinMode(buttonPin, INPUT);
  state = digitalRead(buttonPin);
  previousState = state;
}

void ButtonTracker::update()
{
  //////////////////////////////
  /// Debounce Timer
  //////////////////////////////
  bool stateChanged = 0;
  bool pinState = digitalRead(buttonPin);
  if (previousState != pinState)
  {
    lastDebounce = millis();
  }
  if (millis() - lastDebounce >= debounceTimeoutMs)
  {
    if(state != pinState)
    {
      state = pinState;
      stateChanged = 1;
    }
  }
  previousState = pinState;

  //////////////////////////////
  /// Button Tracker
  //////////////////////////////
  if(state)
  {
    // When button is down
    if(stateChanged)
    {
      down = millis();
      clicks++;
      // Save last clicked
      lastClicked = clicked;
      clicked = millis();
    }
    // When button is being held down
    else if(value < 0)
    {
      return;
    }
  }
  value = 0;
  if(clicks >= 1 && millis() - down > clickTimeoutMs)
  {
    if(state)
    {
      // Button is still down after click timeout, button is being held down
      value = 0 - clicks;
    }
    else
    {
      // Button has been released, return number of clicks
      value = clicks;
    }
    clicks = 0;
  }
}