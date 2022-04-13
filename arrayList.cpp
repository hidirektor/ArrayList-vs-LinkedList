//
// Created by Turing on 12.04.2022.
//
#include <iostream>
#include <chrono>

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

    bool bosKontrol() const {
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
    bool dolulukKontrol() const {
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
    int listBoyut() const {
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
    int maxBoyut() const {
        return this->size;
    }
    void yazdir() {
        for(int i = 0; i < this->size; i++) {
            cout << array[i] << " ";
        }
    }
    bool denklikKontrol(int a, elemType b) {
        if(array[a] == b) {
            return true;
        }
        return false;
    }
    void ekle(int a, elemType b) {
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
    void sonaEkle(elemType a) {
        array[this->size-1] = a;
    }
    void kaldir(int a) {
        array[a] = 0;
    }
    elemType getir(int a) {
        return array[a];
    }
    void degistir(int a, elemType b) {
        array[a] = b;
    }
    void temizle() {
        for(int i = 0; i < 10; i++) {
            array[i] = 0;
        }
    }
    arrayList operator = ( const arrayList& a){
        return arrayList();
    }

    elemType minDeger() {
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
        return minDeger();
    }
};

int main() {
    arrayList<int> yuzlukArray(100);
    arrayList<int> binlikArray(1000);
    arrayList<int> onbinlikArray(10000);

    /*
     * 100'lük eleman ekleme işlemi:
     */
    for(int i=0; i<100; i++) {
        yuzlukArray.ekle(rand(), i);
    }
    cout << "\n100'luk array: " << endl;
    yuzlukArray.yazdir();

    //Başa ekleme işlemi:
    auto beginzeroPoint100 = chrono::high_resolution_clock::now();
    yuzlukArray.ekle(rand(), 1);
    auto endzeroPoint100 = chrono::high_resolution_clock::now();
    auto elapsedzeroPoint100 = chrono::duration_cast<chrono::microseconds>(endzeroPoint100 - beginzeroPoint100);

    //Ortaya ekleme işlemi:
    auto beginmidPoint100 = chrono::high_resolution_clock::now();
    yuzlukArray.ekle(rand(), 50);
    auto endmidPoint100 = chrono::high_resolution_clock::now();
    auto elapsedmidPoint100 = chrono::duration_cast<chrono::microseconds>(endmidPoint100 - beginmidPoint100);

    //Sona ekleme işlemi:
    auto beginendPoint100 = chrono::high_resolution_clock::now();
    yuzlukArray.sonaEkle(rand());
    auto endendPoint100 = chrono::high_resolution_clock::now();
    auto elapsedendPoint100 = chrono::duration_cast<chrono::microseconds>(endendPoint100 - beginendPoint100);

    /*
     * 1000'lik array için:
     */
    for(int i=0; i<1000; i++) {
        binlikArray.ekle(rand(), i);
    }
    cout << "\n1000'lik array: " << endl;
    binlikArray.yazdir();

    //Başa ekleme işlemi:
    auto beginzeroPoint1000 = chrono::high_resolution_clock::now();
    binlikArray.ekle(rand(), 1);
    auto endzeroPoint1000 = chrono::high_resolution_clock::now();
    auto elapsedzeroPoint1000 = chrono::duration_cast<chrono::microseconds>(endzeroPoint1000 - beginzeroPoint1000);

    //Ortaya ekleme işlemi:
    auto beginmidPoint1000 = chrono::high_resolution_clock::now();
    binlikArray.ekle(rand(), 500);
    auto endmidPoint1000 = chrono::high_resolution_clock::now();
    auto elapsedmidPoint1000 = chrono::duration_cast<chrono::microseconds>(endmidPoint1000 - beginmidPoint1000);

    //Ortaya ekleme işlemi:
    auto beginendPoint1000 = chrono::high_resolution_clock::now();
    binlikArray.sonaEkle(rand());
    auto endendPoint1000 = chrono::high_resolution_clock::now();
    auto elapsedendPoint1000 = chrono::duration_cast<chrono::microseconds>(endendPoint1000 - beginendPoint1000);

    /*
     * 10000'lik array için:
     */
    for(int i=0; i<10000; i++) {
        onbinlikArray.ekle(rand(), i);
    }
    cout << "\n10000'lik array: " << endl;
    onbinlikArray.yazdir();

    //Başa ekleme işlemi:
    auto beginzeroPoint10000 = chrono::high_resolution_clock::now();
    onbinlikArray.ekle(rand(), 1);
    auto endzeroPoint10000 = chrono::high_resolution_clock::now();
    auto elapsedzeroPoint10000 = chrono::duration_cast<chrono::microseconds>(endzeroPoint10000 - beginzeroPoint10000);

    //Ortaya ekleme işlemi:
    auto beginmidPoint10000 = chrono::high_resolution_clock::now();
    onbinlikArray.ekle(rand(), 500);
    auto endmidPoint10000 = chrono::high_resolution_clock::now();
    auto elapsedmidPoint10000 = chrono::duration_cast<chrono::microseconds>(endmidPoint10000 - beginmidPoint10000);

    //Ortaya ekleme işlemi:
    auto beginendPoint10000 = chrono::high_resolution_clock::now();
    onbinlikArray.sonaEkle(rand());
    auto endendPoint10000 = chrono::high_resolution_clock::now();
    auto elapsedendPoint10000 = chrono::duration_cast<chrono::microseconds>(endendPoint10000 - beginendPoint10000);


    cout << "\n\n100 elemanli array icin: ";
    cout << "\nBasa Ekleme Suresi => " << elapsedzeroPoint100.count() << " mikro saniye" << endl;
    cout << "Ortaya Ekleme Suresi => " << elapsedmidPoint100.count() << " mikro saniye" << endl;
    cout << "Sona Ekleme Suresi => " << elapsedendPoint100.count() << " mikro saniye" << endl;
    cout << "1000 elemanli array icin: ";
    cout << "\nBasa Ekleme Suresi => " << elapsedzeroPoint1000.count() << " mikro saniye" << endl;
    cout << "Ortaya Ekleme Suresi => " << elapsedmidPoint1000.count() << " mikro saniye" << endl;
    cout << "Sona Ekleme Suresi => " << elapsedendPoint1000.count() << " mikro saniye" << endl;
    cout << "10000 elemanli array icin: ";
    cout << "\nBasa Ekleme Suresi => " << elapsedzeroPoint10000.count() << " mikro saniye" << endl;
    cout << "Ortaya Ekleme Suresi => " << elapsedmidPoint10000.count() << " mikro saniye" << endl;
    cout << "Sona Ekleme Suresi => " << elapsedendPoint10000.count() << " mikro saniye" << endl;
    yuzlukArray.temizle();
    yuzlukArray.~arrayList();
    binlikArray.temizle();
    binlikArray.~arrayList();
    onbinlikArray.temizle();
    onbinlikArray.~arrayList();
    return 0;
}