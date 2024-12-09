#include <iostream>

using namespace std;
template <typename T>
class ArrayList{
private:
    T* startingOfArray;
    int capacity = 10;
    int size = 0;
public:
    ArrayList() {
        capacity = 10;
        size = 0;
        startingOfArray = new T[capacity];
    }

    ArrayList(T value) {
        capacity = 10;
        size = 1;
        startingOfArray = new T[capacity];
        startingOfArray[0] = value;
    }

    void add(T value){
        resizeArrayIfNeeded();
        this->startingOfArray[size] = value;
        this->size++;
    }

    T get(int indexTarget) {
        if (indexTarget >= this->capacity) {
            cout << "Index Out Of Bounds" << endl;
            return 0;
        }
        return startingOfArray[indexTarget];
    }

    void resizeArray() {
        int newSizeOfDynamicArray = this->capacity * 2;
        T* newArray = new T[newSizeOfDynamicArray];
        memcpy(newArray, this->startingOfArray, newSizeOfDynamicArray*sizeof(T));
        delete[] this->startingOfArray;
        this->capacity = newSizeOfDynamicArray;
        this->startingOfArray = newArray;
    }

    void remove(int indexToRemove) {
        if (indexToRemove >= size) {
            return;
        }
        for(int i=indexToRemove+1;i<size;i++){
            this->startingOfArray[i-1] = startingOfArray[i];
        }
        size--;
    }

    void add(int index, T value) {
        if (index > size) {
            cout << "Index not found, current size is " << size << endl;
            return;
        }
        resizeArrayIfNeeded();

        T a = this->startingOfArray[index];
        T b = this->startingOfArray[index];

        for (int i = index; i < size; i++) {
            b = this->startingOfArray[i + 1];
            this->startingOfArray[i + 1] = a;
            a = b;
        }

        this->startingOfArray[index] = value;
        this->size++;
    }

    void resizeArrayIfNeeded() {
        if (size + 1 > capacity) {
            resizeArray();
        }
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }

    void printList() {
        for (int i = 0; i < size; i++) {
            cout << this->startingOfArray[i] << endl;
        }
    }
};
