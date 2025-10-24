/*
Nama: indah mutia trigana 
NIM: 241401028
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku ke layar
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {             // Loop untuk setiap baris
        for (int j = 0; j < 9; j++) {         // Loop untuk setiap kolom
            cout << board[i][j] << " ";       // Tampilkan isi kotak
            if ((j + 1) % 3 == 0) {           // Setiap 3 kolom, beri spasi tambahan biar rapi
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {               // Setiap 3 baris, beri baris kosong biar kelihatan blok 3x3
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah angka "num" boleh dimasukkan di posisi (row, col)
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Cek baris dan kolom apakah angka sudah ada
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;  // Kalau sudah ada di baris atau kolom, tidak valid
        }
    }

    // Cek sub-kotak 3x3
    int startRow = row - row % 3;  // Menentukan baris awal dari kotak 3x3
    int startCol = col - col % 3;  // Menentukan kolom awal dari kotak 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;  // Kalau angka sudah ada di kotak 3x3, tidak valid
            }
        }
    }

    return true; // Kalau lolos semua, berarti valid
}

// Fungsi utama untuk menyelesaikan Sudoku dengan metode rekursi (backtracking)
bool solveSudoku(vector<vector<int>>& board) {
    // Cari posisi yang kosong (yang nilainya 0)
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) { // Kalau ketemu sel kosong
                // Coba isi angka dari 1 sampai 9
                for (int num = 1; num <= 9; num++) {
                    // Periksa apakah angka valid untuk posisi ini
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num; // Isi angka sementara

                        // Panggil lagi fungsi ini untuk mengisi sel berikutnya
                        if (solveSudoku(board)) {
                            return true; // Kalau berhasil, langsung keluar (berhasil)
                        }

                        // Kalau gagal (tidak ada solusi), kembalikan ke 0 (kosong lagi)
                        board[row][col] = 0;
                    }
                }
                // Kalau semua angka 1-9 dicoba tapi gagal, berarti harus mundur (backtrack)
                return false;
            }
        }
    }
    // Kalau tidak ada lagi sel kosong, berarti Sudoku sudah selesai dipecahkan
    return true;
}

int main() {
    // Inisialisasi papan Sudoku (0 berarti kotak kosong)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board); // Tampilkan papan awal

    // Jalankan pemecah Sudoku
    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board); // Tampilkan hasil Sudoku yang sudah selesai
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}