#include "MatrixClass.h"
#include <iostream>
#include <vector>

using namespace std;

struct MatrixClass {
    vector<vector<int> > matrix;
    int module;

    MatrixClass(vector<vector<int> > inputMatrix, int inputModule = 3) {
        matrix = inputMatrix;
        module = inputModule;
    }

    vector<int>& operator[](int id) {
        return matrix[id];
    } 

    MatrixClass operator+(MatrixClass A) {
        MatrixClass result = A;
        for (int i = 0; i < matrix.size(); i++) 
        {
            for (int j = 0; j < matrix[0].size(); j++) 
            {
                
                result[i][j] = (result[i][j] + matrix[i][j]) % module;
            }
        }
        return result;
    }

    MatrixClass& operator+=(MatrixClass A) {
        MatrixClass result = A;
        for (int i = 0; i < matrix.size(); i++) 
        {
            for (int j = 0; j < matrix[0].size(); j++) 
            {
                result[i][j] = (result[i][j] + matrix[i][j]) % module;
            }
        }
        *this = result;
        return *this;
    }

    MatrixClass operator*(MatrixClass A) {
        vector<vector<int> > result(matrix[0].size(), vector<int> (matrix[0].size(), 0));
        for (int i = 0; i < matrix[0].size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                for (int k = 0; k < matrix[0].size(); k++)
                {
                    result[i][j] += (result[i][j] + matrix[i][k] * A[k][j]) % module;
                }
            }
        }
        MatrixClass FinalResult(result);
        return FinalResult;
    }

    MatrixClass& operator*=(MatrixClass A) {
        vector<vector<int> > result(matrix[0].size(), vector<int> (matrix[0].size(), 0));
        for (int i = 0; i < matrix[0].size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                for (int k = 0; k < matrix[0].size(); k++)
                {
                    result[i][j] = (result[i][j] + matrix[i][k] * A[k][j]) % module;
                }
            }
        }
        matrix = result;
        return *this;
    }

    MatrixClass transparate() {
        MatrixClass result(vector<vector<int> > (matrix.size(), vector<int> (matrix[0].size(), 0)));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                result[i][j] = matrix[j][i];
            }
        }
        return result;
    }

    MatrixClass pow(int k) {
        MatrixClass result(matrix);
        MatrixClass ptr(matrix);
        for (int i = 0; i < k - 1; i++)
        {
            result *= ptr;
        }
        return result;
    }

    MatrixClass K(int number) {
        for (int i = 0; i < number; i++)
        {
            
        }
        
    }

    void show() {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};