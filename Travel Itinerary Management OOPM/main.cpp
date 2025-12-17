#include <iostream>
#include "data.h"
using namespace std;

int main() {
    loadItineraries();

    cout << "=========================================\n";
    cout << "      WELCOME TO SMART-TRIP PLANNER\n";
    cout << "   Discover | Plan | Travel Smart\n";
    cout << "=========================================\n\n";

    string currentUser;

    while (true) {
        int choice;
        cout << "\n1. User Signup\n2. User Login\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            signup();
        }
        else if (choice == 2) {

            if (login(currentUser)) {

                while (true) {
                    int userChoice;
                    cout << "\n--- User Menu ---";
                    cout << "\n1. View Available Itineraries";
                    cout << "\n2. Suggest Itinerary";
                    cout << "\n3. Logout";
                    cout << "\nEnter choice: ";
                    cin >> userChoice;

                    if (userChoice == 1) {
                        showItineraries();

                       
                        cout << "\n--- Booking Process ---\n";

                        int pick, persons;
                        cout << "Select Itinerary Number: ";
                        cin >> pick;
                        cout << "Enter Number of Persons: ";
                        cin >> persons;

                        Itinerary &it = itineraries[pick - 1];

                        cout << "\nSelect Food Type:\n";
                        for (int i = 0; i < it.foodOptions.size(); i++)
                            cout << i + 1 << ". " << it.foodOptions[i] << "\n";

                        int foodChoice;
                        cin >> foodChoice;

                        int foodCost = 500 * persons;
                        int total = (it.pricePerPerson * persons) + foodCost;

                        cout << "\n-----------------------------------------\n";
                        cout << "        BUDGET CALCULATION\n";
                        cout << "-----------------------------------------\n";
                        cout << "Base Price/person : INR:- " << it.pricePerPerson << "\n";
                        cout << "Persons           : " << persons << "\n";
                        cout << "Food Charges      : INR:- " << foodCost << "\n";
                        cout << "Total Amount      : INR:- " << total << "\n\n";

                        cout << " Health Advisory:\n";
                        cout << "- Avoid spicy food if you have acidity\n";
                        cout << "- Stay hydrated during activities\n\n";

                        cout << " Travel Suggestions:\n";
                        cout << "- Carry sunscreen\n- Wear comfortable clothes\n";

                        string confirm;
                        cout << "\nConfirm Booking? (yes/no): ";
                        cin >> confirm;

                        if (confirm == "yes") {
                            cout << "\n*** BOOKING CONFIRMED ***\n";
                            cout << "Trip: " << it.title << "\n";
                            cout << "Persons: " << persons << "\n";
                            cout << "Food Type: " << it.foodOptions[foodChoice - 1] << "\n";
                            cout << "Total Paid: INR:- " << total << "\n";
                        } else {
                            cout << "\n***BOOKING CANCELLED***\n";
                        }

                        cout << "\n**********Thank you for choosing SMART-TRIP PLANNER**********\n";
                        cout << "Have a safe and memorable journey!\n";

                        break; 
                    }
                    else if (userChoice == 2) {
                        suggestItinerary();
                    }
                    else if (userChoice == 3) {
                        cout << "\nLogged out successfully.\n";
                        break;
                    }
                    else {
                        cout << "Invalid choice!\n";
                        break;
                    }
                }
            }
        }
        else if (choice == 3) {
            cout << "Thank you for using the system.\n";
            return 0;
        }
        else {
            cout << "Invalid choice!\n";
            break;
        }
    }
}



