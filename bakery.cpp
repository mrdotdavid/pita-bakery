#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
#include "bakery.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

float SMALL_TIME = 4.5;             // Contants represent how long, in minutes, 
float MEDIUM_TIME = 2.562;          // it takes to fill one tray of that size.
float LARGE_TIME = 2.365;

void Bakery::menu() {
    int option;

    cout << "1. Calculate total time of orders." << endl;
    cout << "2. Calculate how many trays for one order." << endl;
    cout << "Select your choice: ";
    cin >> option;

    switch (option) {          
        case 1: readOrder();
        break;
        case 2: calcTrays();
        break;
        default: cout << "Pick an option!" << endl;
    }
}

void Bakery::calcTrays() {
    float pitaQty, pitaPerTray, trayQty, trayWholeNum, trayFraction;
    cout << "How many pitas? ";
    cin >> pitaQty;
    cout << "How many per tray? ";
    cin >> pitaPerTray;

    trayQty = pitaQty / pitaPerTray;                                    // Dividing to get how many 
    trayFraction = ((std::modf(trayQty, &trayWholeNum) * pitaPerTray)); // trays we'll fill up.
    cout << trayWholeNum << "x" << pitaPerTray << " trays." << endl;    // Splitting to get the remainding tray

    if (trayFraction != 0) {                                // Check if there is a fraction.
        cout << "1x" << trayFraction << " tray." << endl;   // In the case that there is no fraction,
    }                                                       // i.e. 30 total pitas / 30 pitaPerTray,
}                                                           // will not return a fraction.

void Bakery::readOrder() {
    cout << "How many small pitas? ";                   // Reads in number of orders
    cin >> smallQty;
    cout << "How many medium pitas? ";
    cin >> mediumQty;
    cout << "How many large pitas? ";
    cin >> largeQty;

    // std::modf will separate our totalMinutes variable into two parts: whole number and fractional.
    // It will help us get, for example, 4 hours and 30 minutes instead of 4.5 hours.

    calcPitaTime(smallQty, mediumQty, largeQty, smallTime, mediumTime, largeTime, totalTime);
    isOverHour(smallTime, smallHours, smallMinutes, small);
    isOverHour(mediumTime, mediumHours, mediumMinutes, medium);
    isOverHour(largeTime, largeHours, largeMinutes, large);
    isOverHour(totalTime, totalHours, totalMinutes);
}

float Bakery::calcPitaTime(float smallQty, float mediumQty, float largeQty, 
                            float &smallTime, float &mediumTime, float &largeTime, float &totalTime) {
    float smallTrays  = smallQty / 40;                // Calculates how many trays are required
    float mediumTrays = mediumQty / 30;               // for the given amount of pitas.
    float largeTrays  = largeQty / 25;

    smallTime   = smallTrays * SMALL_TIME;      // Multipply the amount of trays by their
    mediumTime  = mediumTrays * MEDIUM_TIME;    // respective times to get their total time in minutes.
    largeTime   = largeTrays * LARGE_TIME;
    totalTime   = smallTime + mediumTime + largeTime;

    return totalTime;                               // Returning total time in minutes.
}

bool Bakery::isOverHour(float total, float wholeNumber, float fraction, pitaSize pitaSize) {
    string size;
    switch (pitaSize) {
        case small:     size = "Small";
        break;
        case medium:    size = "Medium";
        break;
        case large:     size = "Large";
        break;
        default: size = "Total";
    }
    if (total >= 60.0) {                                // If over 60, split the whole number and fractional part.
        total /= 60;
        fraction = ((std::modf(total, &wholeNumber) * 60));    // Splitting apart whole number to hours variable,
        cout << size << " time completion: ";                  // and fractional part to minutes variable.
        cout << wholeNumber << " hours and ";
        cout << std::fixed << std::setprecision(0) << fraction;
        cout << " minutes." << endl;

        return true;
    } else if (total < 60) {                            // If our total doesn't surpass an hour,
        cout << size << " time completion: ";           // There is no need to split into
        cout << total << " minutes." << endl;           // whole number and fraction.
    }
    return false;
}

void Bakery::writeData() {
    std::ofstream invoice;
    invoice.open("invoice.txt");

    invoice.close();
}

void Bakery::readData() {
    std::ifstream invoice;
    invoice.open("invoice.txt");

    invoice.close();
}
