#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include <string>
#include <cmath>

class Quaternion {
private:
    double a;
    double i;
    double j;
    double k;

public:
    Quaternion(double real = 0.0, double imag_i = 0.0, double imag_j = 0.0, double imag_k = 0.0);

    Quaternion conjugate() const;
    double norm_sqr() const;
    double norm() const;
    double dot(Quaternion const &second) const;

    Quaternion operator+(Quaternion const &second) const;
    Quaternion operator-(Quaternion &second) const;
    Quaternion operator*(double scalar) const;
    Quaternion operator/(double scalar) const;
    Quaternion operator*(Quaternion const &second) const;

    std::string to_string() const;

    double get_real() const;
    void set_real(double real);
    double get_i() const;
    void set_i(double imag);
    double get_j() const;
    void set_j(double imag);
    double get_k() const;
    void set_k(double imag);
};

Quaternion operator*(double scalar, const Quaternion &quat);

#endif