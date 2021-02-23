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
#include <stdio.h>
#include <assert.h>
/*=============================================================================
=======                Enums for Color Code                             =======
=============================================================================*/
enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};
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
const int MAX_COLORPAIR_NAME_CHARS = 16;
int numberOfMinorColors =
    sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

typedef struct {
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;
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
/*---------------------------------------------------------------------------*/
/*           Test for obtaining Pair from number                             *
*//*-------------------------------------------------------------------------*/
void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}
/*---------------------------------------------------------------------------*/
/*           Test for obtaining Pair from number                             *
*//*-------------------------------------------------------------------------*/
void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    return 0;
}
