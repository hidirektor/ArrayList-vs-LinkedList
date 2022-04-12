//
// Created by Turing on 12.04.2022.
//

#include <iostream>
#include <chrono>

using namespace std;

struct Node {
    int deger;
    struct Node *sonraki;
};

struct Node *list;

struct Node *olustur();
int ekle(struct Node **list, int number);
void yazdir(struct Node*list);
int sil(struct Node **list, int number);
int ara(struct Node *list, int number);

int main() {
    list = olustur();
    /*
     * 100 elemanlı list için:
     */
    for(int i=1; i<101; i++) {
        ekle(&list, i);
    }

    //List ekrana yazdırma:
    cout << "100 elemanli list: \n";
    yazdir(list);

    //Başa ekleme işlemi:
    auto beginzeroPoint100 = chrono::high_resolution_clock::now();
    ekle(&list, 1);
    auto endzeroPoint100 = chrono::high_resolution_clock::now();
    auto elapsedzeroPoint100 = chrono::duration_cast<chrono::microseconds>(endzeroPoint100 - beginzeroPoint100);

    //Ortaya ekleme işlemi:
    auto beginmidPoint100 = chrono::high_resolution_clock::now();
    ekle(&list, 50);
    auto endmidPoint100 = chrono::high_resolution_clock::now();
    auto elapsedmidPoint100 = chrono::duration_cast<chrono::microseconds>(endmidPoint100 - beginmidPoint100);

    //Sona ekleme işlemi:
    auto beginendPoint100 = chrono::high_resolution_clock::now();
    ekle(&list, 100);
    auto endendPoint100 = chrono::high_resolution_clock::now();
    auto elapsedendPoint100 = chrono::duration_cast<chrono::microseconds>(endendPoint100 - beginendPoint100);

    //List hafızadan temizleme:
    free(list);


    /*
     * 1000 elemanlı list için:
     */
    for(int i=1; i<1001; i++) {
        ekle(&list, i);
    }

    //List ekrana yazdırma:
    cout << "1000 elemanli list: \n";
    yazdir(list);

    //Başa ekleme işlemi:
    auto beginzeroPoint1000 = chrono::high_resolution_clock::now();
    ekle(&list, 1);
    auto endzeroPoint1000 = chrono::high_resolution_clock::now();
    auto elapsedzeroPoint1000 = chrono::duration_cast<chrono::microseconds>(endzeroPoint1000 - beginzeroPoint1000);

    //Ortaya ekleme işlemi:
    auto beginmidPoint1000 = chrono::high_resolution_clock::now();
    ekle(&list, 500);
    auto endmidPoint1000 = chrono::high_resolution_clock::now();
    auto elapsedmidPoint1000 = chrono::duration_cast<chrono::microseconds>(endmidPoint1000 - beginmidPoint1000);

    //Sona ekleme işlemi:
    auto beginendPoint1000 = chrono::high_resolution_clock::now();
    ekle(&list, 1000);
    auto endendPoint1000 = chrono::high_resolution_clock::now();
    auto elapsedendPoint1000 = chrono::duration_cast<chrono::microseconds>(endendPoint1000 - beginendPoint1000);

    //List hafızadan temizleme:
    free(list);

    /*
     * 10000 elemanlı list için:
     */
    for(int i=1; i<10001; i++) {
        ekle(&list, i);
    }

    //List ekrana yazdırma:
    cout << "10000 elemanli list: \n";
    yazdir(list);

    //Başa ekleme işlemi:
    auto beginzeroPoint10000 = chrono::high_resolution_clock::now();
    ekle(&list, 1);
    auto endzeroPoint10000 = chrono::high_resolution_clock::now();
    auto elapsedzeroPoint10000 = chrono::duration_cast<chrono::microseconds>(endzeroPoint1000 - beginzeroPoint1000);

    //Ortaya ekleme işlemi:
    auto beginmidPoint10000 = chrono::high_resolution_clock::now();
    ekle(&list, 5000);
    auto endmidPoint10000 = chrono::high_resolution_clock::now();
    auto elapsedmidPoint10000 = chrono::duration_cast<chrono::microseconds>(endmidPoint10000 - beginmidPoint10000);

    //Sona ekleme işlemi:
    auto beginendPoint10000 = chrono::high_resolution_clock::now();
    ekle(&list, 10000);
    auto endendPoint10000 = chrono::high_resolution_clock::now();
    auto elapsedendPoint10000 = chrono::duration_cast<chrono::microseconds>(endendPoint10000 - beginendPoint10000);

    //List hafızadan temizleme:
    free(list);


    cout << "\n\n100 elemanli list icin: ";
    cout << "\nBasa Ekleme Suresi => " << elapsedzeroPoint100.count() << " mikro saniye" << endl;
    cout << "Ortaya Ekleme Suresi => " << elapsedmidPoint100.count() << " mikro saniye" << endl;
    cout << "Sona Ekleme Suresi => " << elapsedendPoint100.count() << " mikro saniye" << endl;
    cout << "1000 elemanli list icin: ";
    cout << "\nBasa Ekleme Suresi => " << elapsedzeroPoint1000.count() << " mikro saniye" << endl;
    cout << "Ortaya Ekleme Suresi => " << elapsedmidPoint1000.count() << " mikro saniye" << endl;
    cout << "Sona Ekleme Suresi => " << elapsedendPoint1000.count() << " mikro saniye" << endl;
    cout << "10000 elemanli list icin: ";
    cout << "\nBasa Ekleme Suresi => " << elapsedzeroPoint10000.count() << " mikro saniye" << endl;
    cout << "Ortaya Ekleme Suresi => " << elapsedmidPoint10000.count() << " mikro saniye" << endl;
    cout << "Sona Ekleme Suresi => " << elapsedendPoint10000.count() << " mikro saniye" << endl;
}

struct Node *olustur() {
    list = NULL;
    return list;
}

int ekle(struct Node **list, int number) {
    struct Node *newnode, *temp, *pre;
    newnode = (struct Node*)malloc(sizeof(struct Node));

    if(newnode==NULL) {
        return 0;
    }

    newnode->deger = number;
    if(*list==NULL) {
        *list = newnode;
        newnode->sonraki = NULL;
        return 1;
    }

    temp = *list;

    if(temp->deger > number) {
        newnode->sonraki = *list;
        *list = newnode;
        return 1;
    }

    while(temp!=NULL && temp->deger < number) {
        pre = temp;
        temp = temp->sonraki;
    }

    if(temp!=NULL && temp->deger == number) {
        return 2;
    }
    newnode->sonraki = temp;
    pre->sonraki = newnode;

    return 1;
}

void yazdir(struct Node*list) {
    struct Node *temp = list;

    if(temp==NULL) {
        printf("EMPTY LIST");
        return;
    }

    while(temp!=NULL) {
        printf("%d ",temp->deger);
        temp=temp->sonraki;
    }
}

int sil(struct Node **list, int number) {
    struct Node *temp, *pre;
    temp = *list;

    if(temp->deger==number) {
        *list = temp->sonraki;
        temp->sonraki = NULL;
        free(temp);
        return 1;
    }

    while(temp!=NULL && temp->deger!= number) {
        pre = temp;
        temp = temp->sonraki;
    }

    if(temp==NULL) {
        return 0;
    }

    pre->sonraki = temp->sonraki;

    temp->sonraki = NULL;
    free(temp);
    return 1;
}

int ara(struct Node *list, int number) {
    struct  Node *temp;
    temp = list;

    while(temp!=NULL && temp->deger!= number) {
        temp = temp->sonraki;
    }

    if(temp==NULL) {
        return 0;
    }
    return 1;
}