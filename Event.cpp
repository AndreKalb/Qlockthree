/**
* Event.cpp
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

#include "Configuration.h"
#include "Event.h"

#define DEBUG
#include "Debug.h"

#define MAX_STR 32

namespace EVENT {

void show(const Event * const e) {
  char txt[MAX_STR+1] = {'0'};

  Effects::eEffects effect = pgm_read_byte_near(&e->_effect);
  eColors color = pgm_read_byte_near(&e->_color);

  strncpy_P(txt, pgm_read_word_near(&e->_txt), MAX_STR);

  DEBUG_PRINT(F("Ticker String: "));
  DEBUG_PRINTLN(txt);
  
  if (strlen(txt) != 0)
    Effects::showTickerString(txt, TICKER_SPEED, settings.getColor());
  if (effect < Effects::BITMAP_MIN) {
    switch (effect)
    {
      case Effects::NO_EFFECT:
        break;
      case Effects::EFFECT_FIREWORK:
        Effects::showFireWork(5, color);
        Effects::showFireWork(2, color);
        Effects::showFireWork(8, color);
        break;
      case Effects::EFFECT_HEART:
        Effects::showHeart(DURATION_ANI_BM, color);
        break;
      case Effects::EFFECT_CANDLE:
        Effects::showCandle(color);
        break;
      default:
        ;
    }
  }
  if ((effect >= Effects::BITMAP_MIN) && (effect < Effects::ANI_BITMAP_MIN)) {
    Effects::showBitmap(effect, DURATION_BM, color);
  }
  if (effect >= Effects::ANI_BITMAP_MIN) {
    Effects::showAnimatedBitmap(effect, DURATION_ANI_BM, color);
  }
}

bool checkDate(const Event * const e, byte actDate, byte actMonth) {
  byte evtDate = pgm_read_byte_near(&e->_date);
  byte evtMonth = pgm_read_byte_near(&e->_month);

  DEBUG_PRINT(F("Check:"));
  DEBUG_PRINT(actDate);
  DEBUG_PRINT(F("="));
  DEBUG_PRINT(evtDate);
  DEBUG_PRINT(F(" "));
  DEBUG_PRINT(actMonth);
  DEBUG_PRINT(F("="));
  DEBUG_PRINTLN(evtMonth);
  
  return ((actDate == evtDate) & (actMonth == evtMonth));
}

}
