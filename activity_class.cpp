#include <iostream>
#include <string>
using namespace std;

class activity {
protected:
    string name;

public:
    activity(string n) {
        name = n;
    }

    virtual void apply(int &energy, int &mood, int &productivity) = 0;

    void showname() {
        cout << "activity: " << name << endl;
    }
};

class study : public activity {
public:
    study() : activity("study") {
    }

    void apply(int &energy, int &mood, int &productivity) {
        cout << "you studied today" << endl;
        productivity += 5;
        energy -= 10;
    }
};

int main() {
    int energy = 100;
    int mood = 100;
    int productivity = 100;

    study s;

    s.showname();

    s.apply(energy, mood, productivity);

    cout << endl;
    cout << "energy: " << energy << endl;
    cout << "mood: " << mood << endl;
    cout << "productivity: " << productivity << endl;

    return 0;
}