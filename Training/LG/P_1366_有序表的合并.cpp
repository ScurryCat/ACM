#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n, m;

int lb(const vector<ull> &b,ull x){
  int l=-1,r=m,mid;
  while(l+1<r) {
    mid = l+r >>1;
    if(b[mid] >= x) r=mid;
    else l=mid;
  }
  return r;
}

int rb(const vector<ull> &b,ull x){
  int l=-1,r=m,mid;
  while(l+1<r) {
    mid = (l+r) >>1;
    if(b[mid] <= x) l=mid;
    else r=mid;
  }
  return l;
}

void qaq_() {
  cin >> n >> m;
  vector<ull> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  ull ans = 0;
  int i=0,j=0;
  for (auto x : a){
    i=lb(b,x);
    j=rb(b,x);
    ull cnt=j-i+1;
    // cout<<x<<' '<<i<<' '<<j<<' '<<cnt<<'\n';
    ans ^= cnt;
  }
  cout << ans << '\n';
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qaq_();
	return 0;
}