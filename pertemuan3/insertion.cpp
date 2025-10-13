// Program Insertion Sort
#include <iostream>
using namespace std;
int main() {
    system("CLS");
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Insertion Sort dari terkecil hingga terbesar
    for (int i = 1; i < n; i++) {
        int key = data[i]; // 2, [0] = 23
        int j = i - 1; // 23, 2

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    
    cout << endl;
    return 0;
}