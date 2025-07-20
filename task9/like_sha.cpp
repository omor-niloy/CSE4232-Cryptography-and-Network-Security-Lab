// like md5 code...

#include<bits/stdc++.h>

using namespace std;

mt19937 rng_engine(chrono::steady_clock::now().time_since_epoch().count()); 
unsigned int rng(unsigned int x, unsigned int y) {
    return uniform_int_distribution<unsigned int>(x, y)(rng_engine);
}

class stringHash{
private:
    unsigned int t1, t2, t3, t4, t5;

public:
    stringHash(){
        t1 = 0x5bd1e995;
        t2 = 0x6c8e9cf1;
        t3 = 0x1b873593;
        t4 = 0xe6546b64;
        t5 = 0x85ebca6b;
    }
    string hash(const string& s) {
        unsigned int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0;
        for (unsigned char c : s) {
            h1 = (h5 * t1 + c * t2);
            h2 = (h1 * t2 + c * t3);
            h3 = (h2 * t3 + c * t4);
            h4 = (h3 * t4 + c * t5);
            h5 = (h4 * t5 + c * t1);
        }
        stringstream ss;
        ss << hex << h1 << h2 << h3 << h4 << h5;
        return ss.str();
    }
};

int main()
{
    stringHash sh;

    string input;
    while (getline(cin, input)) {
        string hashValue = sh.hash(input);
        cout << "Hash of \"" << input << "\": " << hashValue << endl;
    }
    return 0;
}