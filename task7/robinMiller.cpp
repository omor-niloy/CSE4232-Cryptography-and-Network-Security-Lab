#include<bits/stdc++.h>
using namespace std;

mt19937 rng_engine(chrono::steady_clock::now().time_since_epoch().count()); 
long long rng(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng_engine);
}

long long power(long long a, long long b, long long mod){
    long long r = 1;
    while (b > 0) {
        if (b&1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

bool robinMiller(long long int p, int iterations = 5){
    if (p < 2) return false;
    if (p == 2 || p == 3) return true;
    if (p % 2 == 0) return false;

    long long m = p - 1;
    int b = 0;
    while (m % 2 == 0) {
        m /= 2;
        b++;
    }
    
    for (int i = 0; i < iterations; i++) {
        long long a = rng(2, p - 2);
        long long z = power(a, m, p);
        if (z == 1 || z == p - 1) continue;
    
        bool found = false;
        long long d = -1;
        for (int j = 1; j < b; j++) {
            z = (z * z) % p;
            if (z == p - 1) {
                found = true;
                break;
            } else {
                long long g = __gcd(z - 1, p);
                if (g > 1 && g < p) {
                    d = g;
                }
            }
        }
        if (!found) {
            if (d != -1) cout << "Factor: " << d << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    long long p;
    while (cin >> p) {
        if (robinMiller(p)) {
            cout << p << " is a prime\n\n";
        } else {
            cout << p << " is not a prime\n\n";
        }
    }
    return 0;
}