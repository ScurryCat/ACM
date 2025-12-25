#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;

int n,m,ans;
ll k,x;

void solve(){
	cin>>k>>x;
  while(k--){
		// if((x+x)&1==0) x+=x;
		// else x=(x-1)/3;
    if(x&1&&(x-1)%3==0&&x!=1&&(x+x)&1==0) x=(x-1)/3;
    else x*=2;
  }
  cout<<x<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}