#include<iostream>
#include<string>
using namespace std;

class stats {
    public:
    int mood;
    int productivity;
    int energy;

    stats():energy(50),mood(50),productivity(50){} //initialize status at 50
void output() {      // make sure the values are between 0 and 100
       if (energy>100) {
           energy=100;
       }
        else if (energy<0) {
            energy=0;
        }
        if (mood>100) {
            mood=100;
        }
        else if (mood<0) {
            mood=0;
        }
        if (productivity>100) {
            productivity=100;
        }
        else if (productivity<0) {
            productivity=0;
        }

        cout<<"      FINAL REPORT       "<<endl;
        cout<<"energy: "<<energy<<"%"<<endl;
        cout<<"mood: "<<mood<<"%"<<endl;
        cout<<"productivity: "<<productivity<<"%"<<endl;


        if (productivity>=90) {
            cout<<"productive day"<<endl;
        }
        else if (energy<=40) {
            cout<<"exhausting day"<<endl;
        }
        else if (mood>=90) {
            cout<<"joyful day"<<endl;
        }
        else {
            cout<<"balanced day"<<endl;
        }
    }

};




class Relax:public Activity {   //inherit from activity
    public:
    void perform(stats &s) override {  //use apply rather than perform
       cout<<"Action: Relaxing"<<endl; // message
        s.mood+=10;
        s.energy+=10;
        s.productivity-=10;

    }

};





















