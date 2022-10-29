/*
This program generates random numbers based on the information that is given by the user and displays them along with the average, standard deviation, and variance.

a) Declare variables for min, max, number of samples, delta, and array, and constant array size.
b) Ask user to input min, max , number of samples, and delta.
c) Generate random numbers and store them in the array along with making sure it meets the conditions.
d) display the samples as a table.
e) Calculate average.
f) Calculate standard deviation.
g) Calculate variance.
h) Display average, standard deviation, and variance.
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    // Declare variables
    int n, SIZE = 80; // Only the number of samples and constant size of array are integers
    double low, high, delta, randNum[SIZE], average, standardDev; // Use double for other variables to get answer in with decimals
    double variance = 0;
    // Ask the user to input minimum and maximum numbers until they meet the condition
    do {
    cout << "Enter minimum value: ";
    cin >> low;

    cout << "Enter maximimum value: ";
    cin >> high;
    } while (low > high);

    // Ask the user to input number of samples until it meets the condition
    do {
    cout << "Enter number of samples: ";
    cin >> n;
    } while (1 > n || n > 80);

    // Ask the user to input delta until it meets the condition
    do {
    cout << "Enter the smallest difference between the two samples: ";
    cin >> delta;
    } while (delta > (high - low));

    srand(time(0)); // Generate new numbers every time
    // Generate random numbers that meet the condition and store them in the array
    for (int i = 0; i < n; i++) {
            randNum[i] = delta * ((rand() % (int)(high/delta - low/delta + 1))+ low/delta);
    }

    // Generate table of samples with 3 decimal places, 10 spaces in between, in 4 columns
    for (int i = 0; i < n; i++) {
        if (i % 4 == 0) {
            cout << endl;
        }
        if (randNum[i] > 0) {
            cout << fixed << right << setw(10) << setprecision(3) << "+" << randNum[i];
        }
        else {
            cout << fixed << right << setw(10) << setprecision(3) << " " << randNum[i];
        }
    }
    
    // Calculate average
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += randNum[i];
    }
    average = total / n;
    
    //Calculate variance
    for (int i = 0; i < n; i++) {
       variance += pow(randNum[i] - average, 2);
    }
    variance = variance / 5;
    
    // Calculate standard deviation
    standardDev = sqrt(variance);

    // Display Average, standard deviation, and variance
    cout << endl << endl;
    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << standardDev << endl;
    cout << "Variance: " << variance << endl;

    return 0;
}
