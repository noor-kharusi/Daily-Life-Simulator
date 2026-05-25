#ifndef STATS_H
#define STATS_H
#include <iostream>
using namespace std;
// Stores and manages the three player stats
class Stats {
private:
    int energy;
    int mood;
    int productivity;
public:
    // Constructor - all stats start at 50
    Stats() {
        energy = 50;
        mood = 50;
        productivity = 50;
    }
    // Getters
    int getEnergy() const { return energy; }
    int getMood() const { return mood; }
    int getProductivity() const { return productivity; }


    // Setters - keep values between 0 and 100
    void setEnergy(int e) {
        if (e > 100) energy = 100;
        else if (e < 0) energy = 0;
        else energy = e;
    }

    void setMood(int m) {
        if (m > 100) mood = 100;
        else if (m < 0) mood = 0;
        else mood = m;
    }

    void setProductivity(int p) {
        if (p > 100) productivity = 100;
        else if (p < 0) productivity = 0;
        else productivity = p;
    }

    // Display current stats
    void display() const {
        cout << "Energy:       " << energy << "%" << endl;
        cout << "Mood:         " << mood << "%" << endl;
        cout << "Productivity: " << productivity << "%" << endl;
    }
};
#endif