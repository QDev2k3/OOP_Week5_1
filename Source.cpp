#include "Header.h"

int main() {
    Fraction A,B,C,D;
    cout << "(+)Enter fraction A\n "; cin >> A;
    cout << "\n(+)Enter fraction B\n "; cin >> B;
    cout << "\nA + B = " << A+B ;
    cout << "\nA - B = " << A-B ;
    cout << "\nA * B = " << A*B ;
    cout << "\nA / B = " << A/B ;
    A += 2;
    cout << "\nA += 2 = " << A; 
    A-=2;
    cout << "\nA -= 2 = " << A; 
    C = A++;
    cout << "\nC = A++ = " << C << endl;
    C = ++A;
    cout << "C = ++A = " << C << endl;
    D = ~A;
    cout << "D = ~A = " << D << endl;
    system("pause");
    return 0;
}