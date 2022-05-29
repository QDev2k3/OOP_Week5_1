#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class Matrix {
    private:
        int row,col;
        int **array;
    public:
        Matrix() {}
        Matrix(int row, int col) {
            this->row = row;
            this->col = col;
            array = new int*[row];
            for (int i=0; i<row; i++) {
                array[i] = new int [col];
            }
            for (int i=0; i<row; i++) {
                for (int j=0; j<col; j++) {
                    array[i][j] = 0;
                }
            }
        }
        // M = M1
        Matrix operator=(Matrix M){
            if (&M == this)
                return *this;
            this->row = M.row;
            this->col = M.col;
            array = new int*[row];
            for (int i=0; i<row; i++) {
                array[i] = new int [col];
            }
            for (int i=0 ; i<row; i++) {
                for (int j=0; j<col; j++) {
                    array[i][j] = M.array[i][j];
                }
            }
            return *this;
        }
        // M += M1
        Matrix operator+=(const Matrix& M){
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    array[i][j] += M.array[i][j];
                }
            }   
            return *this;
        }
        // M -= M1
        Matrix operator-=(const Matrix& M){
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    array[i][j] -= M.array[i][j];
                }
            }   
            return *this;
        }
        // M *= M1
        Matrix operator*=(const Matrix& M){
            Matrix P(this->row, M.col);

            for (int i = 0; i < P.row; i++) {
                for (int j = 0; j < P.col; j++) {
                    for (int k = 0; k < this->col; k++) {
                        P.array[i][j] += (this->array[i][k] * M.array[k][j]);
                    }
                }
            }
            return (*this = P);
        }
        // M *= k
        Matrix operator*=(double k){
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    array[i][j] *= k;
                }
            }
            return *this;
        }
        // M++
        Matrix operator ++ (int i) {
            Matrix M(row,col);
            for (int i=0; i<M.row; i++) {
                for (int j=0; j<M.col; j++) {
                    M.array[i][j] = this->array[i][j]++;
                }
            }
            return M;
        }
        // ++M
        Matrix operator ++ () {
            Matrix M(row,col);
            for (int i=0; i<M.row; i++) {
                for (int j=0; j<M.col; j++) {
                    M.array[i][j] = ++this->array[i][j];
                }
            }
            return M;
        }
        // M--
        Matrix operator -- (int i) {
            Matrix M(row,col);
            for (int i=0; i<M.row; i++) {
                for (int j=0; j<M.col; j++) {
                    M.array[i][j] = this->array[i][j]--;
                }
            }
            return M;
        }
        // --M
        Matrix operator -- () {
            Matrix M(row,col);
            for (int i=0; i<M.row; i++) {
                for (int j=0; j<M.col; j++) {
                    M.array[i][j] = --this->array[i][j];
                }
            }
            return M;
        }
        
        friend istream& operator >> (istream &in, Matrix &M);
        friend ostream& operator << (ostream &out, const Matrix &M);
        friend Matrix operator+(Matrix M1, Matrix M2);
        friend Matrix operator-(Matrix M1, Matrix M2);
        friend Matrix operator*(Matrix M1, Matrix M2);
        friend Matrix operator*(Matrix M1, double k);
        friend bool operator == (Matrix M1, Matrix M2);
        friend bool operator != (Matrix M1, Matrix M2);
};

// cin >> M
istream& operator >> (istream &in, Matrix &M) {
    cout << "Enter number of rows and columns: ";
    in >> M.row >> M.col;
    M.array = new int*[M.row];
    for (int i=0; i<M.row; i++) {
        M.array[i] = new int [M.col];
    }
    for (int i=0; i< M.row; i++) {
        cout << "\n  +) Row " << i+1 << ": ";
        for (int j=0; j < M.col; j++) {
            in >> M.array[i][j];
        }
    }
    return in;
}
// cout << M
ostream& operator << (ostream &out, const Matrix &M) {
    for (int i=0; i<M.row; i++) {
        for (int j=0; j<M.col; j++) {
            out << M.array[i][j];
            if (j != M.col-1)
                out << setw(5);
        }
        out << endl;
    }
    return out;
}

// M = M1 + M2
Matrix operator+(Matrix M1, Matrix M2) {
    Matrix M(M1.row,M1.col);
    for (int i=0; i<M.row; i++) {
        for (int j=0; j<M.col; j++) {
            M.array[i][j] = M1.array[i][j] + M2.array[i][j];
        }
    }
    return M;
}

// M = M1 - M2
Matrix operator-(Matrix M1, Matrix M2) {
    Matrix M(M1.row,M1.col);
    for (int i=0; i<M.row; i++) {
        for (int j=0; j<M.col; j++) {
            M.array[i][j] = M1.array[i][j] - M2.array[i][j];
        }
    }
    return M;
}

// M = M1*M2
Matrix operator* (Matrix M1, Matrix M2) {
    Matrix P(M1.row, M2.col);
    for (int i = 0; i < P.row; i++) {
        for (int j = 0; j < P.col; j++) {
            for (int k = 0; k < M1.col; k++) {
                P.array[i][j] += (M1.array[i][k] * M2.array[k][j]);
            }
        }
    }
    return P;
}

// M = M1*k
Matrix operator*(Matrix M1, double k) {
    Matrix M;
    M.row = M1.row;
    M.col = M1.col;
    M.array = new int*[M.row];
    for (int i=0; i<M.row; i++) {
        M.array[i] = new int [M.col];
    }
    for (int i=0 ; i<M.row; i++) {
        for (int j=0; j<M.col; j++) {
            M.array[i][j] = M1.array[i][j]*k;
        }
    }
    return M;
}

// M1 == M2
bool operator == (Matrix M1, Matrix M2) {
    if (M1.col != M2.col || M1.row != M2.row)
        return false;
    for (int i=0; i<M1.row; i++) {
        for (int j=0; j<M1.col; j++) {
            if (M1.array[i][j] != M2.array[i][j])
                return false;
        }
    }
    return true;
}

// M1 != M2
bool operator != (Matrix M1, Matrix M2) {
    if (M1.col != M2.col || M1.row != M2.row)
        return true;
    for (int i=0; i<M1.row; i++) {
        for (int j=0; j<M1.col; j++) {
            if (M1.array[i][j] != M2.array[i][j])
                return true;
        }
    }
    return false;
}