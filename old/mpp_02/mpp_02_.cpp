#include <iostream>
#include <complex> 
#include <cmath>

using namespace std;

// Template function to multiply two complex numbers and return the magnitude
template<typename T>
T multiplyAndReturnMagnitude(T c1, T d1, T c2, T d2, T* realPart, T* imagPart, T& phase) {
    // Create complex numbers from the given real and imaginary parts
    complex<T> firstComplex(c1, d1);
    complex<T> secondComplex(c2, d2);
    // Multiply the complex numbers
    complex<T> result = firstComplex * secondComplex;

    // Extract the real and imaginary parts of the result
    *realPart = real(result);
    *imagPart = imag(result);
    // Calculate the phase (argument) of the result
    phase = arg(result);

    // Return the magnitude (absolute value) of the result
    return abs(result);
}

// Function to multiply two complex numbers and return the magnitude
// This is a non-template version specifically for double type
double multipleComplex(const complex<double>& firstComplex, const complex<double>& secondComplex, double* realPart, double* imagPart, double& phase) {
    // Multiply the complex numbers
    complex<double> result = firstComplex * secondComplex;

    // Extract the real and imaginary parts of the result
    *realPart = real(result);
    *imagPart = imag(result);
    // Calculate the phase (argument) of the result
    phase = arg(result);

    // Return the magnitude (absolute value) of the result
    return abs(result);
}

// Function to get input values for the complex numbers
void getCinValue(double& c1, double& c2, double& d1, double& d2) {
    cout << "Enter a value for c1: ";
    cin >> c1;
    cout << "Enter a value for c2: ";
    cin >> c2;
    cout << "Enter a value for d1: ";
    cin >> d1;
    cout << "Enter a value for d2: ";
    cin >> d2;
}

int main() {
    double c1, c2, d1, d2;
    double realPart, imagPart, phase;

    // Loop until invalid input is entered
    while (!cin.fail()) {
        // Get input values for the complex numbers
        getCinValue(c1, c2, d1, d2);

        // Using the non-template function
        complex<double> firstComplex(c1, d1);
        complex<double> secondComplex(c2, d2);

        double complexResult = multipleComplex(firstComplex, secondComplex, &realPart, &imagPart, phase);

        cout << "Result magnitude (non-template): " << complexResult << endl;
        cout << "Real part: " << realPart << ", Imaginary part: " << imagPart << endl;
        cout << "Phase (in radians): " << phase << endl;

        // Using the template function
        double complexMagnitude = multiplyAndReturnMagnitude<double>(c1, d1, c2, d2, &realPart, &imagPart, phase);

        cout << "Result magnitude (template): " << complexMagnitude << endl;
        cout << "Real part: " << realPart << ", Imaginary part: " << imagPart << endl;
        cout << "Phase (in radians): " << phase << endl;
    }
}
