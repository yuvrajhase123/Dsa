#include<iostream>
#include<string.h>
#include<cstdlib> // for exit()
using namespace std;

int const size = 5;

struct student {
    int rollno;
    char name[20];
    float SGPA;
};

void accept(struct student list[size]);
void display(struct student list[size]);
void bubblesort(struct student list[size]);
void binarysearch(struct student list[size]);
void insertionsort(struct student list[size]);

int main() {
    struct student data[size];  // Use 'size' instead of 20
    int ch;

    accept(data);  // Get student data
    
    cout << "\n1. Bubble sort\n2. Binary search\n3. Insertion sort\n";
    cout << "Enter your choice: ";
    cin >> ch;
    
    switch(ch) {
        case 1:
            cout << "\nBubble sort\n";
            bubblesort(data);
            display(data);
            break;
        case 2:
            cout << "\nBinary search\n";
            binarysearch(data);
            break;
        case 3:
            cout << "\nInsertion sort\n";
            insertionsort(data);
            display(data);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice!\n";
    }
}

void accept(struct student list[size]) {
    for (int i = 0; i < size; i++) {
        cout << "Enter roll no., name, and SGPA for student " << (i + 1) << ": ";
        cin >> list[i].rollno >> list[i].name >> list[i].SGPA;
    }
}

void display(struct student list[size]) {
    cout << "\nRoll No.\tName\t\tSGPA\n";
    for (int i = 0; i < size; i++) {
        cout << list[i].rollno << "\t\t" << list[i].name << "\t" << list[i].SGPA << endl;
    }
}

void bubblesort(struct student list[size]) {
    struct student temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (list[j].rollno > list[j + 1].rollno) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void binarysearch(struct student list[size]) {
    int lower = 0, upper = size - 1, mid;
    char search[20];
    
    cout << "\nEnter the name of the student you want to search for: ";
    cin >> search;
    
    while (lower <= upper) {
        mid = (lower + upper) / 2;
        
        int cmp = strcmp(list[mid].name, search);
        
        if (cmp < 0) {
            lower = mid + 1;
        } else if (cmp == 0) {
            cout << "\nStudent found: " << list[mid].rollno << "\t" << list[mid].name << "\t" << list[mid].SGPA << endl;
            return;  // Exit function once found
        } else {
            upper = mid - 1;
        }
    }
    
    cout << search << " not found in the list.\n";
}

void insertionsort(struct student list[size]) {
    struct student temp;
    int j;
    
    for (int k = 1; k < size; k++) {
        temp = list[k];
        j = k - 1;
        
        // Insert list[k] into the sorted part of the array
        while (j >= 0 && strcmp(list[j].name, temp.name) > 0) {
            list[j + 1] = list[j];
            --j;
        }
        list[j + 1] = temp;
    }
}
