#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;

ll n,m,ans;

void solve(){
	ll a,b,k;
	cin>>a>>b;
	ans=-1;
	for (ll i = 1; i * i <= b; i++) {
		if (b % i == 0) {
			ll k1 = i;
			ll s1 = a * k1 + b / k1;
			if (s1 % 2 == 0) {
					ans = max(ans, s1);
			}
			ll k2 = b / i;
			ll s2 = a * k2 + b / k2;
			if (s2 % 2 == 0) {
					ans = max(ans, s2);
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
// a*k+b/k
// a*k*k+b
// k*k+b/a
// 