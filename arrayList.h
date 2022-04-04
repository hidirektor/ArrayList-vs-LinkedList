#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
#include <array>
using namespace std;

template <class elemType>
class arrayList {
private:
    elemType *array = new elemType[10];
    elemType *lowestP = array;
    elemType lowest;
    bool lowestSet = false;
    int size = 10;
public:
    arrayList() {
        for(int i = 0 ; i < 10; i++) {
            array[i] = 0;
        }
    }
    ~arrayList() {
        delete [] array;
        delete lowestP;
    }

    bool isEmpty() const {
        bool elementState = true;
        int i = 0;
        for(int i = 0; i < 10; i++) {
            if(array[i] != 0) {
                elementState = false;
            }
            i++;
        }
        return elementState;
    }
    bool isFull() const {
        bool elementState = true;
        int i = 0;
        for(int i = 0; i < 10; i++) {
            if(array[i] == NULL) {
                return (elementState = false);
            }
            i++;
        }
        return elementState;
    }
    int listSize() const {
        int i = 0;
        int count = 0;
        for(int i = 0; i < 10; i++) {
            if(array[i] != NULL) {
                count++;
            }
            i++;
        }
        return count;
    }
    int maxListSize() const {
        return 10;
    }
    void print() {
        for(int i = 0; i < 10; i++) {
            cout << array[i] << " ";
        }
    }
    bool isItemAtEqual(int a, elemType b) {
        if(array[a] == b) {
            return true;
        }
        return false;
    }
    void insertAt(int a, elemType b) {
        elemType temp;
        bool entered = false;
        for(int i = 0; i < 10; i++) {
            if (i == a ) {
                entered = true;
                temp = array[i];
                array[i] = b;
            }
            if(entered && i > a) {
                elemType tempTwo;
                tempTwo = array[i];
                array[i] = temp;
                temp = tempTwo;
            }
        }
    }
    void insertEnd(elemType a) {
        array[9] = a;
    }
    void removeAt(int a) {
        array[a] = 0;
    }
    elemType retreiveAt(int a) {
        return array[a];
    }
    void replaceAt(int a, elemType b) {
        array[a] = b;
    }
    void clearList() {
        for(int i = 0; i < 10; i++) {
            array[i] = 0;
        }
    }
    arrayList operator = ( const arrayList& a){
        return arrayList();
    }

    elemType getMin() {
        if (!lowestSet) {
            lowest = *lowestP;
            lowestSet = true;
        }
        if(size == 0 ) {
            size = 10;
            return lowest;
        } else {
            if(*lowestP < lowest && *lowestP != 0) {
                lowest = *lowestP;
            }
            lowestP++;
            size--;
        }
        return getMin();
    }
};

#endif /* ARRAYLIST_H_ */