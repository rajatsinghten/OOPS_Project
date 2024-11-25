#include <iostream>
#include <string>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// Function to clear screen across different operating systems
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to display introduction page
void displayIntroduction()
{
    clearScreen();
    cout << "\n\n";
    cout << "\n";
    cout << "************************************************************\n";
    cout << "\n";
    cout << "*             AIRLINE MANAGEMENT SYSTEM                    *\n";
    cout << "\n";
    cout << "************************************************************\n";
    cout << "                    Welcome to                              \n";
    cout << "              SKY AIRLINES BOOKING SYSTEM                   \n";
    cout << "\n";
    cout << "\n";
    cout << "************************************************************\n";
    cout << "*  This system allows you to:                              *\n";
    cout << "*  → View all available flights                          *\n";
    cout << "*  → Register as a new passenger                         *\n";
    cout << "*  → Book flight tickets                                 *\n";
    cout << "*  → View passenger information                          *\n";
    cout << "************************************************************\n";
    cout << "\n";
    cout << "\nPress Enter to continue...";
    cin.ignore();
    clearScreen();
}

// Forward declarations
class Flight;
class Passenger;
class Booking;

// Flight Class
class Flight
{
private:
    string flightNumber;
    string source;
    string destination;
    int totalSeats;
    int availableSeats;
    double price;

public:
    Flight(string fNo, string src, string dest, int seats, double pr)
    {
        flightNumber = fNo;
        source = src;
        destination = dest;
        totalSeats = seats;
        availableSeats = seats;
        price = pr;
    }

    // Getters
    string getFlightNumber() { return flightNumber; }
    string getSource() { return source; }
    string getDestination() { return destination; }
    int getAvailableSeats() { return availableSeats; }
    double getPrice() { return price; }

    // Update available seats
    void bookSeat()
    {
        if (availableSeats > 0)
            availableSeats--;
    }

    void displayFlightInfo()
    {
        cout << "\nFlight Number: " << flightNumber
             << "\nFrom: " << source
             << "\nTo: " << destination
             << "\nAvailable Seats: " << availableSeats
             << "\nPrice: $" << price << endl;
    }
};

// Passenger Class
class Passenger
{
private:
    static int nextPassengerId;
    int passengerId;
    string name;
    string email;
    string phone;

public:
    Passenger(string n, string e, string p)
    {
        passengerId = nextPassengerId++;
        name = n;
        email = e;
        phone = p;
    }

    // Getters
    int getPassengerId() { return passengerId; }
    string getName() { return name; }

    void displayInfo()
    {

        cout << "\nPassenger ID: " << passengerId
             << "\nName: " << name
             << "\nEmail: " << email
             << "\nPhone: " << phone << endl;
    }
};
int Passenger::nextPassengerId = 1000;

// Booking Class
class Booking
{
private:
    static int nextBookingId;
    int bookingId;
    Flight *flight;
    Passenger *passenger;
    string bookingDate;

public:
    Booking(Flight *f, Passenger *p, string date)
    {
        bookingId = nextBookingId++;
        flight = f;
        passenger = p;
        bookingDate = date;
        flight->bookSeat();
    }

    void displayBookingInfo()
    {
        cout << "\n=== Booking Information ===" << endl;
        cout << "Booking ID: " << bookingId << endl;
        cout << "Date: " << bookingDate << endl;
        passenger->displayInfo();
        flight->displayFlightInfo();
    }
};
int Booking::nextBookingId = 100;

// Airline Management System Class
class AirlineManagementSystem
{
private:
    vector<Flight *> flights;
    vector<Passenger *> passengers;
    vector<Booking *> bookings;

public:
    void addFlight(Flight *flight)
    {
        flights.push_back(flight);
    }

    void registerPassenger(Passenger *passenger)
    {
        passengers.push_back(passenger);
    }

    bool isPassengerRegistered(Passenger *passenger)
    {
        for (Passenger *p : passengers)
        {
            if (p->getPassengerId() == passenger->getPassengerId())
                return true;
        }
        return false;
    }

    Flight *findFlight(string flightNumber)
    {
        for (Flight *flight : flights)
        {
            if (flight->getFlightNumber() == flightNumber)
                return flight;
        }
        return nullptr;
    }

    Passenger *findPassenger(int passengerId)
    {
        for (Passenger *passenger : passengers)
        {
            if (passenger->getPassengerId() == passengerId)
                return passenger;
        }
        return nullptr;
    }

    void createBooking(Flight *flight, Passenger *passenger, string date)
    {
        if (!isPassengerRegistered(passenger))
        {
            cout << "\nPassenger not registered! Please register first." << endl;
            return;
        }

        if (flight->getAvailableSeats() > 0)
        {
            Booking *booking = new Booking(flight, passenger, date);
            bookings.push_back(booking);
            cout << "\nBooking successful!" << endl;
            booking->displayBookingInfo();
        }
        else
        {
            cout << "\nSorry, no seats available on this flight." << endl;
        }
    }

    void displayAllFlights()
    {
        cout << "\n=== Available Flights ===" << endl;
        for (Flight *flight : flights)
        {
            flight->displayFlightInfo();
        }
    }

    void displayAllPassengers()
    {
        cout << "\n=== Registered Passengers ===" << endl;
        for (Passenger *passenger : passengers)
        {
            passenger->displayInfo();
        }
    }

    ~AirlineManagementSystem()
    {
        for (Flight *flight : flights)
        {
            delete flight;
        }
        flights.clear();

        for (Passenger *passenger : passengers)
        {
            delete passenger;
        }
        passengers.clear();

        for (Booking *booking : bookings)
        {
            delete booking;
        }
        bookings.clear();
    }
};

// Main function
int main()
{
    displayIntroduction();
    AirlineManagementSystem ams;

    // Adding sample flights
    ams.addFlight(new Flight("FL001", "New York", "London", 200, 500.0));
    ams.addFlight(new Flight("FL002", "Paris", "Tokyo", 150, 750.0));
    ams.addFlight(new Flight("FL003", "Dubai", "Singapore", 180, 450.0));

    int choice;
    do
    {
        cout << "\n=== Airline Management System ===" << endl;
        cout << "1. Display All Flights" << endl;
        cout << "2. Register New Passenger" << endl;
        cout << "3. Book a Flight" << endl;
        cout << "4. Display Registered Passengers" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // clearScreen();
            ams.displayAllFlights();
            break;
        }
        case 2:
        {
            // clearScreen();
            string name, email, phone;
            cout << "\nEnter passenger details:" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Email: ";
            getline(cin, email);
            cout << "Phone: ";
            getline(cin, phone);

            Passenger *passenger = new Passenger(name, email, phone);
            ams.registerPassenger(passenger);
            cout << "\nPassenger registered successfully!" << endl;
            passenger->displayInfo();
            break;
        }
        case 3:
        {
            // clearScreen();
            string flightNumber, date;
            cout << "\nEnter flight number: ";
            cin >> flightNumber;

            Flight *flight = ams.findFlight(flightNumber);
            if (flight != nullptr)
            {
                int passengerId;
                cout << "Enter your Passenger ID: ";
                cin >> passengerId;

                Passenger *passenger = ams.findPassenger(passengerId);

                if (passenger != nullptr)
                {
                    cout << "Enter booking date (DD/MM/YYYY): ";
                    cin >> date;

                    ams.createBooking(flight, passenger, date);
                }
                else
                {
                    cout << "\nPassenger not found! Please register first." << endl;
                }
            }
            else
            {
                cout << "\nFlight not found!" << endl;
            }
            break;
        }
        case 4:
        {
            // clearScreen();
            ams.displayAllPassengers();
            break;
        }
        case 5:
            clearScreen();
            cout << "\nThank you for using the Airline Management System!" << endl;
            cout << "Have a great day!" << endl;
            break;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}