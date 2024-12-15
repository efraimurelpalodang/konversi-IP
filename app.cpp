#include <iostream>
#include <cmath>

using namespace std;

// fungsi untuk mengkonversi bilangan binner ke decimal
int binnaryToDecimal(string binary) {
  int decimal = 0;
  int length = binary.length();

  // iterasi setiap digit binner dari kanan ke kiri
  for (int i = 0; i < length; i++) {
    // jika karakter pada posisi i adalah '1', tambahkan nilai decimalnya
    if (binary[length - 1 - i] == '1') {
      decimal += pow(2, i);
    }
  }

  return decimal;
  
}

int main() {
  string binary, ulang;
  int arr[4], n = 4;

  for (int i = 0; i < n; i++ ) {
    cout<<"Masukkan IP : ";
    cin>>binary;
    int decimal = binnaryToDecimal(binary);
    arr[i] = decimal;
  }

  cout <<"\nIp Address : "<<arr[0]<<"."<<arr[1]<<"."<<arr[2]<<"."<<arr[3];

  return 0;
}