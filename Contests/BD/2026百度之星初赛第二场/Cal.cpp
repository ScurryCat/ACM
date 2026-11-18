#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

ll p[10000];

void fun(ll n){
    for(ll i=1; i<=n; i++){
        p[i] = p[i-1] * i;
    }
}

double calce(ll n){
    ld r = 1;
    for(ll i = 1; i <= n; i++){
        r += 1.0 / p[i];
    }
    return r;
}

int main(){
    ll n;
    cin >> n;
    p[0] = 1;
    fun(n);
    printf("%.50lf", calce(n));

    return 0;
}