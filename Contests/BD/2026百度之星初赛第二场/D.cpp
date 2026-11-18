#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 2e5+9, M = 2e5+9, mod = 998244353; int t_ = 1;
using ll = long long; using ld = long double; using i128 = __int128;

struct cc{
	int c, w;
}a[N];

int n, k;
int ls[N];
ll b[N], idx;
int rr = 0;
ll sum = 0;

bool check(int x){
	int r = 1;
	ll cur = 0;
	for(int i = 1; i<=idx; i++){
		if(b[i] > x){
			return 0;
		}
		if(cur + b[i] > x){
			++r;
			cur = b[i];
		}
		else{
			cur += b[i];
		}
	}
	return r <= k;
}

inline void qwq_(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i].c >> a[i].w;
		ls[a[i].c] = i;
	}

	for(int i=1; i<=n; i++){
		rr = max(rr, ls[a[i].c]);
		sum += a[i].w;
		if(i == rr){
			b[++idx] = sum;
			sum = 0;
		}
	}

	if(idx < k){
		cout << -1 << '\n';
		return;
	}

	int l = -2, r = 1e9, mid;
	while(l + 1 < r){
		mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << r << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}