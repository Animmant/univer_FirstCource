#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <complex> 
#include <cmath>

using namespace std;


template<typename T>
T multiplyAndReturnMagnitude(T c1, T d1, T c2, T d2, T* realPart, T* imagPart, T& phase) {
    complex<T> firstComplex(c1, d1);
    complex<T> secondComplex(c2, d2);
    complex<T> result = firstComplex * secondComplex;

    *realPart = real(result);
    *imagPart = imag(result);
    phase = arg(result);

    return abs(result);
}


double multipleComplex(const complex<double>& firstComplex, const complex<double>& secondComplex, double* realPart, double* imagPart, double& phase){
    complex<double> result = firstComplex * secondComplex;

    *realPart = real(result);
    *imagPart = imag(result);
    // Обчислення фази (аргументу) комплексного числа
    phase = arg(result);

    // Повернення модуля результату
    return abs(result);
}

void getCinValue(double& c1, double& c2, double& d1, double& d2) {
    cout << "Enter a value for c1: ";
    cin >> c1;
    cout << "Enter a value for c2: ";
    cin >> c2;
    cout << "Enter a value for d1:";
    cin >> d1;
    cout << "Enter a value for d2:";
    cin >> d2;
}

int main(){
    double c1, c2, d1, d2;
    double realPart, imagPart, phase;

    getCinValue(c1, c2, d1, d2);
    // Using the template function
    
    double complexMagnitude = multiplyAndReturnMagnitude<double>(c1, d1, c2, d2, &realPart, &imagPart, phase);
    cout << "Result magnitude (template): " << complexMagnitude << endl;
    cout << "Real part: " << realPart << ", Imaginary part: " << imagPart << endl;
    cout << "Phase (in radians): " << phase << endl;

    // Using the non-template function
    complex<double> heroComplex(c1, d1);
    complex<double> popyComplex(c2, d2);
    double complexResult = multipleComplex(heroComplex, popyComplex, &realPart, &imagPart, phase);
    cout << "Result magnitude (non-template): " << complexResult << endl;
    cout << "Real part: " << realPart << ", Imaginary part: " << imagPart << endl;
    cout << "Phase (in radians): " << phase << endl;



  }