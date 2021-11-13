#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "MatrixClass/MatrixClass.cpp"

using namespace std;

int main() {
    int N;
    int M;
    vector<vector<int> > A;

    fstream fin("FilesData/matrixes.txt");
    fin >> N;
    fin >> M;

    A.resize(N, vector<int > (M, 0));
    int ptr;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            fin >> ptr;
            A[i][j] = ptr;
        }
    }

    MatrixClass Matrix1(A);
    MatrixClass Matrix2(A);
    MatrixClass Matrix3 = Matrix1 * Matrix2;
    Matrix1.show();
    cout << "----------- \n";
    Matrix1.pow(2);
    Matrix3.show();
    cout << "----------- \n";
    Matrix1.show();


    return 0;
}