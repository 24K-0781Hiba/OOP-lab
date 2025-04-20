#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight;

class Passenger {
private:
    string id;
    string name;
    
public:
    Passenger(const string& passengerId, const string& passengerName) 
        : id(passengerId), name(passengerName) {}

    string getId() const { return id; }
    string getName() const { return name; }

    bool requestBooking(Flight& flight);
    bool requestCancellation(Flight& flight);
    bool requestUpgrade(Flight& flight);
};

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    vector<string> bookedPassengers;
    vector<string> upgradedPassengers;

    bool isPassengerBooked(const string& passengerId) {
        for (const auto& id : bookedPassengers) {
            if (id == passengerId) return true;
        }
        return false;
    }

    bool isPassengerUpgraded(const string& passengerId) {
        for (const auto& id : upgradedPassengers) {
            if (id == passengerId) return true;
        }
        return false;
    }

public:
    Flight(const string& number, const string& depart, const string& arrive, int cap)
        : flightNumber(number), departure(depart), arrival(arrive), capacity(cap) {}

    string getFlightNumber() const { return flightNumber; }
    string getDeparture() const { return departure; }
    string getArrival() const { return arrival; }
    int getAvailableSeats() const { return capacity - bookedPassengers.size(); }

    bool bookSeat(const Passenger& passenger) {
        if (bookedPassengers.size() >= capacity) {
            cout << "Flight " << flightNumber << " is fully booked.\n";
            return false;
        }
        if (isPassengerBooked(passenger.getId())) {
            cout << "Passenger " << passenger.getName() << " already has a seat.\n";
            return false;
        }
        bookedPassengers.push_back(passenger.getId());
        cout << "Booked seat for " << passenger.getName() << " on flight " << flightNumber << ".\n";
        return true;
    }

    bool cancelSeat(const Passenger& passenger) {
        if (!isPassengerBooked(passenger.getId())) {
            cout << passenger.getName() << " doesn't have a booking to cancel.\n";
            return false;
        }

        for (auto it = bookedPassengers.begin(); it != bookedPassengers.end(); ++it) {
            if (*it == passenger.getId()) {
                bookedPassengers.erase(it);
                break;
            }
        }
   
        for (auto it = upgradedPassengers.begin(); it != upgradedPassengers.end(); ++it) {
            if (*it == passenger.getId()) {
                upgradedPassengers.erase(it);
                break;
            }
        }
        
        cout << "Cancelled booking for " << passenger.getName() << " on flight " << flightNumber << ".\n";
        return true;
    }

    bool upgradeSeat(const Passenger& passenger) {
        if (!isPassengerBooked(passenger.getId())) {
            cout << passenger.getName() << " must have a booking to upgrade.\n";
            return false;
        }
        if (isPassengerUpgraded(passenger.getId())) {
            cout << passenger.getName() << " is already upgraded.\n";
            return false;
        }
        upgradedPassengers.push_back(passenger.getId());
        cout << "Upgraded " << passenger.getName() << " on flight " << flightNumber << ".\n";
        return true;
    }

    friend bool Passenger::requestBooking(Flight&);
    friend bool Passenger::requestCancellation(Flight&);
    friend bool Passenger::requestUpgrade(Flight&);
};

bool Passenger::requestBooking(Flight& flight) {
    return flight.bookSeat(*this);
}

bool Passenger::requestCancellation(Flight& flight) {
    return flight.cancelSeat(*this);
}

bool Passenger::requestUpgrade(Flight& flight) {
    return flight.upgradeSeat(*this);
}

int main() {
    Flight nycToLon("BA112", "JFK", "Heathrow", 3);
    Flight parToBer("AF345", "CDG", "BER", 150);

    Passenger john("P100", "John Smith");
    Passenger emma("P101", "Emma Johnson");
    Passenger li("P102", "Li Wei");
    Passenger ana("P103", "Ana Garcia");

    cout << "\n--- Booking Phase ---\n";
    john.requestBooking(nycToLon);
    emma.requestBooking(nycToLon);
    li.requestBooking(nycToLon);
    ana.requestBooking(nycToLon); //should fail (capacity 3)

    cout << "\n--- Upgrade Phase ---\n";
    john.requestUpgrade(nycToLon);
    emma.requestUpgrade(nycToLon);
    emma.requestUpgrade(nycToLon);

    cout << "\n--- Cancellation Phase ---\n";
    li.requestCancellation(nycToLon);
    li.requestUpgrade(nycToLon); //should fail - no booking
    ana.requestBooking(nycToLon); //shouldn'r wotk after cencellation

    cout << "\n--- Flight Status ---\n";
    cout << "Flight " << nycToLon.getFlightNumber() << " has " 
         << nycToLon.getAvailableSeats() << " seats remaining (capacity: 3).\n";
    cout << "Flight " << parToBer.getFlightNumber() << " has " 
         << parToBer.getAvailableSeats() << " seats remaining (capacity: 150).\n";

    return 0;
}
