#include <iostream>  // buat menampilkan input dari pengguna
#include <vector>    // biar bisa pakai tipe data vector (seperti array dinamis)
using namespace std;

// Fungsi untuk menggabungkan dua bagian array yang udah diurutkan
void merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;   // hitung jumlah data di bagian kiri
    int n2 = right - mid;      // hitung jumlah data di bagian kanan

    vector<int> L(n1), R(n2);  // bikin dua vector sementara buat nyimpan data kiri dan kanan

    // salin data dari array utama ke bagian kiri
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // salin data dari array utama ke bagian kanan
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;    // penanda posisi di bagian kiri
    int j = 0;    // penanda posisi di bagian kanan
    int k = left; // posisi tempat nulis data ke array utama

    // bandingkan data dari kiri dan kanan, masukin yang lebih kecil dulu ke array utama
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {    
            arr[k] = L[i];     // kalau kiri lebih kecil, ambil dari kiri
            i++;               // geser ke data berikutnya di kiri
        } else {               
            arr[k] = R[j];     // kalau kanan lebih kecil, ambil dari kanan
            j++;               // geser ke data berikutnya di kanan
        }
        k++; // pindah ke posisi berikutnya di array utama
    }

    // kalau masih ada sisa data di kiri, masukin semuanya
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // kalau masih ada sisa data di kanan, masukin semuanya juga
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama buat ngatur proses pengurutan pakai merge sort
void mergeSort(vector<int>& arr, int left, int right) {

    if (left >= right) // kalau cuma satu data, berarti udah beres
        return;

    int mid = left + (right - left) / 2; // cari titik tengahnya

    mergeSort(arr, left, mid);      // urutkan bagian kiri dulu
    mergeSort(arr, mid + 1, right); // lalu urutkan bagian kanan
    merge(arr, left, mid, right);   // gabungkan dua bagian itu jadi satu yang udah urut
}

// Fungsi buat nampilin isi array ke layar
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) { // tampilkan semua data satu per satu
        cout << arr[i] << " ";             // tampilkan data dan kasih spasi
    }
    cout << endl; // ganti baris setelah semua data ditampilkan
}

int main() {
    int n; // variabel buat jumlah data
    cout << "Masukkan jumlah elemen data: "; // minta jumlah data dari pengguna
    cin >> n; // baca jumlah data

    vector<int> data(n); // bikin vector dengan ukuran sesuai jumlah data
    cout << "Masukkan elemen-elemen data: "; // minta pengguna masukin datanya
    for (int i = 0; i < n; i++) { // loop buat baca semua data
        cin >> data[i]; // simpan data ke dalam vector
    }

    cout << "Array sebelum diurutkan: "; // tampilkan data sebelum diurutkan
    printArray(data); // tampilkan datanya

    mergeSort(data, 0, n - 1); // jalankan merge sort buat ngurutkan data

    cout << "Array setelah diurutkan: "; // tampilkan data setelah diurutkan
    printArray(data); // tampilkan hasil akhir

    return 0; // program selesai
}