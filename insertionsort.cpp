#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float SGPA;
};

void insertionSort(Student arr[], int n) {
    // Insertion sort to arrange students by name
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key.name, to one position ahead
        while (j >= 0 && arr[j].name > key.name) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void displayList(Student arr[], int n) {
    // Display the sorted list
    cout << "\nRoll No.\tName\t\tSGPA\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].rollNo << "\t\t" << arr[i].name << "\t" << arr[i].SGPA << endl;
    }
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

    // Sort students by name
    insertionSort(students, n);

    // Display the sorted list
    displayList(students, n);

    return 0;
}
