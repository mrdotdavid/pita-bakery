#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "bakery.h"
using std::cout;
using std::cin;
using std::endl;

float SMALL_TIME = 4.5;                                 // Contants represent how long, in minutes, 
float MEDIUM_TIME = 3;                               // it takes to fill one tray of that size.
float LARGE_TIME = 3;

float Bakery::calcPitaTime(float smallQty, float mediumQty, float largeQty, 
                            float &smallTime, float &mediumTime, float &largeTime) {
    float smallTrays    = smallQty / 40;                // Calculates how many trays are required
    float mediumTrays   = mediumQty / 30;               // for the given amount of pitas.
    float largeTrays    = largeQty / 25;

    smallTime   = smallTrays * SMALL_TIME;      // Multipply the amount of trays by their
    mediumTime  = mediumTrays * MEDIUM_TIME;    // respective times to get their total time in minutes.
    largeTime   = largeTrays * LARGE_TIME;
    float totalTimeMins = smallTime + mediumTime + largeTime;

    return totalTimeMins;                               // Returning total time in minutes.
}

void Bakery::readOrder() {
    float smallQty, mediumQty, largeQty;
    float smallTime, mediumTime, largeTime;
    float totalHours, totalMinutes, totalTime;

    float smallHours, smallMinutes, 
            mediumHours, mediumMinutes,
                largeHours, largeMinutes;
    

    cout << "How many small pitas? ";                   // Reads in number of orders
    cin >> smallQty;
    cout << "How many medium pitas? ";
    cin >> mediumQty;
    cout << "How many large pitas? ";
    cin >> largeQty;

    // Set totalMinutes equal to calcPitaTiem divided by 60 to get the total amount of hours in decimal form.
    // std::modf will separate our totalMinutes variable into two parts: whole number and fractional.
    // std::modf will help us get, for example, 4 hours and 30 minutes instead of 4.5 hours.
    totalTime = calcPitaTime(smallQty, mediumQty, largeQty, 
                                    smallTime, mediumTime, largeTime) / 60;
    totalMinutes = ((std::modf(totalTime, &totalHours) * 60));

    // if (smallTime > 60) {
    //     smallMinutes = ((std::modf(smallTime, &smallHours) * 60));
    //     cout << "Small order completion: ";
    //     cout << smallHours << " hours and ";
    //     cout << std::fixed << std::setprecision(0) << smallMinutes;
    //     cout << " minutes." << endl;
    // }
    // if (mediumTime > 60) {
    //     mediumMinutes = ((std::modf(mediumTime, &mediumHours) * 60));
    //     cout << "Medium order completion: ";
    //     cout << mediumHours << " hours and ";
    //     cout << std::fixed << std::setprecision(0) << mediumMinutes;
    //     cout << " minutes." << endl;
    // }
    // if (largeTime > 60) {
    //     largeMinutes = ((std::modf(largeTime, &largeHours) * 60));
    //     cout << "Large order completion: ";
    //     cout << largeHours << " hours and ";
    //     cout << std::fixed << std::setprecision(0) << largeMinutes;
    //     cout << " minutes." << endl;
    // }
    
    cout << "Small time completion: ";
    cout << smallTime << " minutes." << endl;
    cout << "Medium time completion: ";
    cout << mediumTime << " minutes." << endl;
    cout << "Large time completion: ";
    cout << largeTime << " minutes." << endl;

    cout << "Total time completion: ";
    cout << totalHours << " hours and ";
    cout << std::fixed << std::setprecision(0) << totalMinutes;
    cout << " minutes." << endl;
}