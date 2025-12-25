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

ll gcd(ll a,ll b){
  return (b==0?a:gcd(b,a%b));
}

ll lcm(ll a,ll b){
  return (a*b/gcd(a,b));
}

void solve(){
	ll a,b,c;
  cin>>a>>b>>c;
  // cout<<gcd(a,b)<<'\n';
  // cout<<gcd(a,c)<<'\n';
  // cout<<gcd(b,c)<<'\n';
  cout<<lcm(a,lcm(b,c));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}