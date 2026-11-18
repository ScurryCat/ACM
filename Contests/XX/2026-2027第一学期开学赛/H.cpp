#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int ans = 0;

    for(int i=0, j=0; i<n; i++){
        if(b[i] < a[j]){
            j++, ans++;
        }
    }

    cout << ans << '\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--){
        solve();
    }

    return 0;
}