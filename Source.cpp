#include "Header.h"

int main() {
    Matrix M,N,P,Q,A,B,C;
    cin >> M;
    cout << "M: " << endl;
    cout << M << endl;
    B = M++;
    cout << "B = M++: \n";
    cout << B << endl;
    C = ++M;
    cout << "C = ++M: \n";
    cout << C << endl;
    N = C*2;
    cout << "N = C*2: \n";
    cout << N << endl;
    P = C + N;
    cout << "P = C + N: \n";
    cout << P << endl;
    Q = N - C;
    cout << "Q = N - C: \n";
    cout << Q << endl;
    A = P*Q;
    cout << "A = P*Q: \n";
    cout << A << endl;
    system("pause");
    return 0;
}