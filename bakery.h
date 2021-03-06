#pragma once

struct Bakery {
    float smallQty, mediumQty, largeQty;
    float   smallHours, smallMinutes, smallTime;
    float   mediumHours, mediumMinutes, mediumTime;
    float   largeHours, largeMinutes, largeTime;
    float   totalHours, totalMinutes, totalTime; 
    enum    pitaSize { small, medium, large, total };

    void    languageSelect();
    void    menu();
    void    calcTrays();
    void    readOrder();
    float   calcPitaTime(float, float, float, float&, float&, float&, float&);
    bool    isOverHour(float, float, float, pitaSize = total);
    void    writeData();
    void    readData();
};
