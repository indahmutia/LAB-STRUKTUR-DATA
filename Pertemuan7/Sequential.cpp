#include <iostream>
using namespace std;

int main() {
    int n, key, posisi = -1;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n];

    cout << "Masukkan elemen data: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key;

    // TODO : Proses pencarian sequential/linear
    for (int i = 0; i < n; i++) {
        if (data[i] == key) {
            posisi = i;      // simpan posisi ketika ditemukan
            break;            // karna uda ketemu
        }
    }

    // Output hasil
    if (posisi != -1)
        cout << "\nData ditemukan di indeks ke-" << posisi << endl;
    else
        cout << "\nData tidak ditemukan." << endl;

    return 0;
}