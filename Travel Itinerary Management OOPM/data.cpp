#include "data.h"
#include <iostream>
#include <fstream>
using namespace std;

vector<User> users;
vector<Itinerary> itineraries;

// ================= LOAD ITINERARIES =================
void loadItineraries() {

    ifstream in("itineraries.txt");
    if (!in) {
        // ---------- DEFAULT DATA (FIRST RUN) ----------
        itineraries = {
            {
                "Goa Beach Escape",
                "Goa, India",
                5,
                {
                    "Day 1: Beach walk, sunset cruise",
                    "Day 2: Fort Aguada, water sports",
                    "Day 3: Dudhsagar waterfall",
                    "Day 4: Local markets & nightlife",
                    "Day 5: Relaxation & shopping"
                },
                {"Indian", "Chinese", "Italian"},
                12000
            },
            {
                "Manali Adventure Trip",
                "Manali, India",
                4,
                {
                    "Day 1: Mall Road & cafes",
                    "Day 2: Solang Valley adventure",
                    "Day 3: Rohtang Pass snow trip",
                    "Day 4: River rafting & shopping"
                },
                {"Indian", "Continental"},
                10500
            },
            {
                "Rajasthan Royal Heritage",
                "Jaipur, Jodhpur, Udaipur",
                6,
                {
                    "Day 1: Amber Fort",
                    "Day 2: City Palace",
                    "Day 3: Mehrangarh Fort",
                    "Day 4: Desert safari",
                    "Day 5: Lake Pichola",
                    "Day 6: Shopping"
                },
                {"Rajasthani", "Indian"},
                15000
            },
            {
                "Kerala Backwaters Retreat",
                "Kochi, Munnar, Alleppey",
                5,
                {
                    "Day 1: Fort Kochi",
                    "Day 2: Tea gardens",
                    "Day 3: Hill sightseeing",
                    "Day 4: Houseboat stay",
                    "Day 5: Ayurveda relaxation"
                },
                {"South Indian", "Chinese"},
                13500
            },
            {
                "Madhya Pradesh Heritage Tour",
                "Gwalior, Pachmarhi, Indore, Bhopal",
                6,
                {
                    "Day 1: Gwalior Fort",
                    "Day 2: Pachmarhi hill station",
                    "Day 3: Bee Falls & caves",
                    "Day 4: Indore food tour",
                    "Day 5: Bhimbetka caves",
                    "Day 6: Sanchi Stupa"
                },
                {"Indian", "Street Food"},
                14000
            }
        };

        // save default to file
        ofstream out("itineraries.txt");
        out << itineraries.size() << "\n";
        for (auto &it : itineraries) {
            out << it.title << "\n" << it.location << "\n";
            out << it.days << " " << it.pricePerPerson << "\n";
            out << it.activities.size() << "\n";
            for (auto &a : it.activities) out << a << "\n";
            out << it.foodOptions.size() << "\n";
            for (auto &f : it.foodOptions) out << f << "\n";
        }
        out.close();
        return;
    }

    // ---------- LOAD FROM FILE ----------
    itineraries.clear();
    int n;
    in >> n;
    in.ignore();

    for (int i = 0; i < n; i++) {
        Itinerary it;
        getline(in, it.title);
        getline(in, it.location);
        in >> it.days >> it.pricePerPerson;
        in.ignore();

        int a;
        in >> a;
        in.ignore();
        for (int j = 0; j < a; j++) {
            string s;
            getline(in, s);
            it.activities.push_back(s);
        }

        int f;
        in >> f;
        in.ignore();
        for (int j = 0; j < f; j++) {
            string s;
            getline(in, s);
            it.foodOptions.push_back(s);
        }

        itineraries.push_back(it);
    }
    in.close();
}

// ================= DISPLAY =================
void showItineraries() {
    cout << "\n=========================================\n";
    cout << "        AVAILABLE ITINERARIES\n";
    cout << "=========================================\n\n";

    for (int i = 0; i < itineraries.size(); i++) {
        cout << "[" << i + 1 << "] " << itineraries[i].title
             << " (" << itineraries[i].days << " Days)\n";
        cout << "Destination : " << itineraries[i].location << "\n";
        cout << "Daily Activities:\n";
        for (auto &a : itineraries[i].activities)
            cout << " " << a << "\n";
        cout << "Food Options: ";
        for (auto &f : itineraries[i].foodOptions)
            cout << f << " ";
        cout << "\nBase Price / Person: INR:- "
             << itineraries[i].pricePerPerson << "\n\n";
        cout << "-----------------------------------------\n\n";
    }
}

// ================= AUTH =================
bool signup() {
    User u;
    cout << "Enter Username: ";
    cin >> u.username;
    cout << "Enter Password: ";
    cin >> u.password;

    for (auto &x : users)
        if (x.username == u.username) {
            cout << "User already exists!\n";
            return false;
        }

    users.push_back(u);

    ofstream out("users.txt", ios::app);
    out << u.username << " " << u.password << "\n";
    out.close();

    cout << "Signup successful!\n";
    return true;
}

bool login(string &loggedUser) {
    ifstream in("users.txt");
    string u, p;
    cout << "Enter Username: ";
    cin >> u;
    cout << "Enter Password: ";
    cin >> p;

    string fu, fp;
    while (in >> fu >> fp) {
        if (fu == u && fp == p) {
            loggedUser = u;
            cout << "Login successful!\n";
            in.close();
            return true;
        }
    }

    in.close();
    cout << "Invalid login!\n";
    return false;
}
