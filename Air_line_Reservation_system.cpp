#include <iostream>
#include <string>
using namespace std;

class Airline
{
private:
    string name, destination;
    int age;
    int fare;
    bool booked;

public:
    Airline()
    {
        booked = false;
        fare = 0;
    }

    void bookTicket()
    {
        if(booked)
        {
            cout << "Ticket already booked." << endl;
            return;
        }

        cout << "Enter Passenger Name: " << endl;
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: " << endl;
        cin >> age;

        cout << "Select Destination:" << endl;
        cout << "1. Karachi (5000)" << endl;
        cout << "2. Lahore (15000)" << endl;
        cout << "3. Multan (30000)" << endl;
        cout << "Enter choice: " << endl;

        int choice;
        cin >> choice;

        if(choice == 1)
        {
            destination = "Karachi";
            fare = 5000;
        }
        else if(choice == 2)
        {
            destination = "Lahore";
            fare = 15000;
        }
        else if(choice == 3)
        {
            destination = "Multan";
            fare = 30000;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        if(age < 12)
        {
            fare = fare / 2;
            cout << "Child discount applied." << endl;
        }

        booked = true;

        cout << "Ticket booked successfully." << endl;
        cout << "Destination: " << destination << endl;
        cout << "Fare: Rs " << fare << endl;
    }

    void cancelTicket()
    {
        if(!booked)
        {
            cout << "No ticket to cancel." << endl;
        }
        else
        {
            booked = false;
            cout << "Ticket cancelled successfully." << endl;
        }
    }

    void viewDetails()
    {
        if(!booked)
        {
            cout << "No booking found." << endl;
        }
        else
        {
            cout << "Passenger Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Destination: " << destination << endl;
            cout << "Fare: Rs " << fare << endl;
        }
    }
};

int main()
{
    Airline a;
    int option;

    do
    {
        cout << endl;
        cout << "----- Airline Reservation System -----" << endl;
        cout << "1. Book Ticket" << endl;
        cout << "2. Cancel Ticket" << endl;
        cout << "3. View Ticket Details" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter option: " << endl;
        cin >> option;

        if(option == 1)
            a.bookTicket();
        else if(option == 2)
            a.cancelTicket();
        else if(option == 3)
            a.viewDetails();
        else if(option == 4)
            cout << "Thank You for using airline reservation system." << endl;
        else
            cout << "Invalid option." << endl;

    } while(option != 4);

    return 0;
}