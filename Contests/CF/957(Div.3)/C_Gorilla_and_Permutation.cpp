#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int r = 0, w = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar();}
	while('0' <= ch && ch <= '9') {r = (r << 1) + (r << 3) + ch - 48; ch = getchar();}
	return r * w;
}

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9;
const int mod = 998244353;

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll x=n;
	for(int i=1;i<n-m+1;i++){
		cout<<x--<<' ';
	}
	for(int i=m;i>=1;i--){
		cout<<m-i+1<<' ';
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin>>yyy;
	while(yyy--) solve();
	return 0;
}