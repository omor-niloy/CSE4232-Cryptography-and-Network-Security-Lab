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

bool lehmannPrimeCheck(long long int p, int t){
    if (p > 2 && p % 2 == 0) return false; 
    for (int i = 0; i < t; i++) {
        long long a = rng(2, p - 1);
        long long x = power(a, (p - 1) / 2, p);
        if (x == 1 || x == p - 1) {
            continue;
        }
        cout << p << " " << a << " " << x << endl;
        return false;
    }
    return true;
}

int main()
{
    long long p;
    while (cin >> p) {
        if (lehmannPrimeCheck(p, 4)) {
            double error = 1.00 / (double) (1 << 4);
            cout << p << " is a prime with a error rate " << fixed << setprecision(10) << error << endl << endl;;
            
        } else {
            cout << p << " is not a prime\n\n";
        }
    }
    return 0;
}