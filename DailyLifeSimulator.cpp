#include <iostream>
#include <string>
using namespace std;

// =============================================
// STATS CLASS - by Sawsan
// Stores and manages the three player stats
// =============================================
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
    int getEnergy() { return energy; }
    int getMood() { return mood; }
    int getProductivity() { return productivity; }

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
    void display() {
        cout << "Energy:       " << energy << "%" << endl;
        cout << "Mood:         " << mood << "%" << endl;
        cout << "Productivity: " << productivity << "%" << endl;
    }
};

// =============================================
// ACTIVITY CLASS - by Lubna
// Abstract base class for all activities
// =============================================
class Activity {
protected:
    string name;

public:
    // Constructor
    Activity(string n) {
        name = n;
    }

    // Pure virtual function - each activity must override this
    virtual void apply(Stats& stats) = 0;

    // Display the activity name
    void showName() {
        cout << "Activity: " << name << endl;
    }
};

// =============================================
// STUDY CLASS - by Lubna
// Increases productivity, decreases energy
// =============================================
class Study : public Activity {
public:
    Study() : Activity("Study") {}

    void apply(Stats& stats) override {
        cout << "You studied today!" << endl;
        stats.setProductivity(stats.getProductivity() + 20);
        stats.setEnergy(stats.getEnergy() - 15);
    }
};

// =============================================
// SLEEP CLASS - by Yousuf
// Increases energy
// =============================================
class Sleep : public Activity {
public:
    Sleep() : Activity("Sleep") {}

    void apply(Stats& stats) override {
        cout << "You slept today!" << endl;
        stats.setEnergy(stats.getEnergy() + 30);
    }
};

// =============================================
// EXERCISE CLASS - by Yousuf
// Increases mood, decreases energy
// =============================================
class Exercise : public Activity {
public:
    Exercise() : Activity("Exercise") {}

    void apply(Stats& stats) override {
        cout << "You exercised today!" << endl;
        stats.setEnergy(stats.getEnergy() - 20);
        stats.setMood(stats.getMood() + 25);
    }
};

// =============================================
// RELAX CLASS - by Sawsan
// Increases mood and energy, decreases productivity
// =============================================
class Relax : public Activity {
public:
    Relax() : Activity("Relax") {}

    void apply(Stats& stats) override {
        cout << "You relaxed today!" << endl;
        stats.setMood(stats.getMood() + 10);
        stats.setEnergy(stats.getEnergy() + 10);
        stats.setProductivity(stats.getProductivity() - 10);
    }
};

// =============================================
// DAY SIMULATOR CLASS - by Noor
// Controls the full simulation and final report
// =============================================
class DaySimulator {
private:
    string playerName;
    Stats stats;

public:
    // Constructor
    DaySimulator(string name) {
        playerName = name;
    }

    // Run the simulation - user picks 4 activities
    void run() {
        cout << "==============================" << endl;
        cout << "  Welcome, " << playerName << "!" << endl;
        cout << "  Daily Life Simulator" << endl;
        cout << "==============================\n" << endl;

        cout << "Starting stats:" << endl;
        stats.display();
        cout << endl;

        int choice;

        // Loop 4 times for 4 activities
        for (int i = 1; i <= 4; i++) {
            cout << "--- Activity " << i << " ---" << endl;
            cout << "1. Study" << endl;
            cout << "2. Sleep" << endl;
            cout << "3. Exercise" << endl;
            cout << "4. Relax" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            cout << endl;

            // Create the chosen activity and apply it
            if (choice == 1) {
                Study s;
                s.apply(stats);
            } else if (choice == 2) {
                Sleep sl;
                sl.apply(stats);
            } else if (choice == 3) {
                Exercise e;
                e.apply(stats);
            } else if (choice == 4) {
                Relax r;
                r.apply(stats);
            } else {
                cout << "Invalid choice, skipping." << endl;
            }

            // Show stats after each activity
            cout << "\nCurrent stats:" << endl;
            stats.display();
            cout << endl;
        }

        // Show the final report
        showFinalReport();
    }

    // Display final report with day description
    void showFinalReport() {
        cout << "==============================" << endl;
        cout << "        FINAL REPORT" << endl;
        cout << "==============================" << endl;
        stats.display();
        cout << endl;

        // Day description based on stats
        if (stats.getProductivity() >= 90) {
            cout << "Productive Day! Amazing work, " << playerName << "!" << endl;
        } else if (stats.getMood() >= 90) {
            cout << "Joyful Day! You were in a great mood!" << endl;
        } else if (stats.getEnergy() <= 40) {
            cout << "Exhausting Day! Make sure to rest." << endl;
        } else {
            cout << "Balanced Day! Not bad, " << playerName << "!" << endl;
        }
    }
};

// =============================================
// MAIN FUNCTION - by Noor
// Entry point of the program
// =============================================
int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;

    // Create simulator and run it
    DaySimulator sim(name);
    sim.run();

    return 0;
}
