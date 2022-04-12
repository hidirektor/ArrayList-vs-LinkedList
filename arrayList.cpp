//
// Created by Turing on 12.04.2022.
//
#include <iostream>

using namespace std;

template <class elemType>
class arrayList {
private:
    elemType *array = new elemType[10];
    elemType *lowestP = array;
    elemType lowest;
    bool lowestSet = false;
    int size;
public:
    arrayList(int sizeVal) {
        this->size = sizeVal;
        for(int i = 0 ; i < this->size; i++) {
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
        for(int i = 0; i < this->size; i++) {
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
        for(int i = 0; i < this->size; i++) {
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
        for(int i = 0; i < this->size; i++) {
            if(array[i] != NULL) {
                count++;
            }
            i++;
        }
        return count;
    }
    int maxListSize() const {
        return this->size;
    }
    void print() {
        for(int i = 0; i < this->size; i++) {
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
        for(int i = 0; i < this->size; i++) {
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
        array[this->size-1] = a;
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
            size = this->size;
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

int main() {
    arrayList<int> c(100);
    cout << "The arrayList.h header testing with integers." << endl << endl;
    cout << endl; c.print(); cout << endl;
    if(c.isEmpty()) {
        cout << endl << "array List is empty" << endl;
    } else {
        cout << "array List is not empty" << endl;
    }

    if(c.isFull() == true) {
        cout << "array List is Full" << endl;
    } else if(!c.isFull()) {
        cout << "array List is not Full" << endl;
    }

    cout << "the list size is " << c.listSize() << endl;
    cout << "the max list size is " << c.maxListSize() << endl;

    c.print();
    cout << endl;
    if(c.isItemAtEqual(5, 10)) {
        cout << "Item is equal" << endl;
    } else {
        cout << "Item is not equal" << endl;
    }

    c.insertAt(2,2);
    c.print(); cout << ": insertAt";
    cout << endl;
    c.insertAt(2,3);
    c.print(); cout << ": insertAt";
    cout << endl;
    c.insertEnd(2);
    c.print();cout << ": insertEnd";
    cout << endl;
    c.removeAt(2);
    c.print();cout << ": RemoveAt";
    cout << endl;
    cout << c.retreiveAt(3); cout << ": retreiveAt";
    cout << endl;
    c.replaceAt(4,6);
    c.print();cout << ": replaceAt";
    cout << endl;

    c.replaceAt(0,6);   c.replaceAt(1,6);   c.replaceAt(2,6);   c.replaceAt(3,6);   c.replaceAt(4,6);
    c.replaceAt(5,6);   c.replaceAt(6,6);   c.replaceAt(7,6);
    if(c.isEmpty()) {
        cout << endl << "array List is empty" << endl;
    } else {
        cout << "array List is not empty" << endl;
    }

    if(c.isFull() == true) {
        cout << "array List is Full" << endl;
    } else if(!c.isFull()) {
        cout << "array List is not Full" << endl;
    }
    c.print(); cout << endl;
    c.replaceAt(0,8);   c.replaceAt(1,5);   c.replaceAt(2,5);   c.replaceAt(3,5);   c.replaceAt(4,3);
    c.replaceAt(5,6);   c.replaceAt(6,8);   c.replaceAt(7,8);   c.replaceAt(8,8);   c.replaceAt(9,1);
    if(c.isEmpty()) {
        cout << endl << "array List is empty" << endl;
    } else {
        cout << "array List is not empty" << endl;
    }

    if(c.isFull() == true) {
        cout << "array List is Full" << endl;
    } else if(!c.isFull()) {
        cout << "array List is not Full" << endl;
    }
    c.print(); cout << endl;
    cout << endl << endl << "this is the min: " << c.getMin() << endl << endl << endl;
    c.clearList();
    c.print();cout << ": clear list";
    cout << endl;

    c.~arrayList();

    return 0;
}