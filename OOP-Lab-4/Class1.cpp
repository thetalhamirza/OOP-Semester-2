#include <iostream>
#include <stdio.h>
using namespace std;

class Matrix
{
    int rows, cols;
    double** elements;

    public:

    // Default Constructor

    Matrix()    {
        cout << "\nCalling Default Constructor...\n" << endl;
        this->rows = 0;
        this->cols = 0;
        elements = new double*[rows];
        for (int i=0; i<rows; i++)  {
            elements[i] = new double[cols];
            for (int j = 0; j < cols; j++)  {
                elements[i][j] = 0;
            }
        }
        cout << "\nObject created successfully!\n" << endl;
    }

    // Parameterized Constructor

    Matrix(int rowN, int colN)  {
        cout << "\nCalling Parameterized Constructor...\n" << endl;
        this->rows = rowN;
        this->cols = colN;
        elements = new double*[rows];
        for (int i=0; i<rows; i++)  {
            elements[i] = new double[cols];
            for (int j = 0; j < cols; j++)  {
                elements[i][j] = 0;
            }
        }
        cout << "\nObject created successfully!\n" << endl;
    }

    // Deep Copy Constructor

    Matrix(Matrix& copy) {
        cout << "\nCalling Copy Constructor...\n" << endl;
        this->rows = copy.rows;
        this->cols = copy.cols;
        elements = new double*[rows];
        for (int i=0; i<rows; i++)  {
            elements[i] = new double[cols];
            for (int j = 0; j < cols; j++)  {
                elements[i][j] = copy.elements[i][j];
            }
        }
        cout << "\nObject copied successfully!\n" << endl;
        cout << "\nNew Object:" << endl;
        for (int i=0; i<rows; i++)  {
            printf("[ ");
            for (int j = 0; j < cols; j++)  {
                printf(" %.2f ", elements[i][j]);
            }
            printf(" ]\n");
        }
    }

    // Move Constructor

    Matrix(Matrix&& move)   noexcept   {
        cout << "\nCalling Move Constructor...\n" << endl;
        this->rows = move.rows;
        this->cols = move.cols;
        elements = new double*[rows];
        for (int i=0; i<rows; i++)  {
            elements[i] = new double[cols];
            for (int j = 0; j < cols; j++)  {
                elements[i][j] = move.elements[i][j];
            }
        }
        for (int i=0; i<rows; i++)  {
            delete move.elements[i];
        }
        move.elements = nullptr;
        delete move.elements;
        cout << "\nDeleted Source Object!\n" << endl;
        cout << "\nObject moved successfully!\n" << endl;
        cout << "\nNew Object:" << endl;
        for (int i=0; i<rows; i++)  {
            printf("[ ");
            for (int j = 0; j < cols; j++)  {
                printf(" %.2f ", elements[i][j]);
            }
            printf(" ]\n");
        }
    }


    // Destructor

    ~Matrix() {
        cout << "\nCalling Destructor..." << endl;
        for (int i=0; i<rows; i++)  {
            delete elements[i];
        }
        elements = nullptr;
        delete elements;
        cout << "Object destructed successfully!\n" << endl;
    }

    int getRows() {return rows;}
    int getCols() {return cols;}
    double& at(int r, int c) {
        return elements[r][c];
    }
    void fill(double value) {
        for (int i=0; i<rows; i++)  {
            for (int j = 0; j < cols; j++)  {
                elements[i][j] = value;
            }
        }
        cout << "\nValues filled!\n" << endl;
        for (int i=0; i<rows; i++)  {
            printf("[ ");
            for (int j = 0; j < cols; j++)  {
                printf(" %.2f ", elements[i][j]);
            }
            printf(" ]\n");
        }
    }

    Matrix transpose() {
        Matrix newMat(cols, rows);
        for (int i=0; i<cols; i++)  {
            for (int j = 0; j < rows; j++)  {
                newMat.elements[i][j] = elements[i][j];
            }
        }
        printf("\nTransposed!:\n");
    

        printf("\nBefore:\n");
        for (int i=0; i<rows; i++)  {
            printf("[ ");
            for (int j = 0; j < cols; j++)  {
                printf(" %f ", elements[i][j]);
            }
            printf(" ]\n");
        }
        printf("\n\nAfter:\n");
        for (int i=0; i<cols; i++)  {
            printf("[ ");
            for (int j = 0; j < rows; j++)  {
                printf(" %.2f ", newMat.elements[i][j]);
            }
            printf(" ]\n");
        }
        return newMat;
    }
};


int main()  {

    Matrix defaultMat;
    Matrix paraMat(2,4);
    paraMat.fill(4);
    Matrix newMat(6,3);
    Matrix copyMat(paraMat);
    Matrix moveMat=move(paraMat);

    printf("Rows: %d, Cols: %d", newMat.getRows(), newMat.getCols());
    newMat.fill(5);
    newMat.transpose();
}