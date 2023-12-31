#include <iostream>
#include <string>
#include <cmath>

class Quaternion {
    //Real, i, j, k parts respectively
    private:
        double a;
        double i;
        double j;
        double k;
    
    public:
        //Constructor which defaults to Q = 0 + 0i + 0j + 0k
        Quaternion(double real = 0.0, double imag_i = 0.0, double imag_j = 0.0, double imag_k = 0.0) {
            a = real;
            i = imag_i;
            j = imag_j;
            k = imag_k;
        }

        //Finds the conjugate of a quaternion, Q^* = a - bi - cj - dk
        Quaternion conjugate() {
            Quaternion result = Quaternion(a, -i, -j, -k);
            return result;
        }

        //Finds the norm squared of the quaternion
        double norm_sqr() {
            return a*a + i*i + j*j + k*k;
        }

        //Finds the norm of a quaternion, |Q| = sqrt(a^2 + b^2 + c^2 + d^2)
        double norm() {
            return std::sqrt(this->norm_sqr());
        }

        //Defining quaternion addition
        Quaternion operator+(Quaternion const &second) {
            Quaternion result = Quaternion(a + second.a, i + second.i, j + second.j, k + second.k);
            return result;
        }

        //Defines quaternion subtraction as adding the addative inverse
        Quaternion operator-(Quaternion &second) {
            Quaternion result =  *this + (second * -1);
            return result;
        }

        //Defining scalar multiplication of the form Q * a
        Quaternion operator*(double scalar) {
            Quaternion result = Quaternion(a * scalar, i * scalar, j * scalar, k * scalar);
            return result; 
        }

        Quaternion operator/(double scalar) {
            Quaternion result = *this * 1.0/scalar;
            return result;
        }

        //Defining non-commutative quaternion multiplication, ii = jj = kk = ijk = -1
        //(a + bi + cj + dk)(l + mi + nj + ok) = (al - bm - cn - do) + (am + bl + co - dn)i + (an + cl + dm - bo)j + (ao + dl + bn - cm)k
        Quaternion operator*(Quaternion const &second) {
            double res_real = a * second.a - i * second.i - j * second.j - k * second.k;
            double res_i = a * second.i + i * second.a + j * second.k - k * second.j;
            double res_j = a * second.j + j * second.a + k * second.i - i * second.k;
            double res_k = a * second.k + k * second.a + i * second.j - j * second.i;
            Quaternion result = Quaternion(res_real, res_i, res_j, res_k);
            return result;
        }

        //Converting a quaternion to a string for display
        std::string to_string() {
            return std::to_string(a) + " + " + std::to_string(i) + "i + " + std::to_string(j) + "j + " + std::to_string(k) + "k";
        }

        //Setters and Getters
        double get_real() {
            return a;
        }

        void set_real(double real) {
            a = real;
        }

        double get_i() {
            return i;
        }

        void set_i (double imag) {
            i = imag;
        }

        double get_j() {
            return j;
        }

        void set_j(double imag) {
            j = imag;
        }

        double get_k() {
            return k;
        }

        void set_k(double imag) {
            k = imag;
        }
};

//Defines scalar multiplication of the form a * Q
Quaternion operator* (double scalar, Quaternion &quat) {
    return quat.operator*(scalar); 
}

int main() {
    Quaternion quat_one = Quaternion(1, 2, 3, 4);
    Quaternion quat_two = Quaternion(2,3,4,5);
    double norm_one_sqr = quat_one.norm_sqr();
    double norm_one = quat_one.norm();

    std::cout << "Addition is " + (quat_one + quat_two).to_string() + "\n";
    std::cout << "Two minus one is " + (quat_two - quat_one).to_string() + "\n";
    std::cout << "One times two is " + (quat_one * quat_two).to_string() + "\n";
    std::cout << "Two times one is " + (quat_two * quat_one).to_string() + "\n";
    std::cout << "One times scalar 5 is " + (quat_one * 5).to_string() + "\n";
    std::cout << "Scalar 5 times one is " + (5 * quat_one).to_string() + "\n";
    std::cout << "Norm square of one is " + std::to_string(norm_one_sqr) + "\n";
    std::cout << "Norm of two is " + std::to_string(norm_one) + "\n";
    std::cout << "Conjugate of one is " + quat_one.conjugate().to_string() + "\n";
    std::cout << "One is " + quat_one.to_string() + "\n";
    std::cout << "Two is " + quat_two.to_string() + "\n";
}