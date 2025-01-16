#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <vector>

// Fungsi untuk mengonversi bilangan biner ke desimal
int binaryToDecimal(const std::string &binary) {
    return std::bitset<8>(binary).to_ulong();
}

// Fungsi untuk memproses input biner menjadi format IP
std::string binaryToIP(const std::string &binary) {
    if (binary.length() != 32) {
        return "Input biner harus memiliki panjang 32 bit.";
    }

    // Pisahkan string biner menjadi 4 bagian masing-masing 8 bit
    std::string octet1 = binary.substr(0, 8);
    std::string octet2 = binary.substr(8, 8);
    std::string octet3 = binary.substr(16, 8);
    std::string octet4 = binary.substr(24, 8);

    // Konversi setiap bagian ke desimal
    int decimal1 = binaryToDecimal(octet1);
    int decimal2 = binaryToDecimal(octet2);
    int decimal3 = binaryToDecimal(octet3);
    int decimal4 = binaryToDecimal(octet4);

    // Gabungkan hasil konversi menjadi format IP
    return std::to_string(decimal1) + "." + std::to_string(decimal2) + "." + std::to_string(decimal3) + "." + std::to_string(decimal4);
}

int main() {
    std::string input;
    std::vector<std::string> results; // Menyimpan semua hasil konversi

    do {
        std::cout << "Masukkan bilangan biner 32 bit dengan format (8bit.8bit.8bit.8bit): ";
        std::getline(std::cin, input);

        // Pisahkan input berdasarkan tanda titik
        std::stringstream ss(input);
        std::string octet1, octet2, octet3, octet4;
        std::getline(ss, octet1, '.');
        std::getline(ss, octet2, '.');
        std::getline(ss, octet3, '.');
        std::getline(ss, octet4, '.');

        // Gabungkan input menjadi satu string tanpa tanda titik
        std::string fullBinary = octet1 + octet2 + octet3 + octet4;

        // Konversi ke alamat IP
        results.push_back(binaryToIP(fullBinary));

        // Tanya apakah ingin mengulang
        char choice;
        std::cout << "Apakah Anda ingin memasukkan biner lagi? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(); // Menghapus newline dari buffer

        if (choice == 'n' || choice == 'N') {
            break;
        }

    } while (true);

    // Tampilkan semua hasil akhir
    std::cout << "Hasil konversi IP: " << std::endl;
    for (const auto &ip : results) {
        std::cout << ip << std::endl;
    }

    std::cout << "Program selesai." << std::endl;
    return 0;
}
