#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    float real;
    float imaginary;

public:
    ComplexNumber(float realPart, float imaginaryPart) : real(realPart), imaginary(imaginaryPart) {}

    // addition
    ComplexNumber add(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // subtraction
    ComplexNumber subtract(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    // negation
    ComplexNumber negate() const {
        return ComplexNumber(-real, -imaginary);
    }

    // magnitude
    float magnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    // conjugation
    ComplexNumber conjugate() const {
        return ComplexNumber(real, -imaginary);
    }

    // real part
    float realPart() const {
        return real;
    }

    // imaginary part
    float imaginaryPart() const {
        return imaginary;
    }

    // pretty print
    void prettyPrint() const {
        cout << real << " + " << imaginary << "i";
    }
};

class ComplexList {
private:
    vector<ComplexNumber> numbers;

public:
    ComplexList(const vector<ComplexNumber>& numbersList) : numbers(numbersList) {}

    // Sum method
    ComplexNumber sum() const {
        ComplexNumber result(0, 0);
        for (const auto& num : numbers) {
            result = result.add(num);
        }
        return result;
    }

    // combine lists method
    static ComplexList combineLists(const ComplexList& list1, const ComplexList& list2) {
        vector<ComplexNumber> combinedNumbers;
        combinedNumbers.reserve(list1.numbers.size() + list2.numbers.size());
        combinedNumbers.insert(combinedNumbers.end(), list1.numbers.begin(), list1.numbers.end());
        combinedNumbers.insert(combinedNumbers.end(), list2.numbers.begin(), list2.numbers.end());
        return ComplexList(combinedNumbers);
    }

    
    vector<ComplexNumber> getNumbers() const {
        return numbers;
    }
};

int main() {
    ComplexNumber one = ComplexNumber(3.76, 3.98);
    ComplexNumber two = ComplexNumber(2.58, 7.1);
    ComplexNumber three = ComplexNumber(1.2, 5.3);

      ComplexNumber addition = one.add(two);

    cout << "Addition: ";
    addition.prettyPrint();
    cout << endl;

    
    ComplexNumber subtraction =one.subtract(two);

    cout << "Subtraction: ";
    subtraction.prettyPrint();
    cout << endl;

    
    ComplexNumber negation = one.negate();

    cout << "Negation: ";
    negation.prettyPrint();
    cout << endl;

    
    float magnitude = one.magnitude();

    cout << "Magnitude: " << magnitude << endl;

    
    ComplexNumber conjugation = one.conjugate();

    cout << "Conjugation: ";
    conjugation.prettyPrint();
    cout << endl;

    
    float real = one.realPart();
    cout << "Real part: " << real << endl;

    
    float imaginary = one.imaginaryPart();
    cout << "Imaginary part: " << imaginary << endl;

    
    cout << "Pretty print: ";
    one.prettyPrint();
    cout << endl;

    
    vector<ComplexNumber> complexNum = {one, two, addition, subtraction};
    ComplexList complex_list(complexNum);
    cout << "Sum of complex numbers: ";
    complex_list.sum().prettyPrint();
    cout << endl;

    ComplexList complexList1({one, two});
    ComplexList complexList2({three});

    ComplexList combinedList = ComplexList::combineLists(complexList1, complexList2);

    cout << "Combined list:" << endl;
    for (const auto& num : combinedList.getNumbers()) {
        num.prettyPrint();
        cout << endl;
    }

    return 0;
}
