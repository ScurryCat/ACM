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

ll a,p;
int b[N];

// 20000000
void solve(){
  string B;
  cin>>a>>p>>B;
  int lb=B.size();
  for(int i=0;i<lb;i++) b[lb-i-1] = B[i];
  ll ans=1;
  while(){
    if() ans = (ans * a) % p;
    a = (a*a)%p;
    div(b);
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}