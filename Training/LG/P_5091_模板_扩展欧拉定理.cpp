#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 2e7+9;
const int M = 2e5+9;
const int mod = 998244353;

int a,m;
string b;

inline int phi(int x){
  int r = x;
  for(int i=2;i*i<=x;i++){
    if(x%i==0){
      r = r / i * (i-1);
      while(x%i==0) x /= i;
    }
  }
  if(x>1) r = r / x * (x-1);
  return r;
}

inline int qpow(ll a,int b,int c){
  ll r = 1;
  while(b){
    if(b&1) r = r * a % c;
    a = a * a % c;
    b >>= 1;
  }
  return r;
}

inline int depow(string &s, int m){
  ll r = 0, flag = 0;
  for(int i=0;i<s.size();i++){
    r = r * 10 + s[i] - '0';
    if(r>=m) flag = 1, r %= m;
  }
  if(flag) r += m;
  return r;
}

void solve(){
  cin >> a >> m >> b;
  int pm = phi(m);
  int x = depow(b,pm);
  cout << qpow(a,x,m);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}