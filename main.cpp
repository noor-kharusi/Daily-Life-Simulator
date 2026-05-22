#include <iostream>
#include <string>
using namespace std;
 
class Stats {
private:
    int energy;
    int mood;
    int productivity;
 
public:
    Stats() {
        energy = 50;
        mood = 50;
        productivity = 50;
    }
 
    ~Stats() {}
 
    int getEnergy() { return energy; }
    int getMood() { return mood; }
    int getProductivity() { return productivity; }
 
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
 
    Stats operator+(const Stats& other) {
        Stats result;
        result.setEnergy((energy + other.energy) / 2);
        result.setMood((mood + other.mood) / 2);
        result.setProductivity((productivity + other.productivity) / 2);
        return result;
    }
 
    // Display a progress bar for a stat
    void printBar(string label, int value) {
        cout << label << " [";
        int bars = value / 10;
        for (int i = 0; i < 10; i++) {
            if (i < bars) cout << "#";
            else cout << "-";
        }
        cout << "] " << value << "%" << endl;
    }
 
    void display() {
        printBar("Energy:       ", energy);
        printBar("Mood:         ", mood);
        printBar("Productivity: ", productivity);
    }
};
 
class Activity {
protected:
    string name;
 
public:
    Activity(string n) {
        name = n;
    }
 
    ~Activity() {}
 
    virtual void apply(Stats& stats) = 0;
 
    void showName() {
        cout << "Activity: " << name << endl;
    }
};
 
class Study : public Activity {
public:
    Study() : Activity("Study") {}
    ~Study() {}
 
    void apply(Stats& stats) override {
        cout << "  >> You studied!" << endl;
        stats.setProductivity(stats.getProductivity() + 20);
        stats.setEnergy(stats.getEnergy() - 15);
    }
};
 
class Sleep : public Activity {
public:
    Sleep() : Activity("Sleep") {}
    ~Sleep() {}
 
    void apply(Stats& stats) override {
        cout << "  >> You slept!" << endl;
        stats.setEnergy(stats.getEnergy() + 30);
    }
};
 
class Exercise : public Activity {
public:
    Exercise() : Activity("Exercise") {}
    ~Exercise() {}
 
    void apply(Stats& stats) override {
        cout << "  >> You exercised!" << endl;
        stats.setEnergy(stats.getEnergy() - 20);
        stats.setMood(stats.getMood() + 25);
    }
};
 
class Relax : public Activity {
public:
    Relax() : Activity("Relax") {}
    ~Relax() {}
 
    void apply(Stats& stats) override {
        cout << "  >> You relaxed!" << endl;
        stats.setMood(stats.getMood() + 10);
        stats.setEnergy(stats.getEnergy() + 10);
        stats.setProductivity(stats.getProductivity() - 10);
    }
};
 
class Gaming : public Activity {
public:
    Gaming() : Activity("Gaming") {}
    ~Gaming() {}
 
    void apply(Stats& stats) override {
        cout << "  >> You gamed!" << endl;
        stats.setMood(stats.getMood() + 20);
        stats.setProductivity(stats.getProductivity() - 20);
        stats.setEnergy(stats.getEnergy() - 10);
    }
};
 
class Socializing : public Activity {
public:
    Socializing() : Activity("Socializing") {}
    ~Socializing() {}
 
    void apply(Stats& stats) override {
        cout << "  >> You socialized!" << endl;
        stats.setMood(stats.getMood() + 25);
        stats.setEnergy(stats.getEnergy() - 10);
    }
};
 
class Meditation : public Activity {
public:
    Meditation() : Activity("Meditation") {}
    ~Meditation() {}
 
    void apply(Stats& stats) override {
        cout << "  >> You meditated!" << endl;
        stats.setMood(stats.getMood() + 15);
        stats.setEnergy(stats.getEnergy() + 10);
        stats.setProductivity(stats.getProductivity() + 10);
    }
};
 
class DaySimulator {
private:
    string playerName;
    Stats stats;
    int numActivities;
 
public:
    DaySimulator(string name) {
        playerName = name;
        numActivities = 0;
    }
 
    ~DaySimulator() {}
 
    void run() {
        cout << endl;
        cout << "========================================" << endl;
        cout << "       DAILY LIFE SIMULATOR" << endl;
        cout << "========================================" << endl;
        cout << "  Welcome, " << playerName << "!" << endl;
        cout << "  Manage your day and track your stats." << endl;
        cout << "========================================" << endl;
        cout << endl;
 
        // Ask how many activities with exception handling
        while (true) {
            try {
                cout << "How many activities do you want to do today? (1-7): ";
                cin >> numActivities;
 
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw invalid_argument("Please enter a number.");
                }
 
                if (numActivities < 1 || numActivities > 7) {
                    throw out_of_range("Number must be between 1 and 7.");
                }
 
                break;
 
            } catch (invalid_argument& e) {
                cout << "  [Error] " << e.what() << endl;
            } catch (out_of_range& e) {
                cout << "  [Error] " << e.what() << endl;
            }
        }
 
        cout << endl;
        cout << "Starting stats:" << endl;
        stats.display();
        cout << endl;
 
        // Activity loop
        for (int i = 1; i <= numActivities; i++) {
            cout << "----------------------------------------" << endl;
            cout << "  Activity " << i << " of " << numActivities << endl;
            cout << "----------------------------------------" << endl;
            cout << "  1. Study      4. Relax" << endl;
            cout << "  2. Sleep      5. Gaming" << endl;
            cout << "  3. Exercise   6. Socializing" << endl;
            cout << "              7. Meditation" << endl;
            cout << "----------------------------------------" << endl;
 
            int choice;
 
            // Exception handling for invalid choice
            while (true) {
                try {
                    cout << "  Enter choice: ";
                    cin >> choice;
 
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        throw invalid_argument("Please enter a number.");
                    }
 
                    if (choice < 1 || choice > 7) {
                        throw out_of_range("Choice must be between 1 and 7.");
                    }
 
                    break;
 
                } catch (invalid_argument& e) {
                    cout << "  [Error] " << e.what() << endl;
                } catch (out_of_range& e) {
                    cout << "  [Error] " << e.what() << endl;
                }
            }
 
            cout << endl;
 
            if (choice == 1) { Study s; s.apply(stats); }
            else if (choice == 2) { Sleep sl; sl.apply(stats); }
            else if (choice == 3) { Exercise e; e.apply(stats); }
            else if (choice == 4) { Relax r; r.apply(stats); }
            else if (choice == 5) { Gaming g; g.apply(stats); }
            else if (choice == 6) { Socializing so; so.apply(stats); }
            else if (choice == 7) { Meditation m; m.apply(stats); }
 
            cout << endl;
            cout << "  Current stats:" << endl;
            stats.display();
            cout << endl;
        }
 
        showFinalReport();
    }
 
    void showFinalReport() {
        cout << "========================================" << endl;
        cout << "             FINAL REPORT" << endl;
        cout << "========================================" << endl;
        stats.display();
        cout << endl;
 
        if (stats.getProductivity() >= 90) {
            cout << "  ★ Productive Day! Amazing work, " << playerName << "!" << endl;
        } else if (stats.getMood() >= 90) {
            cout << "  ★ Joyful Day! You were in a great mood!" << endl;
        } else if (stats.getEnergy() >= 90) {
            cout << "  ★ Energetic Day! You are full of energy!" << endl;
        } else if (stats.getEnergy() <= 30) {
            cout << "  ★ Exhausting Day! Make sure to rest, " << playerName << "." << endl;
        } else if (stats.getMood() <= 30) {
            cout << "  ★ Rough Day! Tomorrow will be better." << endl;
        } else {
            cout << "  ★ Balanced Day! Not bad, " << playerName << "!" << endl;
        }
 
        cout << "========================================" << endl;
        cout << "  Thanks for playing! Goodbye, " << playerName << "!" << endl;
        cout << "========================================" << endl;
    }
};
 
int main() {
    string name;
    cout << "========================================" << endl;
    cout << "       DAILY LIFE SIMULATOR" << endl;
    cout << "========================================" << endl;
    cout << "  Enter your name: ";
    cin >> name;
 
    DaySimulator sim(name);
    sim.run();
 
    return 0;
}
