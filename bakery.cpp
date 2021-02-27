#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "bakery.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

float SMALL_TIME = 4.5;                     // Contants represent how long, in minutes, 
float MEDIUM_TIME = 3.25;                   // it takes to fill one tray of that size.
float LARGE_TIME = 3;

float Bakery::calcSmallPitasTime(float qty) {
    float trays = qty / 40;                 // Calculates how many trays are required
    float smallTime = trays * SMALL_TIME;   // for the given amount of pitas.
    return smallTime;
}

float Bakery::calcMediumPitasTime(float qty) {
    float trays = qty / 30;
    float mediumTime = trays * MEDIUM_TIME; // Multiply the amount of trays by their
    return mediumTime;                      // respective times to get their total time.
}

float Bakery::calcLargePitasTime(float qty) {
    float trays = qty / 25;
    float largeTime = trays * LARGE_TIME;
    return largeTime;                       // Returning total time it takes for that order.
}

void Bakery::calcTotalTime() {
    float smallPitasQty, mediumPitasQty, largePitasQty;
    float hours, seconds, totalTime;

    cout << "How many small pitas? ";       // Reads in number of orders
    cin >> smallPitasQty;
    cout << "How many medium pitas? ";
    cin >> mediumPitasQty;
    cout << "How many large pitas? ";
    cin >> largePitasQty;

    totalTime = (calcSmallPitasTime(smallPitasQty) +
                calcMediumPitasTime(mediumPitasQty) +
                calcLargePitasTime(largePitasQty)) / 60; // Set totalTime to what our functions return.

    seconds = ((std::modf(totalTime, &hours) * 60));     // Separates whole number and fractional part.

    cout << "Total time to complete: ";
    cout << hours << " hours and ";
    cout << std::fixed << std::setprecision(0) << seconds << " seconds.";
}