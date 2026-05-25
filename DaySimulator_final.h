#ifndef DAYSIMULATOR_H
#define DAYSIMULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include "Activities_final.h"
using namespace std;

class DaySimulator {
private:
    string playerName;
    Stats stats;
    int numActivities;
    vector<string> activityLog;

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

            if (choice == 1) { Study s; s.apply(stats); activityLog.push_back("Study"); }
            else if (choice == 2) { Sleep sl; sl.apply(stats); activityLog.push_back("Sleep"); }
            else if (choice == 3) { Exercise e; e.apply(stats); activityLog.push_back("Exercise"); }
            else if (choice == 4) { Relax r; r.apply(stats); activityLog.push_back("Relax"); }
            else if (choice == 5) { Gaming g; g.apply(stats); activityLog.push_back("Gaming"); }
            else if (choice == 6) { Socializing so; so.apply(stats); activityLog.push_back("Socializing"); }
            else if (choice == 7) { Meditation m; m.apply(stats); activityLog.push_back("Meditation"); }

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
        cout << "  Your day:" << endl;
        for (int i = 0; i < activityLog.size(); i++) {
            cout << "    " << i + 1 << ". " << activityLog[i] << endl;
        }
        cout << endl;
        cout << "  Final stats:" << endl;
        stats.display();
        cout << endl;

        if (stats.getProductivity() >= 90) {
            cout << "  * Productive Day! Amazing work, " << playerName << "!" << endl;
        } else if (stats.getMood() >= 90) {
            cout << "  * Joyful Day! You were in a great mood!" << endl;
        } else if (stats.getEnergy() >= 90) {
            cout << "  * Energetic Day! You are full of energy!" << endl;
        } else if (stats.getEnergy() <= 30) {
            cout << "  * Exhausting Day! Make sure to rest, " << playerName << "." << endl;
        } else if (stats.getMood() <= 30) {
            cout << "  * Rough Day! Tomorrow will be better." << endl;
        } else {
            cout << "  * Balanced Day! Not bad, " << playerName << "!" << endl;
        }

        cout << "========================================" << endl;
        cout << "  Thanks for using Daily Life Simulator!" << endl;
        cout << "  Goodbye, " << playerName << "!" << endl;
        cout << "========================================" << endl;
    }
};

#endif
