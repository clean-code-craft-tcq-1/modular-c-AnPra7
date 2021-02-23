#ifndef EVENTCOLORCODE_H
#define EVENTCOLORCODE_H

/******************************************************************************/
/***    \file        EventCountColorCode.h
***     \author      Pratik Jaiswal               
***
***     \brief       Header for EventCountColorCode.h
***/       
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#include <stdio.h>
#include <assert.h>
  
 /*=============================================================================
=======                Enums for Color Code                             =======
=============================================================================*/
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

/*=============================================================================
=======                Structure for colors                             =======
=============================================================================*/
typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

/*=============================================================================
=======                constants                                        =======
=============================================================================*/
//const int MAX_COLORPAIR_NAME_CHARS = 16;

/*=============================================================================
=======                      COMMON FUNCTIONS                            =======
=============================================================================*/
void ColorPairToString(const ColorPair* colorPair, char* buffer);
ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(const ColorPair* colorPair);

#endif


