//
// Created by Turing on 4.04.2022.
//
#include <iostream>

struct node{
    int data;
    struct node *next;
};

struct node *list;

struct node *init();
int add(struct node **list, int number);
void print(struct node*list);
int deleteProcess(struct node **list, int number);
int search(struct node *list, int number);

int main() {
    list = init();
    char c;
    int num, r;

    while(1) {
        printf(">");
        scanf(" %c",&c);

        switch(c) {
            case 'i':
                scanf("%d", &num);
                r = add(&list, num);
                if(r==0) {
                    printf("OUT OF MEMORY.");
                } else if(r==1) {
                    printf("SUCCESS.");
                } else {
                    printf("NODE ALREADY IN LIST.");
                }
                break;

            case 'p':
                print(list);
                break;

            case 's':
                scanf("%d", &num);
                r = search(list, num);
                if(r==0) {
                    printf("NOT FOUND");
                } else {
                    printf("FOUND");
                }
                break;

            case 'd':
                scanf("%d", &num);
                r = deleteProcess(&list, num);
                if(r==0) {
                    printf("NODE NOT FOUND");
                } else {
                    printf("SUCCESS");
                }
                break;

            case 'x':
                free(list);
                exit(0);

            default:
                printf("i number [insert number]\n");
                printf("p [print the list]\n");
                printf("s number [search the given number]\n");
                printf("d number [delete the given number]\n");
                printf("x [free and exit]\n");
        }
        printf("\n");
    }
}

struct node *init() {
    list = NULL;
    return list;
}

int add(struct node **list, int number) {
    struct node *newnode, *temp, *pre;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode==NULL) {
        return 0;
    }

    newnode->data = number;
    if(*list==NULL) {
        *list = newnode;
        newnode->next = NULL;
        return 1;
    }

    temp = *list;

    if(temp->data > number) {
        newnode->next = *list;
        *list = newnode;
        return 1;
    }

    while(temp!=NULL && temp->data < number) {
        pre = temp;
        temp = temp->next;
    }

    if(temp!=NULL && temp->data == number) {
        return 2;
    }
    newnode->next = temp;
    pre->next = newnode;

    return 1;
}

void print(struct node*list) {
    struct node *temp = list;

    if(temp==NULL) {
        printf("EMPTY LIST");
        return;
    }

    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int deleteProcess(struct node **list, int number) {
    struct node *temp, *pre;
    temp = *list;

    if(temp->data==number) {
    *list = temp->next;
    temp->next = NULL;
    free(temp);
    return 1;
    }

    while(temp!=NULL && temp->data!= number) {
        pre = temp;
        temp = temp->next;
    }

    if(temp==NULL) {
       return 0;
    }

    pre->next = temp->next;

    temp->next = NULL;
    free(temp);
    return 1;
}

int search(struct node *list, int number) {
    struct node *temp;
    temp = list;

    while(temp!=NULL && temp->data!= number) {
        temp = temp->next;
    }

    if(temp==NULL) {
        return 0;
    }
    return 1;
}


