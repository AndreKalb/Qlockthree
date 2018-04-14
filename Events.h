/**
 * Events.h
 * Instanzierung jährlicher Events
 *
 * @mc       Arduino/UNO
 * @autor    Manuel Bracher / manuel.bracher@gmail.com
 * @version  1.0
 * @created  02.01.15
 *
 * Versionshistorie:
 * V 1.0:  - Erstellt.
 */
#ifndef EVENTS_H
#define EVENTS_H

#include <avr/pgmspace.h>

#include "Event.h"
#include "Colors.h"

/**************************************************************************************************************
* Instanzierung und Initialisierung jährlicher Events. Ein Event enthält eine Laufschrift, gefolgt
* von einem Bildeffekt (Herz, Feuerwerk, etc.). Diese werden am definierten Jahrestag jeweils zur vollen Stunde
* während einer definierten Dauer nonstop angezeigt. Soll nur eine Laufschrift (ohne Bildeffekt) angezeigt werden,
* ist als Effekt-Input NO_EFFECT zu wählen. Soll nur ein Bildeffekt (ohne Laufschrift) gezeigt werden, ist als
* Text-Input "" zu definieren. (Monat, Tag, Text, Effekt, Effektfarbe) Das Event-Array kann "beliebig" ergänzt
* werden.
**************************************************************************************************************/
static const char et00[] PROGMEM = "Happy New Year";
static const char et01[] PROGMEM = "Nils@14";
static const char et02[] PROGMEM = "Bianca@78";
static const char et03[] PROGMEM = "Katrin@78";
static const char et04[] PROGMEM = "Lydia@47";
static const char et05[] PROGMEM = "Georg@47";
static const char et06[] PROGMEM = "Happy Valentine's Day";
static const char et07[] PROGMEM = "Sarah@86";
static const char et08[] PROGMEM = "Basti@86";
static const char et09[] PROGMEM = "Arne@15";
static const char et10[] PROGMEM = "Irmgard@47";     
static const char et11[] PROGMEM = "Lothar@64";      
static const char et12[] PROGMEM = "Monika@60";      
static const char et13[] PROGMEM = "Rita@65";        
static const char et14[] PROGMEM = "Melina@98";      
static const char et15[] PROGMEM = "Harald@71";      
static const char et16[] PROGMEM = "Ole@11";         
static const char et17[] PROGMEM = "Silva&Andre@08"; 
static const char et18[] PROGMEM = "Florian@13";     
static const char et19[] PROGMEM = "Renate@57";      
static const char et20[] PROGMEM = "Sabine@78";      
static const char et21[] PROGMEM = "Andreas@85";     
static const char et22[] PROGMEM = "Silva@87";       
static const char et23[] PROGMEM = "Silva&Andre@12"; 
static const char et24[] PROGMEM = "Helmut@63";      
static const char et25[] PROGMEM = "Ralf@83";        
static const char et26[] PROGMEM = "Heike@66";       
static const char et27[] PROGMEM = "Andreas@75";     
static const char et28[] PROGMEM = "Markus@78";      
static const char et29[] PROGMEM = "Andre@83";       
static const char et30[] PROGMEM = "Heinrich@50";    
static const char et31[] PROGMEM = "Felix@15";       
static const char et32[] PROGMEM = "Vanessa@94";     
static const char et33[] PROGMEM = "Marco@76";       
static const char et34[] PROGMEM = "Merry Christmas";

static const Event e00 PROGMEM = {1,  1,  et00, Effects::EFFECT_FIREWORK,     color_rgb_continuous};
static const Event e01 PROGMEM = {1,  12, et01, Effects::NO_EFFECT,           color_white};
static const Event e02 PROGMEM = {1,  21, et02, Effects::NO_EFFECT,           color_white};
static const Event e03 PROGMEM = {1,  21, et03, Effects::NO_EFFECT,           color_white};
static const Event e04 PROGMEM = {2,   7, et04, Effects::NO_EFFECT,           color_white};
static const Event e05 PROGMEM = {2,  12, et05, Effects::NO_EFFECT,           color_white};
static const Event e06 PROGMEM = {2,  14, et06, Effects::EFFECT_HEART,        color_red};
static const Event e07 PROGMEM = {2,  22, et07, Effects::NO_EFFECT,           color_white};
static const Event e08 PROGMEM = {2,  22, et08, Effects::NO_EFFECT,           color_white};
static const Event e09 PROGMEM = {2,  27, et09, Effects::EFFECT_FIREWORK,     color_darkBlue};
static const Event e10 PROGMEM = {4,   5, et10, Effects::NO_EFFECT,           color_white};
static const Event e11 PROGMEM = {4,   9, et11, Effects::NO_EFFECT,           color_white};
static const Event e12 PROGMEM = {4,  16, et12, Effects::NO_EFFECT,           color_white};
static const Event e13 PROGMEM = {4,  16, et13, Effects::NO_EFFECT,           color_white};
static const Event e14 PROGMEM = {4,  28, et14, Effects::NO_EFFECT,           color_white};
static const Event e15 PROGMEM = {5,  25, et15, Effects::NO_EFFECT,           color_white};
static const Event e16 PROGMEM = {7,   1, et16, Effects::NO_EFFECT,           color_white};
static const Event e17 PROGMEM = {7,   2, et17, Effects::BITMAP_HEART,        color_magenta};
static const Event e18 PROGMEM = {7,  11, et18, Effects::NO_EFFECT,           color_white};
static const Event e19 PROGMEM = {7,  11, et19, Effects::NO_EFFECT,           color_white};
static const Event e20 PROGMEM = {7,  22, et20, Effects::NO_EFFECT,           color_white};
static const Event e21 PROGMEM = {7,  31, et21, Effects::NO_EFFECT,           color_white};
static const Event e22 PROGMEM = {8,  25, et22, Effects::EFFECT_LOVEU,        color_magenta};
static const Event e23 PROGMEM = {8,  25, et23, Effects::BITMAP_WEDDINGRING,  color_magenta};
static const Event e24 PROGMEM = {9,   9, et24, Effects::NO_EFFECT,           color_white};
static const Event e25 PROGMEM = {9,  13, et25, Effects::NO_EFFECT,           color_white};
static const Event e26 PROGMEM = {9,  29, et26, Effects::NO_EFFECT,           color_white};
static const Event e27 PROGMEM = {10,  3, et27, Effects::NO_EFFECT,           color_white};
static const Event e28 PROGMEM = {10, 27, et28, Effects::NO_EFFECT,           color_white};
static const Event e29 PROGMEM = {11, 11, et29, Effects::EFFECT_FIREWORK,     color_red};
static const Event e30 PROGMEM = {11, 19, et30, Effects::NO_EFFECT,           color_white};
static const Event e31 PROGMEM = {11, 19, et31, Effects::NO_EFFECT,           color_white};
static const Event e32 PROGMEM = {11, 29, et32, Effects::NO_EFFECT,           color_white};
static const Event e33 PROGMEM = {12, 20, et33, Effects::NO_EFFECT,           color_white};
static const Event e34 PROGMEM = {12, 24, et34, Effects::EFFECT_CANDLE,       color_orange1};
static const Event e35 PROGMEM = {12, 25, et34, Effects::EFFECT_CANDLE,       color_orange1};
static const Event e36 PROGMEM = {12, 26, et34, Effects::EFFECT_CANDLE,       color_orange1};

const Event * const events[] PROGMEM = {
  &e00, &e01, &e02, &e03, &e04, &e05, &e06, &e07, &e08, &e09, 
  &e10, &e11, &e12, &e13, &e14, &e15, &e16, &e17, &e18, &e19,
  &e20, &e21, &e22, &e23, &e24, &e25, &e26, &e27, &e28, &e29,
  &e30, &e31, &e32, &e33, &e34, &e35, &e36, 
};

//NO_EFFECT = 255,
//EFFECT_FIREWORK = 0,
//EFFECT_HEART,
//EFFECT_CANDLE,
//EFFECT_LOVEU,
//EFFECT_INTRO,
//
//BITMAP_MIN,
//BITMAP_HEART = BITMAP_MIN,
//BITMAP_DOTCIRCLE,
//BITMAP_WEDDINGRING,
//BITMAP_BDPIE,
//BITMAP_CHAMPGLASS1,
//BITMAP_CHAMPGLASS2,
//BITMAP_CHRISTTREE1,
//BITMAP_CHRISTTREE2,
//BITMAP_SMILEY,
//BITMAP_SMILEY_WINK,
//
//ANI_BITMAP_MIN,
//ANI_BITMAP_CHAMPGLASS = ANI_BITMAP_MIN,
//ANI_BITMAP_CHRISTTREE,
//ANI_BITMAP_SMILEY_WINK,


/**************************************************************************************************************
 * Anzahl definierter Events
 **************************************************************************************************************/
namespace EVENT {

int nbrOfEvts = sizeof(events) / sizeof(Event*);

}
#endif // EVENTS_H
