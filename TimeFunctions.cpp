// TimeFunctions.cpp
// Author: Eurek Dantley Manfoumbi Ekogha
// CS 210 - Project One: Chada Tech Clocks
//
// Implements the Time struct's supporting functions declared in
// TimeFunctions.h. All logic for validating input, incrementing the
// clock, and displaying the two required clock formats lives here so
// that main() stays as small as possible, per the project rubric.

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include "TimeFunctions.h"

using namespace std;

// Small helper used only within this file to read one bounded integer
// value (e.g., an hour 0-23) and re-prompt until the input is valid.
// Keeping this local (not in the header) means other files don't need
// to know it exists - it is an implementation detail of getInitialTime.
static int getValidatedInt(const string& prompt, int minValue, int maxValue)
{
    int value = 0;

    while (true)
    {
        cout << prompt;
        cin >> value;

        // Guard against non-numeric input (e.g., letters) so the
        // program never crashes or loops forever on bad input.
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a whole number." << endl;
            continue;
        }

        if (value < minValue || value > maxValue)
        {
            cout << "Please enter a value between " << minValue
                 << " and " << maxValue << "." << endl;
            continue;
        }

        // Clear out any leftover characters (like the newline) so the
        // next read starts clean.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

// Gets the starting hour, minute, and second from the user and stores
// them (already validated) in currentTime.
void getInitialTime(Time& currentTime)
{
    cout << "Let's set the initial time." << endl;
    currentTime.hour = getValidatedInt("Enter the hour (0-23): ", 0, 23);
    currentTime.minute = getValidatedInt("Enter the minute (0-59): ", 0, 59);
    currentTime.second = getValidatedInt("Enter the second (0-59): ", 0, 59);
}

// Displays the menu of actions available to the user.
void displayMenu()
{
    cout << "\n----- Chada Tech Clock Menu -----" << endl;
    cout << "1. Add one hour" << endl;
    cout << "2. Add one minute" << endl;
    cout << "3. Add one second" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Adds one hour, wrapping 23 -> 0.
void addHour(Time& currentTime)
{
    currentTime.hour = (currentTime.hour + 1) % 24;
}

// Adds one minute, wrapping 59 -> 0 and rolling into the hour when it does.
void addMinute(Time& currentTime)
{
    currentTime.minute++;

    if (currentTime.minute > 59)
    {
        currentTime.minute = 0;
        addHour(currentTime); // reuse existing wraparound logic
    }
}

// Adds one second, wrapping 59 -> 0 and rolling into the minute when it does.
void addSecond(Time& currentTime)
{
    currentTime.second++;

    if (currentTime.second > 59)
    {
        currentTime.second = 0;
        addMinute(currentTime); // reuse existing wraparound logic
    }
}

// Displays the current time as both a 24-hour clock and a 12-hour
// clock (with AM/PM), satisfying the ISO 8601 requirement that both
// formats be visible to the user at the same time.
void displayTime(const Time& currentTime)
{
    // --- 24-hour clock (no conversion needed; this is the internal format) ---
    cout << "\n24-hour clock: "
         << setfill('0') << setw(2) << currentTime.hour << ":"
         << setfill('0') << setw(2) << currentTime.minute << ":"
         << setfill('0') << setw(2) << currentTime.second << endl;

    // --- 12-hour clock ---
    int displayHour = currentTime.hour % 12;
    if (displayHour == 0)
    {
        displayHour = 12; // 0 and 12 (military) both display as 12 in 12-hour format
    }

    string meridiem = (currentTime.hour < 12) ? "AM" : "PM";

    cout << "12-hour clock: "
         << setfill('0') << setw(2) << displayHour << ":"
         << setfill('0') << setw(2) << currentTime.minute << ":"
         << setfill('0') << setw(2) << currentTime.second
         << " " << meridiem << endl;
}
