#include<bits/stdc++.h> 

using namespace std;

using ll = long long;

bool cmp(pair<ll, int> x, pair<ll, int> y){
    return x.first > y.first;
}

void solve(){
    ll n, k, s;
    cin >> n >> k >> s;
    vector<pair<ll, int>> p(n);
    for(auto &o : p){
        cin >> o.first >> o.second;
    }
    
    sort(p.begin(), p.end(), cmp);

    while(p.size()){
        while(s < p.back().first && k > 0) s <<= 1, k--;
        if(s >= p.back().first) s += p.back().second, p.pop_back();
        else break;
    }
    while(k) s <<= 1, k--;
    cout << s << '\n';
}

int main( )
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}