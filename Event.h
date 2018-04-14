/**
 * Event.h
 * Klasse für ein jährliches Event
 *
 * @mc       Arduino/UNO
 * @autor    Manuel Bracher / manuel.bracher@gmail.com
 * @version  1.0
 * @created  02.01.15
 *
 * Versionshistorie:
 * V 1.0:  - Erstellt.
 */

#ifndef EVENT_H
#define EVENT_H

#include "Effects.h"
#include "Configuration.h"
#include "Colors.h"
#include "Settings.h"

extern Settings settings;

#define DURATION_BM   15
#define TICKER_SPEED  6

#define DURATION_ANI_BM  (DURATION_BM/5)

struct Event
{
    byte _month;
    byte _date;
    const char* _txt;
    Effects::eEffects _effect;
    eColors _color;
};

namespace EVENT {
  
void show(const Event * const e);
bool checkDate(const Event * const e, byte actDate, byte actMonth);

extern int nbrOfEvts;

}

#endif //EVENT_H
