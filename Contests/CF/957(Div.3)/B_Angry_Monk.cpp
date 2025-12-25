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
	ll n,k;
	cin>>n>>k;
	VI a(k);
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll ans=0;
	for(int i=0;i<k-1;i++) ans+=a[i]+a[i]-1;
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin>>yyy;
	while(yyy--) solve();
	return 0;
}