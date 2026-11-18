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
        auto q = p.end();
        cout << (*q).first << ' ' << (*q).second;
        while(s < (*p.end()).first && k) s <<= 1, k--;
        if(s >= (*p.end()).first) s += (*p.end()).second, p.pop_back();
        else break;
    }
    
    cout << s << '\n';
}

int main( )
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}