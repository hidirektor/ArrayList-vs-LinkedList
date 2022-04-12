//
// Created by Turing on 4.04.2022.
//
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    auto begin = chrono::high_resolution_clock::now();
    //Operators
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout << "Ekleme suresi => " << elapsed.count() << " mikro-saniye" << endl;
}

