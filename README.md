# Chada Tech Clocks (CS 210 Project One)

**Author:** Eurek Dantley Manfoumbi Ekogha

A C++ console application that displays a 12-hour and a 24-hour clock at the same time and lets the user advance the time through a menu. The project files are `main.cpp`, `TimeFunctions.h`, and `TimeFunctions.cpp`.

## Summarize the project and what problem it was solving.

Chada Tech has domestic and international clients, and to meet the ISO 8601 standard it wanted a clock that shows both a 12-hour and a 24-hour format instead of only the standard 12-hour clock. This program asks the user for an initial time, then shows a menu to add one hour, one minute, or one second, or to exit. After every change, both clocks are displayed together. It is a simulation, so it does not run in real time. It follows the flowchart provided with the assignment: get the initial time, display the menu, update the time, display the time, and repeat until the user exits.

## What did you do particularly well?

I kept a single internal `Time` struct in 24-hour format and derived the 12-hour display from it each time. This means the two clocks can never get out of sync, and I only had to write the update logic once. I also kept `main()` very small. It only controls the menu loop, and all the real work lives in functions such as `getInitialTime`, `addHour`, `addMinute`, `addSecond`, and `displayTime`. The rollover logic reuses itself: `addSecond` calls `addMinute`, which calls `addHour`, so a time like 23:59:59 correctly wraps to 00:00:00. The initial time input is validated so letters or out-of-range numbers are rejected and the user is asked again.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

The biggest improvement is validating the menu choice in `main()`. The initial time input is validated, but the menu selection is read with a plain `cin >> choice`, so a non-numeric entry could put the program into a repeating loop. Reusing the same validated-input approach there would make the program more secure and more robust. I could also move the time logic into a `Clock` class with private data members and public methods, which would give better encapsulation and make it easier to extend, for example by adding a "subtract time" option. Finally, I could add automated tests for the rollover cases (midnight, noon, 59 minutes, 59 seconds) so changes are less likely to break working behavior.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The trickiest parts were the rollover logic and the 12-hour conversion. Hour 0 has to display as 12 AM and hour 12 as 12 PM, which is easy to get wrong. I handled this by testing the edge cases directly (starting at 23:58:58 and at 00:00:00) and checking the output against what a real clock would show. Input validation was also tricky because bad input can leave characters in the input buffer, so I had to clear the error state and ignore the leftover input. I used the project flowchart and rubric as a checklist, compiled with warnings turned on (`-Wall -Wextra`) to catch mistakes early, and used an AI assistant to help me review my work. I am adding the compiler warning flags, the flowchart-first approach, and edge-case testing to my support network, along with the course materials and instructor feedback.

## What skills from this project will be particularly transferable to other projects or course work?

Breaking a problem into small functions is useful in every project. Reading a flowchart and turning it into code transfers to any design-first assignment. Input validation and defensive programming apply to any program that takes user input. Testing boundary conditions (the edge cases at the start and end of a range) is something I will use constantly. Working with multiple files, a header for declarations and a source file for implementations, is standard in larger C++ projects.

## How did you make this program maintainable, readable, and adaptable?

Every function has a short comment explaining what it does, and the code uses clear names such as `addMinute`, `currentTime`, and `displayHour`. The header file documents the public interface in one place. Because each task is its own function, a change such as a new menu option or a different display format only touches one small area. The single `Time` struct makes the program easy to adapt, since anything that needs the time reads from one source. Passing the time by reference (or `const` reference when it should not change) makes it clear which functions modify data and which only read it.
