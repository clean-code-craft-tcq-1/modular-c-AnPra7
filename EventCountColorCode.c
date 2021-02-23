/******************************************************************************/
/***    \file        EventCountColorCode.c
***     \author      Pratik Jaiswal                 
***
***     \brief       Source file 
***/       
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#include "EventCountColorCode.h"

/*=======================================================================================================
 *  char* MajorColorNames[] : array of pointers to CONSTANT strings which has the major colors          *  
 *  char* MinorColorNames[] : array of pointers to CONSTANT strings which has the minor colors          *
 *  numberOfMajorColors,numberOfMinorColors : size of the array MajorColorNames & MinorColorNames       *  
 *  ColorPair : Structure for defining Major and minor color pairs                                      *
 *  majorColor & minorColor : enum members of structure  ColorPair                                      *                           
========================================================================================================*/

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};
int numberOfMajorColors =
    sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

/*=============================================================================
=======                            Functions                            =======
===============================================================================*/

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    ColorPairToString
 */
/*!    \brief       prints the value of the major and minor color
 *
 *     \param       colorPair,buffer
 *     \returns     void
 *
*//*------------------------------------------------------------------------*/
void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}
/*---------------------------------------------------------------------------*/
/*     FUNCTION:    GetColorFromPairNumber
 */
/*!    \brief       returns the colorpair from the pair number
 *
 *     \param       pairNumber
 *     \returns     void
 *
*//*------------------------------------------------------------------------*/
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}
/*---------------------------------------------------------------------------*/
/*     FUNCTION:    GetPairNumberFromColor
 */
/*!    \brief       returns the pair number
 *
 *     \param       colorPair
 *     \returns     int
 *
*//*------------------------------------------------------------------------*/
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

