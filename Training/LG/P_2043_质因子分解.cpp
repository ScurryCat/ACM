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

int n,m;
int a[N];

void decompose(int x){
  for(int i=2;i*i<=x;i++)
    while(x%i==0) a[i]++,x/=i;
  if(x>1) a[x]++;
}

void solve(){
	cin>>n;
  for(int i=2;i<=n;i++) decompose(i);
  for(int i=2;i<=n;i++) if(a[i]) cout<<i<<' '<<a[i]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}