#include <iostream>
using namespace std;

// Deklarasi struktur node
struct node {
    int value;
    node *next;
};

node *head = NULL; // Inisialisasi head
node *tail = NULL; // Inisialisasi tail

// Insert di depan
void insertFirst(int n) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Insert di belakang
void insertLast(int n) {
    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert setelah node dengan nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List Kosong, Insert di Depan Dahulu\n";
        return;
    }

    node *newNode = new node;
    newNode->value = n;
    newNode->next = NULL;

    node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan.\n";
        delete newNode;
    } else {
        newNode->next = p->next;
        p->next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
}

// Cetak isi Linked List
void printList() {
    node *p = head;
    cout << "Isi Linked List : ";
    while (p != NULL) {
        cout << p->value << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

int main() {
    insertFirst(10);
    insertLast(20);
    insertFirst(30);
    insertAfter(25, 20);

    printList();
    return 0;
}