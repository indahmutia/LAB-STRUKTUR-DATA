// Program Selection Sort
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data:\n ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Selection Sort dari terbesar hingga terkecil
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            maxIndex = j;
        }
        int temp = data[i]; 
        data[i] = data[maxIndex];
        data[maxIndex] = temp;
    }

    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}