#include<bits/stdc++.h>
using namespace std;

// mt19937 rng_engine(13);
mt19937 rng_engine(chrono::steady_clock::now().time_since_epoch().count()); 
int rng(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng_engine);
}

class OneTimePadding {
public:
    string key;

    char chEncode(char a, char b){
        a -= 65;
        b -= 64;
        char t = (a + b) % 26 + 65;
        return t;
    }

    char chDecode(char a, char b){
        a -= 65;
        b -= 64;
        char t = (a - b + 26) % 26 + 65;
        return t;
    }

    string encode(string plainText) {
        ifstream file("in1");
        getline(file, key);
        file.close();

        string cipherText;
        int n = plainText.size();
        for (int i = 0; i < n; i++) {
            cipherText += chEncode(plainText[i], key[i]);
        }
        key = key.substr(n, key.size() - n);
        ofstream outFile("in1");
        outFile << key;
        outFile.close();  
        return cipherText;
    }

    string decode(string cipherText) {
        ifstream file("in2");
        getline(file, key);
        file.close();

        string plainText;
        int n = cipherText.size();
        for (int i = 0; i < n; i++) {
            plainText += chDecode(cipherText[i], key[i]);
        }
        key = key.substr(n, key.size() - n);
        ofstream outFile("in2");
        outFile << key;
        outFile.close();
        return plainText;
    }
};

int main() {
    OneTimePadding otp;
    string plainText;
    while (cin >> plainText) {
        string cipherText = otp.encode(plainText);
        cout << "Cipher text: " << cipherText << endl;
        // sleep(2);
        string decodedText = otp.decode(cipherText);
        cout << "Decoded text: " << decodedText << endl;
        cout << endl;
    }
        
    return 0;
}