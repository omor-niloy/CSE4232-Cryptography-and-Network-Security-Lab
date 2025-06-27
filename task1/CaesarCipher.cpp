#include<bits/stdc++.h>
using namespace std;

class CaesarCipher {
public:
    char encryptChar(char ch) {
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) return ch;
        int v = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
        return (ch - v + 3) % 26 + v;
    }

    char decryptChar(char ch) {
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) return ch;
        int v = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
        return (ch - v - 3 + 26) % 26 + v;
    }
    string encrypt(string &text) {
        string cipherText;
        for (char ch : text) 
            cipherText += encryptChar(ch);
        return cipherText;
    }
    string decrypt(string &cipherText) {
        string plainText;
        for (char ch : cipherText) 
            plainText += decryptChar(ch);
        return plainText;
    }

};

int main(){
    CaesarCipher cipher;
    string text;
    cin >> text;
    string encrypted = cipher.encrypt(text);
    string decrypted = cipher.decrypt(encrypted);
    cout << "Original: " << text << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}