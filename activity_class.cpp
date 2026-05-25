//
// Created by lubna on 5/12/2026.
//

#include <iostream>
#include <string>

using namespace std;

class activity {
protected:
    string name;

public:
    // constructor
    activity(string n) {
        name = n;
    }

    // pure virtual function
    virtual void apply(int &energy, int &mood,
                       int &productivity,
                       int &stress,
                       int &health) = 0;

    void showname() {
        cout << "activity: " << name << endl;
    }
};

// study class
class study : public activity {
public:
    study() : activity("study") {
    }

    void apply(int &energy, int &mood,
               int &productivity,
               int &stress,
               int &health) {

        cout << "you studied today" << endl;

        productivity += 5;
        stress += 7;
        energy -= 10;
        mood -= 2;
    }
};

// sleep class
class sleep : public activity {
public:
    sleep() : activity("sleep") {
    }

    void apply(int &energy, int &mood,
               int &productivity,
               int &stress,
               int &health) {

        cout << "you slept well today" << endl;

        energy += 20;
        mood += 5;
        stress -= 5;
        health += 5;
    }
};

int main() {

    // stats
    int energy = 100;
    int mood = 100;
    int productivity = 100;
    int stress = 0;
    int health = 100;

    // objects
    study s;
    sleep sl;

    // study activity
    s.showname();
    s.apply(energy, mood, productivity, stress, health);

    cout << endl;

    // sleep activity
    sl.showname();
    sl.apply(energy, mood, productivity, stress, health);

    cout << endl;

    // final stats
    cout << "final stats:" << endl;

    cout << "energy: " << energy << endl;
    cout << "mood: " << mood << endl;
    cout << "productivity: " << productivity << endl;
    cout << "stress: " << stress << endl;
    cout << "health: " << health << endl;

    return 0;
}