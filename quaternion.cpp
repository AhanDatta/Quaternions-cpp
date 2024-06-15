#include <iostream>
#include <string>
#include <cmath>
#include "quaternion.h"

//Constructor
Quaternion::Quaternion(double real, double imag_i, double imag_j, double imag_k) {
    a = real;
    i = imag_i;
    j = imag_j;
    k = imag_k;
}

//Finds the conjugate of a quaternion
Quaternion Quaternion::conjugate() const {
    return Quaternion(a, -i, -j, -k);
}

//Finds the norm squared of the quaternion
double Quaternion::norm_sqr() const {
    return a * a + i * i + j * j + k * k;
}

//Finds the norm of a quaternion
double Quaternion::norm() const {
    return std::sqrt(norm_sqr());
}

//Defines the dot product between quaternion
//i_1*i_2 + j_1*j_2 + k_1*k_2
double Quaternion::dot(Quaternion const &second) const{
    return i*second.i + j*second.j + k*second.k;
}

//Quaternion addition
Quaternion Quaternion::operator+(Quaternion const &second) const {
    return Quaternion(a + second.a, i + second.i, j + second.j, k + second.k);
}

//Quaternion subtraction
Quaternion Quaternion::operator-(Quaternion &second) const {
    return *this + (second * -1);
}

//Scalar multiplication of form Q*a
Quaternion Quaternion::operator*(double scalar) const {
    return Quaternion(a * scalar, i * scalar, j * scalar, k * scalar);
}

//Scalar division
Quaternion Quaternion::operator/(double scalar) const {
    return *this * (1.0 / scalar);
}

//Quaternion multiplication
Quaternion Quaternion::operator*(Quaternion const &second) const {
    double res_real = a * second.a - i * second.i - j * second.j - k * second.k;
    double res_i = a * second.i + i * second.a + j * second.k - k * second.j;
    double res_j = a * second.j + j * second.a + k * second.i - i * second.k;
    double res_k = a * second.k + k * second.a + i * second.j - j * second.i;
    return Quaternion(res_real, res_i, res_j, res_k);
}

//Convert quaternion to string
std::string Quaternion::to_string() const {
    return std::to_string(a) + " + " + std::to_string(i) + "i + " + std::to_string(j) + "j + " + std::to_string(k) + "k";
}

//Getters
double Quaternion::get_real() const {
    return a;
}

double Quaternion::get_i() const {
    return i;
}

double Quaternion::get_j() const {
    return j;
}

double Quaternion::get_k() const {
    return k;
}

//Setters
void Quaternion::set_real(double real) {
    a = real;
}

void Quaternion::set_i(double imag) {
    i = imag;
}

void Quaternion::set_j(double imag) {
    j = imag;
}

void Quaternion::set_k(double imag) {
    k = imag;
}

//Scalar multiplication of form a*Q
Quaternion operator*(double scalar, const Quaternion &quat) {
    return quat.operator*(scalar);
}