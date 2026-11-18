#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    ll cnt = 0;
    for(int i=0; i<n; i++){
        cnt += a[i];
        if(cnt >= k){
            cout << i+1;
            return;
        }
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}