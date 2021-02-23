/******************************************************************************/
/***    \file        stats.h
***     \author      Pratik Jaiswal               
***
***     \brief       Header for EventCountColorCode.h
***/       
/*****************************************************************************/

*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#include <stdio.h>
#include <assert.h>
  
 /*=============================================================================
=======                Enums for Color Code                             =======
=============================================================================*/
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};


typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;



