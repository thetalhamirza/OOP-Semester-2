#include <iostream>
#include <stdio.h>
using namespace std;

class Matrix
{

    public:
    int rows, cols;
    int** elements;
    
    Matrix (int rowNum, int colNum) {
        this->rows = rowNum;
        this->cols = colNum;
        elements = new int*[rows];
        for (int i = 0; i < rows; i++)  {
            elements[i] = new int[cols];
            for (int j = 0; j < cols; j++)  {
                elements[i][j] = 0;
            }
        }
    }
    
    int getRows() {return rows;}
    int getColumns() {return cols;}

    void setElement(int x, int y, int content)  {
        elements[x-1][y-1] = content; 
        // cout << "\nValue Added.\n" << endl;
    }
    
    int getElement(int x, int y)    {
        return elements[x-1][y-1];
    }

    void displayElements() {
        printf("\n");
        for (int i = 0; i < rows; i++)  {
            printf("[");
            for (int j = 0; j < cols; j++) {
                printf(" %d ", elements[i][j]);
            }
            printf("]\n");
        }
    }

};

Matrix addMatrix(Matrix mat1, Matrix mat2)    {
    if ((mat1.getRows() != mat2.getRows()) or (mat1.getColumns() != mat2.getColumns())) {
        cout << "\nError: Matrix order not equal!\n" << endl;
        return mat1;        //default
    } else {
        Matrix sumMatrix(mat1.getRows(), mat1.getColumns());
        for (int i=1; i<=mat1.getRows(); i++)    {
            for (int j=1; j<=mat1.getColumns(); j++) {
                int sum = mat1.getElement(i, j) + mat2.getElement(i, j);
                sumMatrix.setElement(i, j, sum);
            }
        }
        cout << "\nMatrices added successfully!\n" << endl;
        // sumMatrix.displayElements();
        return sumMatrix;
    }
}




int main() {
    Matrix m1(3, 3);
    Matrix m2(3, 3);
    Matrix m3(4, 4);

    // m1.displayElements();
    // m2.displayElements();

    // TESTING

    // m1.setElement(1, 1, 63);
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            m1.setElement(i,j,2);
            m2.setElement(i,j,3);
        }
    }

    m1.displayElements();
    m2.displayElements();
    

    Matrix newMatrix = addMatrix(m1, m2);
    newMatrix.displayElements();


};