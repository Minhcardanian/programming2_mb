#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct ComplexNumber {
    double real;
    double imag;
    double magnitude;
};

int main() {
    std::ifstream inFile("In.txt");
    if (!inFile.is_open()) {
        std::cerr << "Could not open file In.txt\n";
        return 1;
    }
    int N;
    inFile >> N;
    std::vector<ComplexNumber> numbers;
    numbers.reserve(N);
    for (int i = 0; i < N; ++i) {
        double r, im;
        inFile >> r >> im;
        ComplexNumber cn;
        cn.real = r;
        cn.imag = im;
        cn.magnitude = std::sqrt(r*r + im*im);
        numbers.push_back(cn);
    }
    inFile.close();
    std::sort(numbers.begin(), numbers.end(), [](auto &a, auto &b){
        return a.magnitude > b.magnitude;
    });
    int limit = (N < 5) ? N : 5;
    for (int i = 0; i < limit; ++i) {
        std::cout << std::fixed << std::setprecision(2)
                  << "(" << numbers[i].real << ", " << numbers[i].imag << ") "
                  << numbers[i].magnitude << "\n";
    }
    return 0;
}

