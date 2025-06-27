//i hate _____
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define lll __int128_t
#define ld long double
#define pb push_back
#define ii pair<int,int>
#define endl "\n"
double pi = 2 * acos(0.0) ;

// mt19937 rng_engine(chrono::steady_clock::now().time_since_epoch().count()); 
mt19937 rng_engine(13);

int rng(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng_engine);
}

vector<int> print_array_randomly(vector<int>a){
    vector<int>res;
    int cnt = 0;;
    while(a.size()) {
        if (cnt == 1000) exit(0);
        int x = rng(0, a.size()-1);
        if (x - 1 == res.size()) {
            cnt++;
            continue;
        }
        res.pb(a[x]);
        a.erase(a.begin()+x);
    }
    return res;
}

vector<int> _permutation(int n){
    vector<int>a;
    for (int i = 1; i <= n; i++) a.pb(i);
    a = print_array_randomly(a);
    // for (auto it : a) cout << it << " "; cout << endl;
    return a;
}

void _print(vector<string>s){
    vector<int>p = _permutation(s.size());
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " " << s[p[i] - 1] << endl;
        if (s[i] == s[p[i] - 1]) exit(0); // skip if same
    }
}

void promod(){
    vector<string>s;
    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                string str = "";
                str += i; str += j; str += k;
                s.pb(str);
            }
        }
    }
    _print(s);
    s.clear();
    for (int i = 'A'; i <= 'Z'; i++) {
        for (int j = 'A'; j <= 'Z'; j++) {
            string str = "";
            str += i; str += j;
            s.pb(str);
        }
    }
    _print(s);
    s.clear();
    for (char i = 'A'; i <= 'Z'; i++) {
        string str = "";
        str += i;
        s.pb(str);  
    }
    _print(s);
}

int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("dictionary.txt", "w", stdout);
    #endif

    int test_cases = 1;
    // cout << test_cases << endl;
    // cin >> test_cases;

    for (int tc = 1 ; tc <= test_cases ; tc++){

        //cout << "Case " << tc << ": ";
        // cout << tc << endl;
        promod();
        //printf("Case %d: %.10lf\n",tc,ans);

    }

    return 0;
}
/*
    problems are the sign of life
*/