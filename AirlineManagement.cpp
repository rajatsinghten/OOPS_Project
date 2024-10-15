#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void mainMenu();

class Management {
public:
    Management() {
        mainMenu();
    }
};

void mainMenu() {
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

    switch(choice) {
        case 1:
            cout << "Add Customer Details\n";
            break;
        case 2:
            cout << "Flight Registration\n";
            break;
        case 3:
            cout << "Ticket and Charges\n";
            break;
        case 4:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid choice. Try again.\n";
            mainMenu();
    }
}

int main() {
    Management manage;
    return 0;
}
