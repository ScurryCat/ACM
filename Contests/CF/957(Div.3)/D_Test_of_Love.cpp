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
	string s;
	s.resize(n+2);
	for(int i=1;i<=n;i++) cin>>s[i];
	bool ok=true;
	ll pos=0,cnt=0;
	while(pos<=n){
		for(int i=1;i<=m;i++){
			pos++;
			if(pos>n){
				cout<<"YES\n";
				return;
			}
			if(s[pos]=='L') i=0;
		}
		while(s[pos]=='W'){
			pos++;
			cnt++;
		}
		if(s[pos]=='C'||cnt>k){
			ok=false;
			break;
		}
	}
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin>>yyy;
	while(yyy--) solve();
	return 0;
}