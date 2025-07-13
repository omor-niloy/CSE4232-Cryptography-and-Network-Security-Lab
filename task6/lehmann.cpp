#include<bits/stdc++.h>
using namespace std;

mt19937 rng_engine(chrono::steady_clock::now().time_since_epoch().count()); 
long long rng(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng_engine);
}

bool lehmannPrimeCheck(long long int p){
    long long a = rng(2, p - 1);
}

int main()
{
    long long p;
}