#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "bakery.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void Bakery::start() {
    calcTotalTime();
}

float Bakery::calcSmallPitasTime(float qty) {
    float trays = qty / 40;
    float smallTime = trays * 4.5;
    return smallTime;
}

float Bakery::calcMediumPitasTime(float qty) {
    float trays = qty / 30;
    float mediumTime = trays * 3.25;
    return mediumTime;
}

float Bakery::calcLargePitasTime(float qty) {
    float trays = qty / 25;
    float largeTime = trays * 3;
    return largeTime;
}

void Bakery::calcTotalTime() {
    float smallPitasQty, mediumPitasQty, largePitasQty, totalTime;
    float hours, seconds;

    cout << "How many small pitas? ";
    cin >> smallPitasQty;
    cout << "How many medium pitas? ";
    cin >> mediumPitasQty;
    cout << "How many large pitas? ";
    cin >> largePitasQty;

    totalTime = (calcSmallPitasTime(smallPitasQty) +
                calcMediumPitasTime(mediumPitasQty) +
                calcLargePitasTime(largePitasQty)) / 60;

    hours = totalTime;
    seconds = ((std::modf(totalTime, &hours) * 60));

    cout << "Total time to complete: ";
    cout << std::fixed << std::setprecision(0) << hours << " hours and ";
    cout << std::setw(2) << std::setfill('0') << seconds << " seconds.";
}