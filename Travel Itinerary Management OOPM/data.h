#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
using namespace std;


struct User {
    string username;
    string password;
};


struct Itinerary {
    string title;
    string location;
    int days;
    vector<string> activities;
    vector<string> foodOptions;
    int pricePerPerson;
};


void loadItineraries();
void saveItineraries();      
void showItineraries();
void suggestItinerary();



bool signup();
bool login(string &loggedUser);


extern vector<User> users;
extern vector<Itinerary> itineraries;

#endif



