#include <iostream>
#include <cmath>
using namespace std;

class Rational {
private:
    int chislitel;
    int  znamenatel;
    int GCD(int a, int b) const{
        if (a < 0)
            a*= -1;
        while(b){
            a%=b;
            std::swap(a,b);
        }
        return a;
    }
    int LCM(int a, int b)const
    {
        return a*b/ GCD(a,b);
    }
    void sokrawenie(){
        int nod =GCD(chislitel,znamenatel);
        chislitel /= nod;
        znamenatel /= nod;
    }
public:

    Rational(int a, int b) {
        chislitel = a;
        znamenatel = b;
        sokrawenie();
    }
    Rational() {
        chislitel = 0;
        znamenatel = 0;
    }

    Rational &operator=(const Rational &other) {
        this->chislitel = other.chislitel;
        this->znamenatel = other.znamenatel;
        sokrawenie();
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Rational rational) {
        return os << rational.chislitel << "/" << rational.znamenatel;
    }

    Rational operator+(const Rational &other) {
        Rational temp;
        temp.chislitel = this->chislitel + other.chislitel;
        temp.znamenatel = this->znamenatel;
        if (this->znamenatel != other.znamenatel) {
            temp.chislitel = chislitel * ((znamenatel * other.znamenatel) / znamenatel) +
                             other.chislitel * ((znamenatel * other.znamenatel) / other.znamenatel);
            temp.znamenatel = znamenatel * other.znamenatel;
        } else {
            temp.chislitel = chislitel + other.chislitel;
            temp.znamenatel = znamenatel;
        }
        sokrawenie();
        return temp;
    }
    Rational operator-(const Rational &other) {
        Rational temp;
        temp.chislitel = this->chislitel - other.chislitel;
        temp.znamenatel = this->znamenatel;
        if (this->znamenatel != other.znamenatel) {
            temp.chislitel = chislitel * ((znamenatel * other.znamenatel) / znamenatel) -
                             other.chislitel * ((znamenatel * other.znamenatel) / other.znamenatel);
            temp.znamenatel = znamenatel * other.znamenatel;
        } else {
            temp.chislitel = chislitel - other.chislitel;
            temp.znamenatel = znamenatel;
        }
        sokrawenie();
        return temp;
    }
    Rational operator/(const Rational &other) {
        Rational temp;
        temp.chislitel = this->chislitel * other.znamenatel;
        temp.znamenatel = this->znamenatel * other.chislitel;
        sokrawenie();
        return temp;
    }

    Rational operator*(const Rational &other) {
        Rational temp;
        temp.chislitel = this->chislitel * other.chislitel;
        temp.znamenatel = this->znamenatel * other.znamenatel;
        sokrawenie();
        return temp;
    }

    Rational &operator*=(const Rational &other) {
        this->chislitel *= other.chislitel;
        this->znamenatel *= other.znamenatel;
        sokrawenie();
        return *this;
    }
    bool operator==(const Rational &other) {
        sokrawenie();
        return this->chislitel == other.chislitel and this->znamenatel == other.znamenatel;
    }
    bool operator!=(const Rational &other) {
        sokrawenie();
        return !(this->chislitel == other.chislitel and this->znamenatel == other.znamenatel);
    }
    Rational operator+=(const Rational &other) {
        Rational temp;
        temp.chislitel = this->chislitel += other.chislitel;
        temp.znamenatel = this->znamenatel;
        if (this->znamenatel != other.znamenatel) {
            temp.chislitel = chislitel * ((znamenatel * other.znamenatel) / znamenatel) +
                             other.chislitel * ((znamenatel * other.znamenatel) / other.znamenatel);
            temp.znamenatel = znamenatel * other.znamenatel;
        } else {
            temp.chislitel += other.chislitel;
            temp.znamenatel = znamenatel;
        }
        sokrawenie();
        return temp;
    }
    Rational &operator/=(const Rational &other) {
        this->chislitel /= other.chislitel;
        this->znamenatel /= other.znamenatel;
        sokrawenie();
        return *this;
    }
    bool operator>(Rational second) const {
        return this->toDouble() > second.toDouble();
    }
    bool operator<(Rational second) const {
        return this->toDouble() < second.toDouble();
    }
    double toDouble() const {
        return (double) this->chislitel / this->znamenatel;
    }
    Rational operator-=(const Rational &other) {
        Rational temp;
        temp.chislitel = this->chislitel -= other.chislitel;
        temp.znamenatel = this->znamenatel;
        if (this->znamenatel != other.znamenatel) {
            temp.chislitel = chislitel * ((znamenatel * other.znamenatel) / znamenatel) +
                             other.chislitel * ((znamenatel * other.znamenatel) / other.znamenatel);
            temp.znamenatel = znamenatel * other.znamenatel;
        } else {
            temp.chislitel -= other.chislitel;
            temp.znamenatel = znamenatel;
        }
        sokrawenie();
        return temp;
    }

    Rational operator-() const {
        return Rational(-this->chislitel, znamenatel);
    }
    Rational POWx2(){
        Rational temp;
        temp.chislitel = this -> chislitel * this ->chislitel;
        temp.znamenatel = this -> znamenatel * this -> znamenatel;
        sokrawenie();
        return temp;
    }
    Rational POW(Rational value, int num){
        Rational temp;
        temp.chislitel = value.chislitel;
        temp.znamenatel = value.znamenatel;
        for (int i = 0; i < num - 1; i++){
            temp.chislitel *= value.chislitel;
            temp.znamenatel *= value.znamenatel;
        }
        sokrawenie();
        return temp;
    }
    Rational POW(Rational value, double num){
        Rational temp;
        temp.chislitel *= 0.5;
        temp.znamenatel *= 0.5;
        sokrawenie();
        return temp;
    }

    Rational sqrt(){
        return Rational(::sqrt(chislitel),::sqrt(znamenatel));
    }
};
class ComplexNumber {
private:
    Rational Real;
    Rational Imag;
public:
    Rational GetReal() {
        return Real;
    }
    Rational GetImag() {
        return Imag;
    }
    void SetReal(Rational value_real) {
        Real = value_real;
    }
    void SetImag(Rational value_imag) {
        Imag = value_imag;
    }
    ComplexNumber &operator=(const ComplexNumber &other) {
        this->Real = other.Real;
        this->Imag = other.Imag;
        return *this;
    }
    ComplexNumber() {
        this->Real;
        this->Imag;
    }
    ComplexNumber(Rational re, Rational im) {
        this->Real = re;
        this->Imag = im;
    }
    friend ostream &operator<<(ostream &os, const ComplexNumber complexNumber) {
        return os << "z = " << complexNumber.Real << " + (" << complexNumber.Imag << ")*i";
    }
    ComplexNumber operator+(const ComplexNumber &other) {
        return ComplexNumber(this->Real + other.Real, this->Imag + other.Imag);
    }
    ComplexNumber operator-(const ComplexNumber &other) {
        return ComplexNumber(this->Real - other.Real, this->Imag - other.Imag);
    }
    ComplexNumber operator*(const ComplexNumber &other) {
        ComplexNumber temp;
        temp.Real = (((this->Real) * (other.Real)) - ((this->Imag) * (other.Imag)));
        temp.Imag = (((this->Real) * (other.Imag)) + ((this->Imag) * (other.Real)));
        return temp;
    }
    ComplexNumber operator/(ComplexNumber& other ) {
        ComplexNumber temp;
        temp.Real = (this->Real*other.Real+this->Imag*other.Imag) / (other.Real*other.Real+other.Imag*other.Imag);
        temp.Imag = (this->Imag*other.Real-this->Real*other.Imag) / (other.Real*other.Real+other.Imag*other.Imag);
        return temp;
    }
    bool operator==(const ComplexNumber& other){
        return this -> Real == other.Real and this -> Imag == other.Imag;
    }
    bool operator!=(const ComplexNumber& other){
        return !(this->Real == other.Real and this->Imag == other.Imag);
    }
    ComplexNumber &operator+=(const ComplexNumber &other) {
        this->Real += other.Real;
        this->Imag += other.Imag;
        return *this;
    }
    ComplexNumber &operator*=(const ComplexNumber &other) {
        this->Real *= other.Real;
        this->Imag *= other.Imag;
        return *this;
    }
    ComplexNumber &operator-=(const ComplexNumber &other) {
        this->Real -= other.Real;
        this->Imag -= other.Imag;
        return *this;
    }
    ComplexNumber &operator/=(const ComplexNumber &other) {
        this->Real /= other.Real;
        this->Imag /= other.Imag;
        return *this;
    }
    ComplexNumber operator-() {
        return ComplexNumber(-(this->Real), (-this->Imag));
    }
    double abs() {
        ComplexNumber temp;
        Rational a(1,2);
        temp.Real = this->Real * this->Real;
        temp.Imag = this->Imag * this->Imag;
        Rational tempe;
        tempe = temp.Real*temp.Real + temp.Imag * temp.Imag;
        return ::sqrt(tempe.toDouble());
    }
    double arg() {
        double pi = 3.14;
        if (this->Real.toDouble() == 0 and this->Imag.toDouble() == 0)
            return 0;
        if (this->Real.toDouble() > 0)
            return atan((this->Imag / this->Real).toDouble());
        if (this->Real.toDouble() < 0 and this->Imag.toDouble() > 0)
            return pi + atan((this->Imag / this->Real).toDouble());
        if (this->Real.toDouble() < 0 and this->Imag.toDouble() < 0)
            return -pi + atan((this->Imag / this->Real).toDouble());
        if (this->Real.toDouble() == 0 and this->Imag.toDouble() > 0)
            return pi / 2;
        else return -pi / 2;
    }
    ComplexNumber POW(ComplexNumber val,int num){
        ComplexNumber finally;
        finally = val;
        for (int i = 0; i <= num ; i++){
            finally *= val;
        }
        return finally;
    }

};
// READY FOR RATIONAL : ALL OVERLOAD/ ALL FOO
// READY FOR COMPLEX : ALL OVERLOAD / ALL FOO / KROME POW ;(
int main() {
    Rational a(1, 2);
    Rational b(1, 3);
    Rational c;
    c = a + b;
    c = a - b;
    c = a * b;
    c = a / b;
    ComplexNumber a1(a,b);
    a1 += a1;
    cout << a1;
}
