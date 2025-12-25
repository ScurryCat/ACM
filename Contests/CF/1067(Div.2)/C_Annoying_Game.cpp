#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n, k;
	cin >> n >> k;
	k %= 2;
	vector<ll> a(n+1), b(n+1), f(n+2), g(n+2);
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];
	for(int i=1; i<=n; i++) f[i] = max(a[i], f[i-1] + a[i]);
	for(int i=n; i>=1; i--) g[i] = max(a[i], g[i+1] + a[i]);
	ll ans = -1e9;
	for(int i=1; i<=n; i++){
		ll x = a[i] + k * b[i] + max(0ll, f[i-1]) + max(0ll, g[i+1]);
		ans = max(ans, x);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}