#include <iostream>
#include <string>
#include <cmath>
#include "quaternion.h"

int main() {
    Quaternion quat_one = Quaternion(1.0, 2.0, 3.0, 4.0);
    Quaternion quat_two = Quaternion(2.0,3.0,4.0,5.0);
    double norm_one_sqr = quat_one.norm_sqr();
    double norm_one = quat_one.norm();

    std::cout << "Addition is " + (quat_one + quat_two).to_string() + "\n";
    std::cout << "Two minus one is " + (quat_two - quat_one).to_string() + "\n";
    std::cout << "One times two is " + (quat_one * quat_two).to_string() + "\n";
    std::cout << "Two times one is " + (quat_two * quat_one).to_string() + "\n";
    std::cout << "One times scalar 5 is " + (quat_one * 5).to_string() + "\n";
    std::cout << "Scalar 5 times one is " + (quat_one * 5.0).to_string() + "\n";
    std::cout << "Norm square of one is " + std::to_string(norm_one_sqr) + "\n";
    std::cout << "Norm of two is " + std::to_string(norm_one) + "\n";
    std::cout << "Conjugate of one is " + quat_one.conjugate().to_string() + "\n";
    std::cout << "One dot Two is " + std::to_string(quat_one.dot(quat_two)) + "\n";
    std::cout << "One is " + quat_one.to_string() + "\n";
    std::cout << "Two is " + quat_two.to_string() + "\n";
}