#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string gender;
    string contact;

    void addPatient();
    void displayPatients();
};

void Patient::addPatient() {
    ofstream file("patients.txt", ios::app);
    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;
    cout << "Enter Contact: ";
    cin >> contact;

    file << id << " " << name << " " << age << " " << gender << " " << contact << endl;
    file.close();
    cout << "Patient added successfully!" << endl;
}

void Patient::displayPatients() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "No patient records found!" << endl;
        return;
    }

    int id;
    string name, gender, contact;
    int age;

    cout << "\nPatient Records:\n";
    cout << "--------------------------------------" << endl;
    cout << "ID\tName\tAge\tGender\tContact" << endl;
    cout << "--------------------------------------" << endl;

    while (file >> id >> name >> age >> gender >> contact) {
        cout << id << "\t" << name << "\t" << age << "\t" << gender << "\t" << contact << endl;
    }
    file.close();
}

void menu() {
    Patient patient;
    int choice;

    do {
        cout << "\n--- Hospital Management System ---" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. View All Patients" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            patient.addPatient();
            break;
        case 2:
            patient.displayPatients();
            break;
        case 3:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);
}

int main() {
    menu();
    return 0;
}
