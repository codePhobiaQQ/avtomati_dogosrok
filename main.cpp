#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
//#include "./MatrixClass/MatrixClass.h"

int main() {
    std::cout << 100; 
    return 0; 
    /*
    int N;
    std::vector<std::vector<int> > A;

    std::fstream fin("FilesData/matrixes.txt");
    fin >> N;

    A.resize(N);
    int ptr;

    for (int i = 0; i < N; i++) {
        A[i].resize(N);
        for (int j = 0; j < N; j++) {
            fin >> ptr;
            A[i][j] = ptr;
            std::cout << A[i][j];
        }
        std::cout << "\n";
    }
    int result = test(5);
    std::cout << result;
    */
    return 0;
}