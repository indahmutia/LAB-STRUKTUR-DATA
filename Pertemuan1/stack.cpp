#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1; // awalnya kosong

// push 
void push (int value){
    if (top == MAX){
        cout << "Stack Penuh !\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dalam stack \n";
    }
}

//pop
void pop() {
    if (top == 1) {
        cout << "Stack kosong! \n ";
    } else {
        cout <<"\n" << stack[top] <<"dihapus dari stack.\n";
        top--;
    }
}

// nampilin stack
void display() {
    if (top == -1) {
        cout << "Stack kosong\n";
    } else {
        cout << "\nIsi stack : \n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }

        cout << "\nIsi array (index 0 ke MAX-1): \n";
        for (int i = 0; i < top; i++) {
            cout << "[ " << i << " ] " << stack[i] << " ";
        }
        cout << endl;
    }
}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display;
}