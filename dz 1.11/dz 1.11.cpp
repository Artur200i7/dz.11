#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void encryptCaesar(ifstream& inputFile, ofstream& outputFile, int shift) {
    char ch;
    while (inputFile.get(ch)) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = static_cast<char>((ch - base + shift) % 26 + base);
        }
        outputFile.put(ch);
    }
}

int main() {
    SetConsoleOutputCP(1251);
    ifstream inputFile("inputshifr.txt");
    ofstream outputFile("outputshifr.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    int shift = 3;
    encryptCaesar(inputFile, outputFile, shift);

    inputFile.close();
    outputFile.close();

    cout << "Encryption complete." << endl;

    return 0;
}
