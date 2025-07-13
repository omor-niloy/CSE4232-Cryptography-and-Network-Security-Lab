#include<bits/stdc++.h>
using namespace std;

class TransposeCipher {
public:
    int width;
    TransposeCipher(int width = 5){
        this->width = width;
    }

    string encode(string plainText, int m = -1){
        if (m == -1) m = width;
        int n = plainText.size();
        vector<string> rows;
        for(int i = 0; i < n; i += m) {
            rows.push_back(plainText.substr(i, m));
            // cout << rows.back() << endl; 
        }
        string cipherText;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < rows.size(); j++) {
                if(i < rows[j].size()) {
                    cipherText += rows[j][i];
                }
            }
        }
        return cipherText;
    }
    
    string decode(string cipherText, int m = -1) {
        if (m == -1) m = width;
        int n = cipherText.size();
        int rowsCount = (n + m - 1) / m;
        int extra = n % m, eidx = 0;
        vector<string> rows(rowsCount);
        string plainText;
        for(int i = 0; i < n; i++) {
            if (extra > 0) {
                rows[i % rowsCount] += cipherText[i];
                if ((i + 1) % rowsCount == 0) extra--;
                if (extra == 0) eidx = i + 1;
            } else {
                rows[(i - eidx) % (rowsCount - 1)] += cipherText[i];
            }
        }
        for(int i = 0; i < rowsCount; i++) {
            // cout << rows[i] << endl; 
            plainText += rows[i];
        }
        return plainText;
    }
};

int main() {
    TransposeCipher tc;

    string text;
    cin >> text;
    cout << "Input: " << text << endl;
    string encoded = tc.encode(text);
    cout << "Encoded: " << encoded << endl;
    string decoded = tc.decode(encoded);
    cout << "Decoded: " << decoded << endl;


    return 0;
}