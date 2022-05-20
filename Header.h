#include <iostream>
#include <math.h>
using namespace std;

// Tìm ước chung nn, dùng để tối giản phân số
int gcd(int a, int b) {
    if (a==b) return a;
    if (a>b) return gcd(a-b,b);
    if (a<b) return gcd(b-a,a);
}

class Fraction {
    private:
        // Tử số, Mẫu số
        int numerator, denominator;  
    public:
        Fraction(int a=0, int b=0) {
            numerator = a;
            denominator = b;
        }
        // Hàm rút gọn phân số tối giản
        void optimize() { 
            int divisor = gcd(abs(numerator), abs(denominator));
            numerator /= divisor;
            denominator /= divisor;
        }
        // A += n
        void operator += (int x){
            numerator += x;
            denominator += x;
            optimize();
        }
        // A += B
        void operator += (Fraction F2){
            this->numerator = this->numerator*F2.denominator + F2.numerator*this->denominator;
            this->denominator = this->denominator * F2.denominator;
            optimize();
        }
        // A -= n
        void operator -= (int x){
            numerator -= x;
            denominator -= x;
            optimize();
        }
        // A -= B
        void operator -= (Fraction F2){
            this->numerator = this->numerator*F2.denominator - F2.numerator*this->denominator;
            this->denominator = this->denominator * F2.denominator;
            optimize();
        }
        // A *= n
        void operator *= (int x){
            numerator *= x;
            optimize();
        }
        // A /= n
        void operator /= (int x){
            denominator *= x;
            optimize();
        }
        // ++A
        Fraction operator++ (){
            Fraction F;
            F.numerator = ++numerator;
            F.denominator = ++denominator;
            return F;
        }
        // A++
        Fraction operator++ (int i){
            Fraction F;
            F.numerator = numerator++;
            F.denominator = denominator++;
            return F;
        }
        // --A
        Fraction operator-- (){
            Fraction F;
            F.numerator = --numerator;
            F.denominator = --denominator;
            return F;
        }
        // A--
        Fraction operator-- (int i){
            Fraction F;
            F.numerator = numerator--;
            F.denominator = denominator--;
            return F;
        }
        // B = ~A <=> B = 1/A
        Fraction operator ~ () {
            Fraction F;
            F.numerator = denominator;
            F.denominator = numerator;
            return F;
        }
        // Các toán tử tương ứng >>, <<, +, -, *, /, ==, !=, >, >=, <, <=
        friend istream & operator >> (istream &in, Fraction &F);
        friend ostream & operator << (ostream &out, const Fraction &F);
        friend Fraction operator + (Fraction &F1, Fraction &F2);
        friend Fraction operator - (Fraction &F1, Fraction &F2);
        friend Fraction operator * (Fraction &F1, Fraction &F2);
        friend Fraction operator / (Fraction &F1, Fraction &F2);
        friend bool operator == (Fraction F1, Fraction F2);
        friend bool operator != (Fraction F1, Fraction F2);
        friend bool operator > (Fraction F1, Fraction F2);
        friend bool operator >= (Fraction F1, Fraction F2);
        friend bool operator < (Fraction F1, Fraction F2);
        friend bool operator <= (Fraction F1, Fraction F2);
};

istream & operator >> (istream &in, Fraction &F) {
    cout << "   Enter numerator: ";
    in >> F.numerator;
    cout << "    Enter denominator: ";
    in >> F.denominator;
    while (F.denominator == 0) {
        cout << "(!) Invalid denominator, please enter again: ";
        in >> F.denominator;
    }
    F.optimize();
    return in;
}

ostream & operator << (ostream &out, const Fraction &F) {
    out << F.numerator << "/" << F.denominator;
    return out;
}

Fraction operator + (Fraction &F1, Fraction &F2) {
    int num = F1.numerator*F2.denominator + F2.numerator*F1.denominator;
    int den = F1.denominator * F2.denominator;
    int div = gcd(abs(num), abs(den));
    num /= div; den /= div;
    return Fraction(num,den);
}

Fraction operator - (Fraction &F1, Fraction &F2) {
    int num = F1.numerator*F2.denominator - F2.numerator*F1.denominator;
    int den = F1.denominator * F2.denominator;
    int div = gcd(abs(num), abs(den));
    num /= div; den /= div;
    return Fraction(num,den);
}

Fraction operator * (Fraction &F1, Fraction &F2) {
    int num = F1.numerator * F2.numerator;
    int den = F1.denominator * F2.denominator;
    int div = gcd(abs(num), abs(den));
    num /= div; den /= div;
    return Fraction(num,den);
}

Fraction operator / (Fraction &F1, Fraction &F2) {
    int num = F1.numerator * F2.denominator;
    int den = F1.denominator * F2.numerator;
    int div = gcd(abs(num), abs(den));
    num /= div; den /= div;
    return Fraction(num,den);
}

bool operator == (Fraction F1, Fraction F2) {
    F1.optimize(); F2.optimize();
    return (F1.numerator == F2.numerator && F1.denominator == F2.denominator);
}

bool operator != (Fraction F1, Fraction F2) {
    F1.optimize(); F2.optimize();
    return !(F1.numerator == F2.numerator && F1.denominator == F2.denominator);
}

bool operator > (Fraction F1, Fraction F2) {
    int x = F1.numerator*F2.denominator - F1.denominator*F2.numerator;
    return (x > 0);
}

bool operator >= (Fraction F1, Fraction F2) {
    int x = F1.numerator*F2.denominator - F1.denominator*F2.numerator;
    return (x >= 0);
}

bool operator < (Fraction F1, Fraction F2) {
    int x = F1.numerator*F2.denominator - F1.denominator*F2.numerator;
    return (x < 0);
}

bool operator <= (Fraction F1, Fraction F2) {
    int x = F1.numerator*F2.denominator - F1.denominator*F2.numerator;
    return (x <= 0);
}