#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,p;

inline int qpow(int a, int b){
  ll r = 1;
  while(b){
    if(b&1) r = r * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return r;
}

inline void solve(){
  cin >> n >> p;
  for(int i=1;i<=n;i++){
    cout << qpow(i, p-2) << '\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}