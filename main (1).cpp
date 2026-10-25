// main.cpp
// Author: Eurek Dantley Manfoumbi Ekogha
// CS 210 - Project One: Chada Tech Clocks
//
// Drives the dual-clock simulation. Per the assignment requirements,
// main() contains only high-level control flow; all real logic lives
// in the functions declared in TimeFunctions.h / defined in
// TimeFunctions.cpp.

#include <iostream>
#include "TimeFunctions.h"

using namespace std;

int main()
{
    Time currentTime{ 0, 0, 0 }; // internal time always stored as 24-hour
    int choice = 0;
    bool exitProgram = false;

    // Step 1: Get the user's starting time.
    getInitialTime(currentTime);

    // Step 2: Loop showing the menu until the user chooses to exit.
    while (!exitProgram)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addHour(currentTime);
            displayTime(currentTime);
            break;
        case 2:
            addMinute(currentTime);
            displayTime(currentTime);
            break;
        case 3:
            addSecond(currentTime);
            displayTime(currentTime);
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            exitProgram = true;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, 3, or 4." << endl;
            break;
        }
    }

    return 0;
}
