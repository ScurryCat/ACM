#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const ll mod = 998244353;
const ll inv3 = 332748118;

ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

inline void qwq_(){
    ll n, k;
    string a, b;
    cin >> n >> k >> a >> b;

    // int n = a.size();

    ll ca = 0, cb = 0, cc = 0;

    for(int i = 0; i < n; i++){
        ca += a[i] == '1';
        cb += b[i] == '1';
        cc += a[i] != b[i];
    }

    auto f = [&](ll x){
        return x * (n - x) % mod;
    };

    ll pw = qpow(2, k);

    ll cntA, cntB, cntC;

    if(k & 1){
        cntA = cntB = cntC = (pw + 1) % mod * inv3 % mod;
    }else{
        cntA = cntB = (pw + 2) % mod * inv3 % mod;
        cntC = (pw - 1 + mod) % mod * inv3 % mod;
    }

    ll ans = 0;
    ans = (ans + cntA * f(ca)) % mod;
    ans = (ans + cntB * f(cb)) % mod;
    ans = (ans + cntC * f(cc)) % mod;

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        qwq_();
    }

    return 0;
}