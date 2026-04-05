#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
    }

    void display() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};

vector<Student> students;

// Add Student
void addStudent() {
    Student s;
    s.input();
    students.push_back(s);
    cout << "Student Added Successfully!\n";
}

// View Students
void viewStudents() {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }

    for (auto s : students) {
        s.display();
    }
}

// Search Student
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "Student Found:\n";
            s.display();
            return;
        }
    }

    cout << "Student not found!\n";
}

// Delete Student
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student Deleted!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}