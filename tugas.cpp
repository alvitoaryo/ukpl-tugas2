#include <iostream>
#include <cassert>

using namespace std;

int tambah(int a, int b) {
    return a + b;
}

int kurang(int a, int b) {
    return a - b;
}

int kali(int a, int b) {
    return a * b;
}

int bagi(int a, int b) {
    if (b == 0) {
        throw "Tidak bisa melakukan pembagian dengan 0!";
    }
    return a / b;
}

int main() {
    int a, b, hasil;
    char op;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;

    try {
        switch (op) {
            case '+':
                hasil = tambah(a, b);
                break;
            case '-':
                hasil = kurang(a, b);
                break;
            case '*':
                hasil = kali(a, b);
                break;
            case '/':
                hasil = bagi(a, b);
                break;
            default:
                throw "Operator tidak valid!";
        }
        cout << "Hasil: " << hasil << endl;
    }
    catch (const char* msg) {
        cerr << "Error: " << msg << endl;
        return 1;
    }

    // Boundary Value Analysis testing
    assert(tambah(1, 1) == 2);
    assert(tambah(0, 0) == 0);
    assert(tambah(-1, -1) == -2);
    assert(kurang(1, 1) == 0);
    assert(kurang(0, 0) == 0);
    assert(kurang(-1, -1) == 0);
    assert(kali(2, 2) == 4);
    assert(kali(0, 0) == 0);
    assert(kali(-2, 2) == -4);
    assert(bagi(2, 2) == 1);
    assert(bagi(0, 2) == 0);
    assert(bagi(-2, 2) == -1);

    // State Transition Testing
    assert(tambah(0, 1) == 1);
    assert(tambah(1, 0) == 1);
    assert(kurang(1, 0) == 1);
    assert(kurang(0, 1) == -1);
    assert(kali(0, 2) == 0);
    assert(kali(2, 0) == 0);
    assert(bagi(0, 2) == 0);
    assert(bagi(2, 1) == 2);

    cout << "Semua pengujian telah berhasil dilakukan!" << endl;

    return 0;
}

