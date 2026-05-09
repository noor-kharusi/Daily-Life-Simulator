#include <iostream>
using namespace std;

// Sleep derived class
class Sleep : public Activity {
public:
    void apply(Stats& stats) override {
        int newEnergy = stats.getEnergy() + 30;

        if (newEnergy > 100)
            newEnergy = 100;

        stats.setEnergy(newEnergy);

        // Mood and productivity unchanged
    }
};

// Exercise derived class
class Exercise : public Activity {
public:
    void apply(Stats& stats) override {
        int newEnergy = stats.getEnergy() - 20;

        if (newEnergy < 0)
            newEnergy = 0;

        stats.setEnergy(newEnergy);

        int newMood = stats.getMood() + 25;

        if (newMood > 100)
            newMood = 100;

        stats.setMood(newMood);

        // Productivity unchanged
    }
};
