#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float SGPA;
};

void bubbleSort(Student arr[], int n) {
    // Bubble Sort to arrange students by roll number
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].rollNo > arr[j+1].rollNo) {
                // Swap the students
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
        cout << "\nEnter details for student " << i+1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cin.ignore();  // To consume any newline character left in the input buffer
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].SGPA;
    }

    // Sort the students by Roll No in ascending order
    bubbleSort(students, n);

    // Display the sorted list
    displayList(students, n);

    return 0;
}
