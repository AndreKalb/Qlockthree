/**
  Effects.cpp
  Klasse für diverse Effekte

  @mc       Arduino/UNO
  @autor    Manuel Bracher / manuel.bracher@gmail.com
  @version  1.0
  @created  02.01.15

  Versionshistorie:
  V 1.0:  - Erstellt.
*/

#include "Effects.h"
#include "Staben.h"

// #define DEBUG
#include "Debug.h"

void Effects::showTickerString(const char* str2disp, byte tickerSpeed) {
  word matrix [16];

  int strLength = strlen(str2disp);
  long bufLen;
  char actChar;
  char lastChar = 'W';
  int offsetV = 2;
  bool finish = false;
  int i = 0;

  // Diesen Serial print einfach drin lassen! Keine Ahnung weshalb, aber ohne werden die Eventtexte auf mysteriöse Weise manipuliert...
  Serial.print(F("testtest"));

  while (!finish) {
  renderer.clearScreenBuffer(matrix);
    unsigned int shift = 0; // Schiebekorrektur aufgrund variierender Buchstabenbreite
    for (byte k = 0; k < strLength; k++) {
      actChar = str2disp[k];
      if (actChar == ' ') {
        shift += 3;  //bei einem Space eine Lücke von:
      }
      else {
        shift -= pgm_read_byte_near(&(stabenBig[lastChar - '!'][7]));
        for (byte j = 0; j < 7; j++) {
          matrix[offsetV + j] |= (pgm_read_byte_near(&(stabenBig[actChar - '!'][j])) << (1 - shift + i)) & 0b1111111111100000;
        }
        if (k < (strLength - 1)) {
          shift += 6; // Max. Buchstabenbreite + ein Pixel Lücke
        }
        lastChar = actChar;
      }
    }
    writeToBuffer(matrix, 3 * (10 - tickerSpeed));
    bufLen = shift + 15;
    if (i == bufLen) {
      finish = true;
    }
    else {
      i++;
    }
  }
}

/**
   Intro
*/
void Effects::showIntro() {
  word matrix [16];

  renderer.clearScreenBuffer(matrix);
  for (int j = 0; j < 11; j++) {
    for (byte i = 0; i < 10; i++) {
      matrix[i] |= 0b1 << 15 - j;
    }
    writeToBuffer(matrix, 5);
  }
  for (int j = 0; j < 11; j++) {
    for (int i = 0; i < 10; i++) {
      matrix[i] ^= 0b1 << 5 + j;
    }
    writeToBuffer(matrix, 5);
  }
  renderer.clearScreenBuffer(matrix);
  for (int i = 9; i >= 0; i--) {
    matrix[i] |= 0b1111111111100000;
    writeToBuffer(matrix, 5);
  }
  for (int i = 0; i < 10; i++) {
    matrix[i] ^= 0b1111111111100000;
    writeToBuffer(matrix, 5);
  }
}

/**
   Pulsierender Herz-Effekt
*/
void Effects::showHeart(byte duration, eColors color) {
  word matrix [16];
  for ( int y = 0; y < 3; y++) {
    renderer.clearScreenBuffer(matrix);
    for (int j = 0; j < 8; j++) {
      matrix[1 + j] |= (pgm_read_word_near(&(effectMasks[0][j])) << 5);
    }
    writeToBuffer(matrix, 16 * duration, color);
    for ( int i = 0; i < 2; i++) {
      renderer.clearScreenBuffer(matrix);
      for (int z = 0; z < 2; z++) {
        for (int j = 0; j < 8; j++) {
          matrix[1 + j] |= (pgm_read_word_near(&(effectMasks[z][j])) << 5);
        }
        writeToBuffer(matrix, 4 * duration, color);
      }
    }
  }
  renderer.clearScreenBuffer(matrix);
  for (int j = 0; j < 8; j++) {
    matrix[1 + j] |= (pgm_read_word_near(&(effectMasks[0][j])) << 5);
  }
  writeToBuffer(matrix, 14 * duration, color);
}

/**
   Feuerwerk-Effekt
*/
void Effects::showFireWork(byte posX, eColors color) {
  word matrix [16];

  for (int i = 9; i >= 3; i--) {
    renderer.clearScreenBuffer(matrix);
    ledDriver.setPixelInScreenBuffer(posX, i, matrix);
    writeToBuffer(matrix, 7, color);
  }

  for (int i = 8; i <= 10; i++) {
    renderer.clearScreenBuffer(matrix);
    for (int j = 0; j < 10; j++) {
      matrix[j] |= (pgm_read_word_near(&(effectMasks[i][j])) << 10 - posX) & 0b1111111111100000;
    }
    writeToBuffer(matrix, 3 + round(10 * (i - 8) / 3), color);
  }
  for (int i = 0; i <= 10; i++) {
    renderer.clearScreenBuffer(matrix);
    for (int j = 0; j < 10 - i; j++) {
      matrix[j + i] |= (pgm_read_word_near(&(effectMasks[12 + i % 2][j])) << 10 - posX) & 0b1111111111100000;
    }
    writeToBuffer(matrix, 20, color);
  }
}

/**
   Kerzen-Effekt
*/
void Effects::showCandle(eColors color) {
  word matrix [16];
  for (int k = 0; k < 5; k++) {
    for (int j = -4; j < 4; j++) {
      renderer.clearScreenBuffer(matrix);
      for (int i = 5; i < 10; i++) {
        matrix[i] |= (pgm_read_word_near(&(effectMasks[7][i])) << 5);
      }
      for (int i = 0; i < 5; i++) {
        matrix[i] |= (pgm_read_word_near(&(effectMasks[2 + 4 - abs(j % 4)][i])) << 5);
      }
      writeToBuffer(matrix, 10, color);
    }
  }
}

/**
   Love U
*/
void Effects::showLoveU(eColors color) {
  word matrix [16];
  renderer.clearScreenBuffer(matrix);
  for (int i = 0; i < 10; i++) {
    matrix[i] |= (pgm_read_word_near(&(effectMasks[14][i])) << 5);
  }
  writeToBuffer(matrix, 400, color);
}

/**
   Bitmap
*/
void Effects::showBitmap(byte bitmapIdx, byte duration, eColors color) {
  word matrix [16];
  renderer.clearScreenBuffer(matrix);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 11; j++) {
      matrix[i] |= ((pgm_read_word_near(&(bitmaps[bitmapIdx - BITMAP_MIN][j])) >> i) & 0x0001) << 15 - j;
    }
  }
  writeToBuffer(matrix, 15 * duration, color);
}

/**
   Bitmap-Effekt
*/
void Effects::showAnimatedBitmap(byte animatedBitmap, byte duration, eColors color) {
  switch (animatedBitmap) {
    case ANI_BITMAP_CHAMPGLASS:
      for (int i = 0; i < 6; i++) {
        showBitmap(BITMAP_CHAMPGLASS1 + i % 2, duration, color);
      }
      break;
    case ANI_BITMAP_CHRISTTREE:
      for (int i = 0; i < 4; i++) {
        showBitmap(BITMAP_CHRISTTREE1 + i % 2, duration, color);
      }
      break;
    case ANI_BITMAP_SMILEY_WINK:
      showBitmap(BITMAP_SMILEY, 2 * duration, color);
      showBitmap(BITMAP_SMILEY_WINK, duration, color);
      showBitmap(BITMAP_SMILEY, duration, color);
      break;
  }
}

void Effects::writeToBuffer(word aMatrix[], unsigned int aDuration, eColors color)
{
#ifdef RGB_LEDS
  ledDriver.writeScreenBufferToMatrix(aMatrix, true, color);
  delay(aDuration * 14);
#else
  for (int i = 0; i < aDuration; i++) {
    ledDriver.writeScreenBufferToMatrix(aMatrix, true, color);
  }
#endif
}

