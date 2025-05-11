#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Event {
    string day;
    string issueType; // e.g., Water, Electricity
    string reason;
};

vector<Event> events;

void addEvent() {
    Event e;
    cout << "Enter day (e.g., Monday): ";
    getline(cin, e.day);
    cout << "Enter issue type (Water/Electricity): ";
    getline(cin, e.issueType);
    cout << "Enter reason: ";
    getline(cin, e.reason);
    events.push_back(e);
    cout << "Event added successfully.\n";
}

void displayEvents() {
    if (events.empty()) {
        cout << "No events to display.\n";
        return;
    }

    cout << "\n--- All Events ---\n";
    for (const auto& e : events) {
        cout << "On " << e.day << ", " << e.issueType << " issue occurred: " << e.reason << "\n";
    }
}

void queryWhy() {
    string day, type;
    cout << "Enter the day: ";
    getline(cin, day);
    cout << "Enter issue type (Water/Electricity): ";
    getline(cin, type);

    for (const auto& e : events) {
        if (e.day == day && e.issueType == type) {
            cout << "On " << e.day << ", " << type << " was not available because: " << e.reason << "\n";
            return;
        }
    }

    cout << "No information found for that query.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- Society Maintenance Expert System ---\n";
        cout << "1. Add Event\n2. Display All Events\n3. Query 'Why' an issue occurred\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addEvent(); break;
            case 2: displayEvents(); break;
            case 3: queryWhy(); break;
            case 4: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
