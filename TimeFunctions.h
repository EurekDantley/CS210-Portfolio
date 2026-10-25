// TimeFunctions.h
// Author: Eurek Dantley Manfoumbi Ekogha
// CS 210 - Project One: Chada Tech Clocks
//
// Declares the Time struct and all supporting functions used to run
// the dual (12-hour / 24-hour) clock simulation described in the
// Chada Tech Clocks Functional Requirements document.

#ifndef TIMEFUNCTIONS_H
#define TIMEFUNCTIONS_H

// Holds the current simulated time using 24-hour (military) values.
// Keeping a single internal representation avoids having two separate
// clocks fall out of sync with each other.
struct Time
{
    int hour;   // 0-23
    int minute; // 0-59
    int second; // 0-59
};

// Prompts the user for a starting hour, minute, and second and
// validates each value before storing it in the Time struct.
void getInitialTime(Time& currentTime);

// Prints the menu of available actions to the console.
void displayMenu();

// Increases the hour by one, wrapping from 23 back to 0.
void addHour(Time& currentTime);

// Increases the minute by one, wrapping from 59 back to 0.
// Rolling over from 59 to 0 also advances the hour (with its own wrap).
void addMinute(Time& currentTime);

// Increases the second by one, wrapping from 59 back to 0.
// Rolling over from 59 to 0 also advances the minute (and, in turn,
// the hour if the minute itself rolls over).
void addSecond(Time& currentTime);

// Displays the current time simultaneously as a 12-hour clock
// (with AM/PM) and a 24-hour clock, satisfying the ISO 8601
// requirement from Chada Tech.
void displayTime(const Time& currentTime);

#endif // TIMEFUNCTIONS_H
