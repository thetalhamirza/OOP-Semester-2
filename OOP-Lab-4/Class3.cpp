#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class DynamicArray
{
    public:
    int *arr;
    int sizeArray;
    int capacity;

    DynamicArray() {
        arr = new int[0];
        sizeArray = 0;
        capacity = 0;
    }

    DynamicArray(int n) {
        arr = new int[n];
        sizeArray = n;
        capacity = n;
        for (int i=0; i<n; i++) {
            arr[i] = 0;
        }
    }

    DynamicArray(const DynamicArray &copy) {
        arr = new int[copy.sizeArray];
        sizeArray = copy.sizeArray;
        capacity = copy.capacity;
        for (int i=0; i<sizeArray; i++) {
            arr[i] = copy.arr[i];
        }
    }

    DynamicArray(DynamicArray &&move) noexcept {
        arr = move.arr;
        sizeArray = move.sizeArray;
        capacity = move.capacity;
        move.arr = nullptr;
        move.sizeArray = 0;
        move.capacity = 0;
    }

    DynamicArray& operator=(const DynamicArray &copy) {
        if (this == &copy) {
            return *this;
        }
        delete[] arr;
        arr = new int[copy.sizeArray];
        sizeArray = copy.sizeArray;
        capacity = copy.capacity;
        for (int i = 0; i < sizeArray; i++) {
            arr[i] = copy.arr[i];
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray &&move) noexcept {
        if (this == &move) {
            return *this;
        }
        delete[] arr;
        arr = move.arr;
        sizeArray = move.sizeArray;
        capacity = move.capacity;
        move.arr = nullptr;
        move.sizeArray = 0;
        move.capacity = 0;
        return *this;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    int size()  {
        return sizeArray;
    }


    int* at(int index) {
        if (index < 0 || index >= sizeArray) {
            return nullptr;
        }
        return &arr[index];
    }

    void resizeArray(int newsizeArray)    {
        if (newsizeArray <= sizeArray) {
            sizeArray = newsizeArray;
            return;
        }
        int *newArr = new int[newsizeArray];
        for (int i=0; i<sizeArray; i++) {
            newArr[i] = arr[i];
        }
        for (int i=sizeArray; i<newsizeArray; i++) {
            newArr[i] = 0;
        }
        delete[] arr;
        arr = newArr;
        sizeArray = newsizeArray;
        capacity = newsizeArray;
    }

};

int main()  {
    DynamicArray a(5);
    for (int i=0; i<5; i++) {
        *a.at(i) = i;
    }
    DynamicArray b(a);
    for (int i=0; i<5; i++) {
        cout << *b.at(i) << " ";
    }
    cout << endl;
    DynamicArray c;
    c = a;
    for (int i=0; i<5; i++) {
        cout << *c.at(i) << " ";
    }
    cout << endl;
    DynamicArray d;
    d = move(a);
    for (int i=0; i<5; i++) {
        cout << *d.at(i) << " ";
    }
    cout << endl;
    return 0;
}