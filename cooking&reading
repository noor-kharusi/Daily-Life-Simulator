class Cooking : public Activity {
public:
    Cooking() : Activity("Cooking") {}

    ~Cooking() {}

    void apply(Stats& stats) override {
        cout << "  >> You cooked!" << endl;
        stats.setMood(stats.getMood() + 15);
        stats.setProductivity(stats.getProductivity() + 10);
        stats.setEnergy(stats.getEnergy() - 5);
    }
};

class Reading : public Activity {
public:
    Reading() : Activity("Reading") {}

    ~Reading() {}

    void apply(Stats& stats) override {
        cout << "  >> You read!" << endl;
        stats.setProductivity(stats.getProductivity() + 20);
        stats.setMood(stats.getMood() + 10);
        stats.setEnergy(stats.getEnergy() - 10);
    }
};
