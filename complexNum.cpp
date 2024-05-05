#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    float real;
    float imaginary;

public:
    
    ComplexNumber(float Real, float Imaginary) : real(Real), imaginary(Imaginary) {}

    // addition
    ComplexNumber add(const ComplexNumber& other) const {

        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // subtraction
    ComplexNumber subtract(const ComplexNumber& other) const {

        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    // magnitude
    float magnitude() const {

        return sqrt(real * real + imaginary * imaginary);
    }

    
    string prettyPrint() const {

        return to_string(real) + " + " + to_string(imaginary) + "i";
    }
};

class ComplexList {
private:
    vector<ComplexNumber> numbers;

public:
    
    ComplexList(const vector<ComplexNumber>& numbersList) : numbers(numbersList) {}

    //sum
    ComplexNumber sum() const {
        ComplexNumber result(0, 0);

        for (const auto& num : numbers) {

            result = result.add(num);
        }
        return result;
    }
};

int main() {
    
    ComplexNumber one = ComplexNumber(5.64, 7.0);
    ComplexNumber two = ComplexNumber(2.3, 1.1);

    ComplexNumber three = one.add(two);

    cout << three.prettyPrint() << endl; 

    ComplexNumber four = one.subtract(two);

    cout << four.prettyPrint() << endl; 

    float magnitude = one.magnitude();

    cout << magnitude << endl; 

    ComplexList list({one, two, three, four});
    
    ComplexNumber sum = list.sum();

    cout << sum.prettyPrint() << endl; 
    
    return 0;
}
