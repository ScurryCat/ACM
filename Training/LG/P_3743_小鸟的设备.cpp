#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

inline int read(){
	int r = 0, w = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar();}
	while('0' <= ch && ch <= '9') {r = (r << 1) + (r << 3) + ch - 48; ch = getchar();}
	return r * w;
}

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int N = 1e5+9;
const int mod = 998244353;

double n,p;
PDD a[N];

bool check(double x){
  double cnt=0;
  for(int i=1;i<=n;i++){
    if(a[i].se/a[i].fi<x){
      cnt+=(x-a[i].se/a[i].fi)*a[i].fi;
      if(cnt>p*x) return false;
    }
  }
  return true;
}

void solve(){
  double mx=0,cnt=0,sa=0,sb=0;
	cin>>n>>p;
  cout<<fixed<<setprecision(10);
  for(int i=1;i<=n;i++){
    cin>>a[i].fi>>a[i].se;
    cnt+=a[i].fi;
    sa+=a[i].fi;
    sb+=a[i].se;
  }
  if(cnt<=p){
    cout<<-1;
    return;
  }
  double l=0,r=sb/(sa-p),mid;
  while(r-l>1e-11){  
    mid=(l+r)/2;
    if(mid==l||mid==r) break;     // 这种二分方法必须加上这条语句，否则会TLE
    if(check(mid)) l=mid;
    else r=mid;
  }
  // for(int i=0;i<100;i++){
  //   mid=(l+r)/2;
  //   if(check(mid)) l=mid;
  //   else r=mid;
  // }
  cout<<l;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}