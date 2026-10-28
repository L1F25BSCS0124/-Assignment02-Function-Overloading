
#include <iostream>
#include <string>
using namespace std;

// Answer 1: printInfo(string name, int rollNo) runs.
// Step 1: "Sara" matches string.
// Step 2: 'B' is a char, but it can be converted to int.
// Step 3: The character 'B' has ASCII value 66.
// Therefore, Roll No: 66 is printed.

// Answer 2: Adding int printInfo(char grade) does not cause
// a compile error by itself. However, if the return type is changed
// from void to int for the same parameter list, it causes an error
// because functions cannot be overloaded by return type alone.

// Answer 3: These two versions differ only by parameter order:
// printInfo(string name, int rollNo)
// printInfo(int rollNo, string name)

void printInfo(string name) {
    cout << "Name: " << name << endl;
}

void printInfo(string name, int rollNo) {
    cout << "Name: " << name << " | Roll No: " << rollNo << endl;
}

void printInfo(int rollNo, string name) {
    cout << "Roll No: " << rollNo << " | Name: " << name << endl;
}

void printInfo(string name, double cgpa) {
    cout << "Name: " << name << " | CGPA: " << cgpa << endl;
}

void printInfo(char grade) {
    cout << "Grade: " << grade << endl;
}

int main() {
    printInfo("Ali");
    printInfo("Ali", 12);
    printInfo(12, "Ali");
    printInfo("Ali", 3.5);
    printInfo('A');
    printInfo("Sara", 'B');

    return 0;
}
