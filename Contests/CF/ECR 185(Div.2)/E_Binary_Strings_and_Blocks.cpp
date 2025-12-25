#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n, m;
	cin>>n>>m;
	vector<int> x(n+1);
	for(int i=1;i<=m;i++){
		int l, r;
		cin>>l>>r;
		r--;
		if(l<=r) x[r] = max(x[r],l);
	}
	
	vector<int> p(n+1), s(n+1), f(n+1);
	for(int i=1;i<=n;i++){
		p[i] = max(p[i-1],x[i-1]);
	}

	f[0]=1;
	s[0]=1;
	for(int i=1;i<=n;i++){
		if(p[i]<=i){
			int v = (p[i]<1) ? 0 : s[p[i]-1];
			f[i] = (s[i-1]-v+mod) % mod;
		}
		else{
			f[i] = 0;
		}
		s[i] = (s[i-1]+f[i]) % mod;
	}

	cout<<((ll)(f[n]<<1)+mod) % mod<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}