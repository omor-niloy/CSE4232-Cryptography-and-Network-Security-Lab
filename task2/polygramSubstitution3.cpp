#include<bits/stdc++.h>
using namespace std;

class PolygramSubstitution {
public:
    map<string, string> encodings, decodings;
    PolygramSubstitution(string dictionary) {
        ifstream file(dictionary);
        if (!file.is_open()) {
            cerr << "Error opening dictionary file." << endl;
            exit(1);
        }
        string line;
        while (getline(file, line)) {
            int pos = line.find(" ");
            if (line.substr(0, pos) == line.substr(pos + 1)) {
                cerr << "Error: Encoding and decoding strings cannot be the same." << endl;
                exit(1);
            }
            encodings[line.substr(0, pos)] = line.substr(pos + 1);
            decodings[line.substr(pos + 1)] = line.substr(0, pos);
        }
    }
    string encode(string &text) {
        string ciphertext;
        for (int i = 0; i < text.size();) {
            if (i + 2 < text.size()) {
                ciphertext += encodings[text.substr(i, 3)];
                i += 3;
            } else if (i + 1 < text.size()) {
                ciphertext += encodings[text.substr(i, 2)];
                i += 2;
            } else {
                ciphertext += encodings[text.substr(i, 1)];
                i++;
            }
        }
        return ciphertext;
    }
    string decode(string &ciphertext) {
        string text;
        for (int i = 0; i < ciphertext.size();) {
            if (i + 2 < ciphertext.size()) {
                text += decodings[ciphertext.substr(i, 3)];
                i += 3;
            } else if (i + 1 < ciphertext.size()) {
                text += decodings[ciphertext.substr(i, 2)];
                i += 2;
            } else {
                text += decodings[ciphertext.substr(i, 1)];
                i++;
            }
        }
        return text;
    }
};

int main() {
    PolygramSubstitution ps("dictionary.txt");

    string text;
    cin >> text;
    string ciphertext = ps.encode(text);
    string decodedText = ps.decode(ciphertext);
    cout << "Original text: " << text << endl;
    cout << "Encoded text: " << ciphertext << endl;
    cout << "Decoded text: " << decodedText << endl;

    return 0;
}