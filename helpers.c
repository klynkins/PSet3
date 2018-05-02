// Helper functions for music
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int num = atoi(&fraction[0]);
    int den = atoi(&fraction[2]);

    switch (den)
    {
        case 8:
            break;
        case 4:
            num = num * 2;
            break;
        case 2:
            num = num * 4;
            break;
    }
    return num;
}

// Calculates frequency (in Hz) of a note
// Take away semitones from A. e.g. C is 9 semitones below A
// If sharp add a semitone, if flat then subtract a semitone
// Add or subtract 12 semitones for every octave above or below A4
//Input semitones into given formula and calculate frequency
int frequency(string note)
{
    float semi = 0.0;
    switch (note[0])
    {

        case 'A' :
        semi = 0.0;
        break;

        case 'B' :
        semi += 2.0;
        break;

        case 'C' :
        semi -= 9.0;
        break;

        case 'D' :
        semi -= 7.0;
        break;

        case 'E' :
        semi-= 5.0;
        break;

        case 'F' :
        semi -= 4.0;
        break;

        case 'G' :
        semi-= 2.0;
        break;
    }

    // Store the number of semitones from A4 in n
    // Adjust the octave number from the Ascii Chart
    float octave = note[strlen(note) - 1] - 48;

    semi += (octave - 4.0) * 12.0;

    float n = note[1];

    if (n == '#')
    {
        semi += 1;
    }

    else if (n == 'b')
    {
        semi -= 1;
    }

    float freq = (pow(2.0, semi / 12.0) * 440.0);

    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    return false;
}

//Good use of comments. Easy to understands
