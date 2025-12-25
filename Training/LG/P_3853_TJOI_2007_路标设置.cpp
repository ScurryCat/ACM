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

ll s,n,k;
ll a[N],d[N];

bool check(ll x){
  for(ll i=1,j=0;i<=n;i++){
    if(d[i]>x){
      // ll y=d[i]-1;       // 错误代码
      // ll c=2;
      // while((y/c)>x) c++;
      // j+=c-1;
      j+=(d[i]-1)/x;
      if(j>k) return false;
    }
  }
  return true;
}

void solve(){
  cin>>s>>n>>k;
  VI a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    d[i]=a[i]-a[i-1];
    // cout<<d[i]<<' ';
  }
  // cout<<'\n';
  ll l=0,r=s+1,mid;
  while(l+1<r){
    mid=l+r>>1;
    if(check(mid)) r=mid;
    else l=mid;
  }
  cout<<r;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}