#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void mainMenu();  // Function declaration
void customerInfo();  // Forward declaration for customer info
void flights();  // Forward declaration for flight registration
void bill();  // Forward declaration for ticket and charges

class Management
{
public:
    Management()
    {
        mainMenu();
    }
};

// Main menu function
void mainMenu()
{
    int choice;
    cout << "\t\tXYZ Airlines\n" << endl;
    cout << "\t\tMain Menu\n" << endl;
    cout << "\t|\tPress 1 to add the Customer Details\t|" << endl;
    cout << "\t|\tPress 2 for Flight Registration\t\t|" << endl;
    cout << "\t|\tPress 3 for Ticket and Charges\t\t|" << endl;
    cout << "\t|\tPress 4 to Exit\t\t\t\t|" << endl;
    cout << "\t_______________________________________\n" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        customerInfo();
        break;
    case 2:
        flights();
        break;
    case 3:
        bill();
        break;
    case 4:
        cout << "Exiting...\n";
        exit(0);
    default:
        cout << "Invalid choice. Try again.\n";
        mainMenu();
    }
}

// Placeholder functions for the respective features

void customerInfo()
{
    cout << "Customer Information\n";
    // Add logic to handle customer information here
}

void flights()
{
    cout << "Flight Registration\n";
    // Add logic to handle flight registration here
}

void bill()
{
    cout << "Ticket and Charges\n";
    // Add logic to handle ticketing and charges here
}

int main()
{
    Management manage;
    return 0;
}
