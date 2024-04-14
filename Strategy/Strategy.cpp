#include <iostream>
#include <string>

class TripStrategy {
protected:
    int price;
    int time;

public:
    TripStrategy(int price, int time) : price(price), time(time) {}

    virtual void trip() const = 0;
    virtual ~TripStrategy() = default;
};

class Bicycle : public TripStrategy {
public:
    Bicycle() : TripStrategy(0, 60) {}

    void trip() const override {
        std::cout << "On the bicycle, you'll arrive at your destination in " << time << " minutes with a cost of " << price << " hrn" << std::endl;
    }
};

class PublicTransport : public TripStrategy {
public:
    PublicTransport() : TripStrategy(20, 30) {}

    void trip() const override {
        std::cout << "Using public transport, you'll arrive at your destination in " << time << " minutes with a cost of " << price << " hrn" << std::endl;
    }
};

class Taxi : public TripStrategy {
public:
    Taxi() : TripStrategy(100, 10) {}

    void trip() const override {
        std::cout << "Taking a taxi, you'll arrive at your destination in " << time << " minutes with a cost of " << price << " hrn" << std::endl;
    }
};

class ConcreteTrip {
    TripStrategy* strategy;

public:
    ConcreteTrip() : strategy(nullptr) {}

    void setStrategy(TripStrategy* strategy) {
        this->strategy = strategy;
    }

    void trip() const {
        if (strategy)
            strategy->trip();
        else
            std::cout << "Please set a trip strategy before proceeding." << std::endl;
    }
};

int main() {
    ConcreteTrip trip;
    PublicTransport pt;
    trip.setStrategy(&pt);
    trip.trip();

    Bicycle bike;
    trip.setStrategy(&bike);
    trip.trip();

    Taxi taxi;
    trip.setStrategy(&taxi);
    trip.trip();

    return 0;
}
