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

#ifndef ButtonTracker_h
#define ButtonTracker_h

#include "Arduino.h"

class ButtonTracker
{

public:
  ButtonTracker(uint16_t debounceTimeoutMs, uint16_t clickTimeoutMs, uint8_t buttonPin);
  void update();
  int8_t value;
  unsigned long clicked, lastClicked;
  
private:
  uint16_t debounceTimeoutMs, clickTimeoutMs;
  uint32_t lastDebounce, down;
  uint8_t buttonPin, clicks;
  bool state, previousState;
};

#endif