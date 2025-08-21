#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Passenger;  

class Flight {
private:
    string flightNumber, departure, arrival;
    int capacity;

    vector<bool> economySeats;
    vector<bool> businessSeats;

public:
    Flight(string fN, string d, string a, int cap)
        : flightNumber(fN), departure(d), arrival(a), capacity(cap) {
        economySeats.resize(10, false);   
        businessSeats.resize(10, false);
    }

    bool bookSeat(const string& seatType, int& seatIndexOut) {
        vector<bool>& seats = (seatType == "business") ? businessSeats : economySeats;

        for (int i = 0; i < seats.size(); i++) {
            if (!seats[i]) {
                seats[i] = true;
                seatIndexOut = i;
                return true;
            }
        }
        return false;  
    }

    bool cancelSeat(const string& seatType, int seatIndex) {
        vector<bool>& seats = (seatType == "business") ? businessSeats : economySeats;

        if (seatIndex >= 0 && seatIndex < seats.size() && seats[seatIndex]) {
            seats[seatIndex] = false;
            return true;
        }
        return false;
    }

    bool upgradeSeat(int econSeatIndex, int& businessSeatOut) {
        if (econSeatIndex < 0 || econSeatIndex >= economySeats.size() || !economySeats[econSeatIndex])
            return false;

        for (int i = 0; i < businessSeats.size(); i++) {
            if (!businessSeats[i]) {
                businessSeats[i] = true;
                economySeats[econSeatIndex] = false;
                businessSeatOut = i;
                return true;
            }
        }
        return false;
    }

    void showSeats() {
        cout << "\nFlight: " << flightNumber << " | " << departure << " -> " << arrival << "\n";
        cout << "Economy Seats: ";
        for (auto s : economySeats) cout << (s ? "[X]" : "[ ]");
        cout << "\nBusiness Seats: ";
        for (auto s : businessSeats) cout << (s ? "[X]" : "[ ]");
        cout << "\n";
    }
};

class Passenger {
private:
    string ID, name;
    string bookedSeatType;
    int seatIndex;
    bool hasBooking = false;

public:
    Passenger(string id, string n) : ID(id), name(n), seatIndex(-1) {}

    void requestBooking(Flight& flight, const string& seatType) {
        if (hasBooking) {
            cout << name << " already has a booking.\n";
            return;
        }

        if (flight.bookSeat(seatType, seatIndex)) {
            bookedSeatType = seatType;
            hasBooking = true;
            cout << name << " successfully booked a " << seatType << " seat at index " << seatIndex << ".\n";
        } else {
            cout << name << " failed to book a " << seatType << " seat.\n";
        }
    }

    void requestCancellation(Flight& flight) {
        if (!hasBooking) {
            cout << name << " has no booking to cancel.\n";
            return;
        }

        if (flight.cancelSeat(bookedSeatType, seatIndex)) {
            cout << name << " successfully cancelled their " << bookedSeatType << " seat.\n";
            hasBooking = false;
            seatIndex = -1;
        } else {
            cout << name << " failed to cancel seat.\n";
        }
    }

    void requestUpgrade(Flight& flight) {
        if (!hasBooking || bookedSeatType != "economy") {
            cout << name << " can't be upgraded (not in economy or no booking).\n";
            return;
        }

        int newBusinessIndex;
        if (flight.upgradeSeat(seatIndex, newBusinessIndex)) {
            cout << name << " upgraded to Business seat index " << newBusinessIndex << ".\n";
            bookedSeatType = "business";
            seatIndex = newBusinessIndex;
        } else {
            cout << name << "'s upgrade to Business failed (no available seats).\n";
        }
    }
};

int main() {
    
    Flight flight1("PK301", "Karachi", "Lahore", 20);
    Flight flight2("PK302", "Lahore", "Islamabad", 20);

    
    Passenger p1("P001", "Talha");
    Passenger p2("P002", "Ahsan");
    Passenger p3("P003", "Arham");

    
    p1.requestBooking(flight1, "economy");
    p2.requestBooking(flight1, "economy");
    p3.requestBooking(flight1, "business");

    
    p2.requestUpgrade(flight1);  
    p1.requestCancellation(flight1);

    
    flight1.showSeats();
}
