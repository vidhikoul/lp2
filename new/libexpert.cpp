#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> bookRecommendations = {
    {"AI", "Artificial Intelligence by Russell & Norvig"},
    {"DBMS", "Database System Concepts by Silberschatz"},
    {"Web", "HTML & CSS by Jon Duckett"},
    {"ML", "Hands-On Machine Learning with Scikit-Learn by Aurélien Géron"}
};

void recommendBook() {
    string projectType;
    cout << "Enter your project type (AI/DBMS/Web/ML): ";
    getline(cin, projectType);

    if (bookRecommendations.find(projectType) != bookRecommendations.end()) {
        cout << "Recommended Book: " << bookRecommendations[projectType] << "\n";
    } else {
        cout << "Sorry, no recommendation available for this project type.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Library Book Recommendation Expert System ---\n";
        cout << "1. Get Book Recommendation\n2. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: recommendBook(); break;
            case 2: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
