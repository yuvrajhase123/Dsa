#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float SGPA;
};

// Function to search for a student based on SGPA
void searchBySGPA(Student arr[], int n, float searchSGPA) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].SGPA == searchSGPA) {
            cout << "Student found: Roll No: " << arr[i].rollNo << ", Name: " << arr[i].name << ", SGPA: " << arr[i].SGPA << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with SGPA " << searchSGPA << endl;
    }
}

// Function to perform binary search based on student name
void binarySearchByName(Student arr[], int n, const string &searchName) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].name == searchName) {
            cout << "Student found: Roll No: " << arr[mid].rollNo << ", Name: " << arr[mid].name << ", SGPA: " << arr[mid].SGPA << endl;
            return;
        }
        else if (arr[mid].name < searchName) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Student with name " << searchName << " not found." << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n]; // Array of students

    // Input student details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cin.ignore();  // To consume any newline character left in the input buffer
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].SGPA;
    }

    // Sort the students by name to use binary search
    sort(students, students + n, [](const Student &a, const Student &b) {
        return a.name < b.name;  // Sort by name in ascending order
    });

    // Search for a student by SGPA
    float searchSGPA;
    cout << "\nEnter SGPA to search for: ";
    cin >> searchSGPA;
    searchBySGPA(students, n, searchSGPA);

    // Search for a student by name using binary search
    string searchName;
    cout << "\nEnter name to search for: ";
    cin.ignore();  // To clear the input buffer before taking the name input
    getline(cin, searchName);
    binarySearchByName(students, n, searchName);

    return 0;
}
