#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, M = 2e5+9, mod = 998244353; int t_ = 1;
using ll = long long; using ld = long double; using i128 = __int128;

inline void qwq_(){
	int n; cin >> n;
    vector<int> a(n+1), pre(n+1), sub(n+2);
    vector<ll> s(n+1);
    pre[0] = -1e9;
    sub[n+1] = -1e9;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        pre[i] = max(pre[i-1], a[i]);
    }
    for(int i=n; i>=1; i--){
        sub[i] = max(sub[i+1], a[i]);
    }
    ll ans = s[5];  
    for(int i=4; i<=n; i++){
        ll cur = s[i] - s[i-4];
        int mx = max(pre[i-4], sub[i+1]);
        ans = max(ans, cur + mx);
    }
    for(int i=6; i<=n; i++){
        int mn = a[i-5];
        for(int j=i-4; j<=i; j++){
            mn = min(mn, a[j]);
        }
        ans = max(ans, s[i] - s[i-6] - mn);
    }
    cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}