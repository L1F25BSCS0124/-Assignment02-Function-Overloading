
#include <iostream>
using namespace std;

// Answer 1: We must write 0 for sms if we want to use the default
// rate value of 2.5, because arguments are passed from left to right.
// We cannot skip the second argument and provide the third one.

// Answer 2: mobileBill(60, , 1.5) gives a compilation error because
// C++ does not allow an argument to be omitted in the middle of a
// function call. Default arguments are used for trailing arguments.

// Default arguments are written in the function prototype, not repeated
// in the function definition.

double mobileBill(int minutes, int sms = 0, double rate = 2.5);

void printLine(char ch = '-', int count = 30);

int main() {
    printLine();

    cout << "Bill 1: " << mobileBill(100) << endl;
    cout << "Bill 2: " << mobileBill(100, 50) << endl;
    cout << "Bill 3: " << mobileBill(100, 50, 2.5) << endl;

    printLine('*', 10);

    cout << "Bill 4: " << mobileBill(100, 0, 2.5) << endl;

    printLine('=');

    return 0;
}

double mobileBill(int minutes, int sms, double rate) {
    return minutes + sms * rate;
}

void printLine(char ch, int count) {
    for (int i = 0; i < count; i++)
        cout << ch;

    cout << endl;
}
