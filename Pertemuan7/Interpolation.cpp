#include <iostream>
#include <algorithm> 
#include <math.h>    
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    int data[N];
    cout << "Masukkan " << N << " data (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    sort(data, data + N);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    // Proses Interpolation Search
    while (low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = (float)(cari - data[low])  / (data[high] - data[low]);
        posisi = floor(posisi1);

        cout << "\n posisi perkiraan: " << posisi << "-> dibulatkan ke " << posisi; 

        if (data[posisi] == cari) {
            flag = 1; 
            break;
        }
        if (data[posisi] > cari)
            high= posisi - 1; 
        else
            low = posisi + 1; 
    }

    cout << "\n\nHasil: ";
    if (flag == 1)
        cout << "Data " << cari << " ditemukan pada indeks ke-" << posisi << endl;
    else
        cout << "Data " << cari << " tidak ditemukan dalam array." << endl;

    return 0;
}