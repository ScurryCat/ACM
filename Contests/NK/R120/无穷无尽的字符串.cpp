#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int l, r;
	cin >> l >> r;
	int k1 = (l - 1) % 3;
	int k2 = r % 3;
	int cnt1 = (l - 1) / 3;
	int cnt2 = r / 3;
	int ans = cnt2 - cnt1;
	cout << ans + (k2>=1) - (k1>=1) << ' '<< ans + (k2>=2) - (k1>=2) << ' ' << ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}