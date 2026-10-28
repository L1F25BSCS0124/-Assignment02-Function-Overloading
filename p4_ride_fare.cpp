
#include <iostream>
#include <fstream>
using namespace std;

double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);

int main() {
    cout << "fare(10) = " << fare(10) << endl;
    cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
    cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
    cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
    cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
    cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;


    int n;
    cout << "How many rides? ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of rides." << endl;
        return 1;
    }

    ofstream fout("rides.txt");

    if (!fout) {
        cout << "Error opening rides.txt" << endl;
        return 1;
    }

    double total = 0.0;

    for (int i = 1; i <= n; i++) {
        char vehicle;
        double km;
        int promo;

        cout << "Ride " << i
             << " vehicle (B/R/C), km, promo %: ";

        cin >> vehicle >> km >> promo;

        double amount;

        if (promo == 0)
            amount = fare(km, vehicle);
        else
            amount = fare(km, vehicle, promo);

        fout << "Ride " << i << " (" << vehicle << "), "
             << km << " km -> Rs. " << amount << endl;

        total += amount;
    }

    fout << "Total collected: Rs. " << total << endl;
    fout.close();

    cout << "Receipts saved to rides.txt" << endl;

    // ---- Part C: Ambiguous call ----

    // fare(10, 40);

    // Error: call of overloaded 'fare(int, int)' is ambiguous
    // Reason: The second argument, int, can convert to either double
    //         for fare(double, double) or char for fare(double, char).
    //         Neither overload is a better match.
    // Fix 1: fare(10, 40.0);
    // Fix 2: fare(10, static_cast<double>(40));

    return 0;
}

// Part A: Function definitions without default arguments

double fare(double km, double ratePerKm) {
    return 100 + km * ratePerKm;
}

double fare(double km, double ratePerKm, bool peakHour) {
    double amount = fare(km, ratePerKm);

    if (peakHour)
        amount *= 1.20;

    return amount;
}

double fare(double km, char vehicle) {
    double rate;

    if (vehicle == 'B')
        rate = 25.0;
    else if (vehicle == 'R')
        rate = 35.0;
    else if (vehicle == 'C')
        rate = 50.0;
    else
        return 0.0;

    return fare(km, rate);
}

double fare(double km, char vehicle, int promoPercent) {
    double amount = fare(km, vehicle);

    if (amount == 0.0)
        return 0.0;

    return amount * (1.0 - promoPercent / 100.0);
}
