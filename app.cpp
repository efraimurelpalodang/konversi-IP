#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Untuk fungsi pow()
#include <iomanip> // Untuk std::setw

using namespace std;

// Fungsi untuk mengkonversi bilangan biner ke desimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int length = binary.length();

    // Iterasi setiap digit biner dari kanan ke kiri
    for (int i = 0; i < length; i++) {
        // Jika karakter pada posisi i adalah '1', tambahkan nilai desimalnya
        if (binary[length - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

int main() {
    vector<vector<int>> ipAddresses; // Menyimpan array desimal dari 4 oktet IP
    string ulang, binary;
    
    // Menambahkan data IP
    do {
        vector<int> ipAddress(4); // Menyimpan 4 oktet IP dalam bentuk desimal
        cout << "\nMasukkan IP Address dalam format biner (8 bit per oktet, misalnya 11000000 untuk 192):\n";
        
        // Input biner untuk setiap oktet IP
        for (int i = 0; i < 4; i++) {
            cout << "Oktet " << i + 1 << ": ";
            cin >> binary;

            // Memastikan input adalah biner 8 digit
            if (binary.length() != 8 || binary.find_first_not_of("01") != string::npos) {
                cout << "Input harus berupa angka biner 8 digit!\n";
                return 1; // Menghentikan program jika input tidak valid
            }

            // Mengkonversi biner ke desimal dan menyimpan di vector
            ipAddress[i] = binaryToDecimal(binary);
        }

        // Menyimpan alamat IP yang sudah dikonversi
        ipAddresses.push_back(ipAddress);

        cout << "Apakah Anda ingin memasukkan IP lagi? (ya/tidak): ";
        cin >> ulang;

    } while (ulang == "ya");

    // Menampilkan hasil dalam format tabel yang rapi
    cout << "\nData IP Address yang sudah dikonversi ke desimal:\n";
    cout << string(60, '-') << endl; // Garis pemisah
    cout << left << setw(15) << "Oktet 1" 
          << setw(15) << "Oktet 2" 
          << setw(15) << "Oktet 3" 
          << setw(15) << "Oktet 4" 
          << endl;
    cout << string(60, '-') << endl; // Garis pemisah

    for (const auto& ipAddress : ipAddresses) {
        cout << setw(15) << ipAddress[0] 
              << setw(15) << ipAddress[1] 
              << setw(15) << ipAddress[2] 
              << setw(15) << ipAddress[3] 
              << endl;
    }

    cout << string(60, '-') << endl; // Garis pemisah

    return 0;
}
