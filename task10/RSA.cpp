#include<bits/stdc++.h>
using namespace std;
#define int long long

mt19937 rng_engine(chrono::steady_clock::now().time_since_epoch().count()); 
long long rng(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng_engine);
}

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int power(int a, int b, int mod) {
    int r = 1;
    while (b > 0) {
        if (b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

int modInverse(int a, int m) {
    int m0 = m, t = 0, y = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        int tmp = m;

        m = a % m;
        a = tmp;
        tmp = t;

        t = y - q * t;
        y = tmp;
    }

    if (y < 0) y += m0;
    return y;
}

void generateKeys(int &e, int &d, int &n) {
    int p, q;
    do {
        p = rng(100, 1000); 
    } while (!isPrime(p));
    do {
        q = rng(100, 1000); 
    } while ((!isPrime(q)) || (q == p)); 

    n = p * q; 

    int phi = (p - 1) * (q - 1); 

    do {
        e = rng(2, phi - 1); 
    } while (__gcd(e, phi) != 1);

    d = modInverse(e, phi);

    cout << "Public Key: (" << e << ", " << n << ")\n";
    cout << "Private Key: (" << d << ", " << n << ")\n";
}

vector<int> encryptMessage(string &message, int e, int n) {
    vector<int> encrypted;
    for (char c : message) {
        int m = c; 
        int ciph = power(m, e, n);
        encrypted.push_back(ciph);
    }
    return encrypted;
}

string decryptMessage(vector<int> &encrypted, int d, int n) {
    string decrypted;
    for (int ciph : encrypted) {
        char m = power(ciph, d, n);
        decrypted.push_back(m); 
    }
    return decrypted;
}


int32_t main()
{
    int e, d, n;
    generateKeys(e, d, n);

    string message;
    getline(cin, message);

    vector<int> encryptedMessage;
    encryptedMessage = encryptMessage(message, e, n);
    cout << "Encrypted Message: ";
    for (int c : encryptedMessage) {
        cout << c << " ";
    }
    cout << endl;

    string decryptedMessage = decryptMessage(encryptedMessage, d, n);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;

}