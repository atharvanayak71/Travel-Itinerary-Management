#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
using namespace std;

// ================= USER =================
struct User {
    string username;
    string password;
};

// ================= ITINERARY =================
struct Itinerary {
    string title;
    string location;
    int days;
    vector<string> activities;
    vector<string> foodOptions;
    int pricePerPerson;
};

// ================= FUNCTIONS =================
// ---- Itinerary ----
void loadItineraries();
void saveItineraries();      
void showItineraries();

// ---- User ----
bool signup();
bool login(string &loggedUser);

// ================= GLOBAL =================
extern vector<User> users;
extern vector<Itinerary> itineraries;

#endif

