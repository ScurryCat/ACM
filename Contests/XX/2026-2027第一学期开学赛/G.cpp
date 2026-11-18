#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> d(n+1);
    for(int i=0; i<m; i++){
        int l, r, v;
        cin >> l >> r >> v;
        d[l] += v;
        d[r+1] -= v;
    }
    for(int i=1; i<=n; i++){
        d[i] += d[i-1];
    }

    long long mx = 0, id = 0, cnt = 0;
    for(int i=1; i<=n; i++){
        if(mx < d[i]){
            mx = d[i];
            id = i;
            cnt = 1;
        }
        else if(mx == d[i]) cnt++;
    }
    cout << mx << ' ' << cnt << ' ' << id;
}

int main(){

    solve();

    return 0;
}