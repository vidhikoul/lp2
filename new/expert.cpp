#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 100;
const int MAX_QUESTIONS = 5;

struct Employee {
    string name;
    string department;
    string position;
    string questions[MAX_QUESTIONS];
    int ratings[MAX_QUESTIONS]; 
    int questionCount;
};

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Set questions based on position
void setQuestions(Employee &emp) {
    if (emp.position == "Manager") {
        emp.questions[0] = "Leadership";
        emp.questions[1] = "Strategy";
        emp.questions[2] = "Motivation";
        emp.questions[3] = "Decision Making";
        emp.questions[4] = "Delegation";
        emp.questionCount = 5;
    } else if (emp.position == "Developer") {
        emp.questions[0] = "Problem Solving";
        emp.questions[1] = "Coding";
        emp.questions[2] = "Technical Knowledge";
        emp.questions[3] = "Code Quality";
        emp.questions[4] = "Collaboration";
        emp.questionCount = 5;
    } else if (emp.position == "Customer Support") {
        emp.questions[0] = "Communication";
        emp.questions[1] = "Resolution";
        emp.questions[2] = "Patience";
        emp.questions[3] = "Product Knowledge";
        emp.questions[4] = "Satisfaction";
        emp.questionCount = 5;
    } else {
        emp.questionCount = 0;
    }
}

// Get rating from user
int getRating(string q) {
    int r;
    while (true) {
        cout << "Rate " << q << " (1-10): ";
        cin >> r;
        if (r >= 1 && r <= 10) break;
        cout << "Invalid rating. Please enter a number between 1 and 10.\n";
    }
    return r;
}

// Show advice
void printAdvice(int r) {
    if (r >= 8) cout << "  Excellent. Keep it up!\n";
    else if (r >= 6) cout << "  Good. You can improve further.\n";
    else if (r >= 4) cout << "  Needs improvement.\n";
    else cout << "  Poor. Needs serious attention.\n";
}

// Add employee
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Employee limit reached.\n";
        return;
    }

    cin.ignore();
    Employee emp;
    cout << "Enter name: ";
    getline(cin, emp.name);
    cout << "Enter department (IT/Finance/Marketing): ";
    getline(cin, emp.department);
    cout << "Enter position (Manager/Developer/Customer Support): ";
    getline(cin, emp.position);

    setQuestions(emp);

    if (emp.questionCount == 0) {
        cout << "Invalid position entered.\n";
        return;
    }

    for (int i = 0; i < emp.questionCount; i++) {
        emp.ratings[i] = getRating(emp.questions[i]);
    }

    employees[employeeCount++] = emp;
    cout << "Employee added successfully.\n";
}

// View all employees
void viewAll() {
    if (employeeCount == 0) {
        cout << "No employees to show.\n";
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        Employee &emp = employees[i];
        cout << "\n" << emp.name << " | " << emp.department << " | " << emp.position << "\n";
        for (int j = 0; j < emp.questionCount; j++) {
            cout << emp.questions[j] << ": " << emp.ratings[j] << "/10";
            printAdvice(emp.ratings[j]);
        }
        cout << "-------------------------\n";
    }
}

// View specific employee
void viewSpecific() {
    cin.ignore();
    string searchName;
    cout << "Enter employee name to search: ";
    getline(cin, searchName);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].name == searchName) {
            Employee &emp = employees[i];
            cout << "\n" << emp.name << " | " << emp.department << " | " << emp.position << "\n";
            for (int j = 0; j < emp.questionCount; j++) {
                cout << emp.questions[j] << ": " << emp.ratings[j] << "/10";
                printAdvice(emp.ratings[j]);
            }
            return;
        }
    }

    cout << "Employee not found.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Add Employee\n2. View All Employees\n3. View Specific Employee\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewAll(); break;
            case 3: viewSpecific(); break;
            case 4: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
