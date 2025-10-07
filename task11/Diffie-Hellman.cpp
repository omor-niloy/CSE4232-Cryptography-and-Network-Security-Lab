#include<bits/stdc++.h>

using namespace std;

mt19937 rng_engine(chrono::steady_clock::now().time_since_epoch().count()); 
long long rng(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng_engine);
}

bool isPrime(int x){
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) 
            return false;
    }
    return true;
}

int power(int a, int b, int mod){
    int r = 1;
    while (b > 0) {
        if (b&1) r = (1LL * r * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return r;
}

bool isPremitive(int a, int q){
    set<int>s;
    for (int i = 1; i < q; i++) {
        s.insert(power(a, i, q));
    }
    return (s.size() == q - 1);
}

void DiffieHellman(){
    int q;
    do {
        q = rng(100, 1000);
    } while (!isPrime(q));

    int a;
    for (int i = 1; i < q; i++) {
        if (isPremitive(i, q)) {
            a = i;
            break;
        }
    }

    cout << q << " " << a << endl;

    int xa = rng(2, q - 1);
    int ya = power(a, xa, q);

    int xb = rng(2, q - 1);
    int yb = power(a, xb, q);

    cout << "\nAlice\npulic key: " << xa << "\nprivate key: " << ya << endl;
    cout << "\nBob\npulic key: " << xb << "\nprivate key: " << yb << endl << endl;

    int ka = power(yb, xa, q);
    int kb = power(ya, xb, q);
    cout << ka << " " << kb << endl;

}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    DiffieHellman();
    
    return 0;
}