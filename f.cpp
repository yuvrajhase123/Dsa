#include<iostream>
#include<fstream> // The fstream library allows us to work with files.
using namespace std;

typedef struct student {
    int roll;
    char div, name[20], add[30];
} stud;

ifstream fin; // An ifstream is an input file stream, i.e., a stream of data used for reading input from a file.
ofstream fout;
fstream fm; // This class describes a file stream in general. It can create files, write to files, and read data from files.

int n;
char fname[20];

void create();
void display();
void insert();
void search(int key);

int main() {
    int ch, x;
    do {
        cout << "\n1. Create\n2. Display\n3. Insert\n4. Search\n5. Exit";
        cout << "\nEnter your choice :";
        cin >> ch;

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                cout << "Enter roll no to search :";
                cin >> x;
                search(x);
                break;
        }
    } while (ch != 5);

    return 0;
}

void create() {
    int i;
    stud s;
    cout << "Enter name of the file :";
    cin >> fname;
    fm.open(fname, ios::out); // This ios prefix is used to open a file to write the output from the user.

    cout << "\nEnter no. of records :";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter roll no :";
        cin >> s.roll;
        cout << "Enter name :";
        cin >> s.name;
        cout << "Enter division :";
        cin >> s.div;
        cout << "Enter address :";
        cin >> s.add;
        fm.write((char*)&s, sizeof(s));
    }

    fm.close();
} // create

void display() {
    int i;
    stud s;
    fin.open(fname);

    cout << "\nROLL NO\tNAME\tDIV\tADDRESS";

    // while(!fin.eof())
    for (i = 0; i < n; i++) {
        fin.read((char*)&s, sizeof(s));
        cout << "\n" << s.roll << "\t" << s.name << "\t" << s.div << "\t" << s.add;
    }

    fin.close();
} // display

void insert() {
    stud s;
    fout.open(fname, ios::app); // Set the stream's position indicator to the end of the stream before each output operation.

    cout << "Enter roll no :";
    cin >> s.roll;
    cout << "Enter name :";
    cin >> s.name;
    cout << "Enter division :";
    cin >> s.div;
    cout << "Enter address :";
    cin >> s.add;
    fout.write((char*)&s, sizeof(s));
    n++;

    fout.close();
}

void search(int key) {
    stud s;
    int flag = 0, i;
    fin.open(fname);

    for (i = 0; i < n; i++) {
        fin.read((char *)&s, sizeof(s));
        if (s.roll == key) {
            cout << "\nRecord is present";
            cout << "\nRoll No." << s.roll;
            cout << "\nName :" << s.name;
            cout << "\nDivision :" << s.div;
            cout << "\nAddress :" << s.add;
            flag = 1;
        }
    }

    if (flag == 0)
        cout << "\nRoll no. : " << key << " is not present in the record";

    fin.close();
}
