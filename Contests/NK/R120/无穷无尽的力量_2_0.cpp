#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n, m;
	cin >> n >> m;
	if(n>m) swap(n, m);
	if(n == 1) cout << 1;
	else if(n == 2) cout << (m+1) / 2;
	else if(n == 3 && m == 3) cout << 8;
	else cout << 1ll * n * m; 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}