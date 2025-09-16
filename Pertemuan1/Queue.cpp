#include <iostream>
using namespace std;

#define max 6
int queue[max];
int front = -1; 
int rear = -1;

// enqueue
void enqueue(int value) {
    if (rear == max - 1) {
        cout << "Queue penuh !\n";
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value; 
        cout << value << " masuk ke queue.\n";
    }
}

// dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue kosong !\n";
    } else {
        cout << queue[front] << " keluar dari queue.\n";
        front++;
    }
}

// tampilin isi queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue kosong !\n";
    } else {
        cout << "Isi queue : ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}