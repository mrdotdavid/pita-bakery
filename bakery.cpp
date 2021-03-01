#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "bakery.h"
using std::cout;
using std::cin;
using std::endl;

float SMALL_TIME = 4.5;                                 // Contants represent how long, in minutes, 
float MEDIUM_TIME = 3.25;                               // it takes to fill one tray of that size.
float LARGE_TIME = 3;

float Bakery::calcPitaTime(float smallQty, float mediumQty, float largeQty) {
    float smallTrays    = smallQty / 40;                // Calculates how many trays are required
    float mediumTrays   = mediumQty / 30;               // for the given amount of pitas.
    float largeTrays    = largeQty / 25;

    float smallTime     = smallTrays * SMALL_TIME;      // Multipply the amount of trays by their
    float mediumTime    = mediumTrays * MEDIUM_TIME;    // respective times to get their total time in minutes.
    float largeTime     = largeTrays * LARGE_TIME;
    float totalTimeMins = smallTime + mediumTime + largeTime;

    return totalTimeMins;                               // Returning total time in minutes.
}

void Bakery::readOrder() {
    float smallQty, mediumQty, largeQty;
    float hours, minutes, totalMinutes;

    cout << "How many small pitas? ";                   // Reads in number of orders
    cin >> smallQty;
    cout << "How many medium pitas? ";
    cin >> mediumQty;
    cout << "How many large pitas? ";
    cin >> largeQty;

    // Set totalMinutes equal to calcPitaTiem divided by 60 to get the total amount of hours in decimal form.
    // std::modf will separate our totalMinutes variable into two parts: whole number and fractional.
    // std::modf will help us get, for example, 4 hours and 30 minutes instead of 4.5 hours.
    totalMinutes = calcPitaTime(smallQty, mediumQty, largeQty) / 60;
    minutes = ((std::modf(totalMinutes, &hours) * 60));

    cout << "Total time to complete: ";
    cout << hours << " hours and ";
    cout << std::fixed << std::setprecision(0) << minutes;
    cout << " minutes." << endl;
}