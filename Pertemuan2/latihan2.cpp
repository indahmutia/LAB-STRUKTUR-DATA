#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void pop() {
    if (head == NULL) {
        cout << "Stack kosong!" << endl;
        return;
    }

    if (head == tail) {
        cout << tail->data << " di hapus dari stack" << endl;
        delete tail;
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    cout << tail->data << " di hapus dari stack" << endl;
    delete tail;
    tail = temp;
    tail->next = NULL;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    push(5);
    push(10);
    push(15);
    cout << "Angka yang di masukkan ke stack : ";
    display();
    cout << endl;
    cout << "Isi stack : ";
    display();
    cout << endl;
    pop();
    cout << "Isi stack : ";
    display();
    cout << endl;
    return 0;
}